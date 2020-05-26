#pragma once
#include "cLayer.h"
#include "cGridSelection.h"

class cTiledLayer : public cLayer
{
public:
	cTiledLayer(const std::string& name, LayerType t);
	virtual ~cTiledLayer();

public:
	//void CreateBrush_Line(const olc::vi2d& vStart, const olc::vi2d& vEnd, const cGridSelection& source, const uint32_t flags)
	virtual void ClearBrush() {};
	virtual void ApplyBrush() {};


};


// Brush elements are the set of what is to be "painted" into the tile layer
template <typename T>
struct sBrushElement
{
	T content;
	olc::vi2d pos;
};

template <typename T>
class cContentContainer
{
public:
	cContentContainer()
	{

	}

	virtual ~cContentContainer()
	{

	}

	virtual const T& Get(const olc::vi2d& vPos) const
	{

	}
};

class cContentContainerBoolean : public cContentContainer<uint8_t>
{
public:
	cContentContainerBoolean(bool b)
	{
		m_nContent = b ? 1 : 0;
	}

	const uint8_t& Get(const olc::vi2d& vPos) const override
	{
		return m_nContent;
	}

private:
	uint8_t m_nContent = 0;
};


template <typename T, typename B>
class cTiledLayerAdaptor : public cTiledLayer
{
private:
	

public:
	cTiledLayerAdaptor(const std::string& name, LayerType t) : cTiledLayer(name, t)
	{

	}

	~cTiledLayerAdaptor()
	{
	}

	void SetLayerSize(const olc::vi2d& size) override
	{
		// Create temporary of new vector
		std::vector<T> newmap;
		newmap.resize(size.x * size.y);
		std::fill(newmap.begin(), newmap.end(), NullItem);

		// Copy existing map into new vector
		olc::vi2d copysize = { std::min(size.x, m_vLayerSize.x), std::min(size.y, m_vLayerSize.y) };
		for (int y = 0; y < copysize.y; y++)
			for (int x = 0; x < copysize.x; x++)
				newmap[y * size.x + x] = m_tiles[y * m_vLayerSize.x + x];

		// Transfer new data
		m_tiles.clear();
		m_tiles = newmap;
		m_vLayerSize = size;
	}

	T& GetTile(const olc::vi2d& pos)
	{
		return GetTile(pos.x, pos.y);
	}

	T& GetTile(const int x, const int y)
	{
		if (x >= 0 && x < m_vLayerSize.x && y >= 0 && y < m_vLayerSize.y)
		{
			return m_tiles[y * m_vLayerSize.x + x];
		}
		else
			return NullItem;
	}

	// Clears the current brush
	void ClearBrush() override
	{
		setBrush.clear();
	}

	// Transfers brush into layer
	void ApplyBrush() override
	{
		for (auto& element : setBrush)
			GetTile(element.pos) = element.content;		
	}

	// 
	void CreateBrush_Point(const olc::vi2d& vTile, const cGridSelection& gs, const cContentContainer<T>& content)
	{
		ClearBrush();

		for (const auto& cell : gs->setSelected)
		{
			olc::vi2d vOffsetFromRoot = cell - gs->vRoot;
			olc::vi2d vWorldCell = vTile + vOffsetFromRoot;
			setBrush.insert({ content.Get(cell), vWorldCell });
		}
	}

protected:
	std::vector<T> m_tiles;
	T NullItem = { 0 };	
	std::unordered_set<B> setBrush;
};

template<typename B>
struct std::hash<sBrushElement<B>>
{
	size_t operator()(const sBrushElement<B>& obj) const
	{
		return hash<uint64_t>()(uint64_t(obj.pos.y) << 32 | uint64_t(obj.pos.x));
	}
};