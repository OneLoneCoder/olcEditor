#pragma once
#include "cLayer.h"

class cTiledLayer : public cLayer
{
public:
	cTiledLayer(const std::string& name, LayerType t);
	virtual ~cTiledLayer();

	olc::vi2d GetLayerSize() const;
	void SetTileSize(const olc::vi2d& size);
	olc::vi2d GetTileSize() const;
	olc::vi2d TileCoord(const olc::vf2d& vWorld) const;
	

protected:
	olc::vf2d m_vTileSize = { 16.0f, 16.0f };
	olc::vi2d m_vLayerSize = { 0, 0 };
};

template <typename T>
class cTiledLayerAdaptor : public cTiledLayer
{
public:
	cTiledLayerAdaptor(const std::string& name, LayerType t) : cTiledLayer(name, t)
	{

	}

	~cTiledLayerAdaptor()
	{
	}

	void SetLayerSize(const olc::vi2d& size)
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

protected:
	std::vector<T> m_tiles;
	T NullItem = { 0 };
};