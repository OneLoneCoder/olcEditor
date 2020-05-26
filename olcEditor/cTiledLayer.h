#pragma once
#include "cLayer.h"
#include "cGridSelection.h"

// Brush elements are the set of what is to be "painted" into the tile layer
template <typename T>
struct sBrushElement
{
	T content;
	olc::vi2d pos;
};

// std::unordered_set requires overload for equality, in this case only
// the position needs to be equal, not the contents
template <typename T>
bool operator==(const sBrushElement<T>& a, const sBrushElement<T>& b)
{ return a.pos == b.pos; }

// A content container translates resources into tangiable cell contents
// Each layer type will need a content container derived form this template
template <typename T>
class cContentContainer
{
public:
	cContentContainer()
	{}

	virtual ~cContentContainer()
	{}

	virtual const T Get(const olc::vi2d& vPos) const = 0;
};

// A brush element is a transient world-space object that represents
// a single tile ready to be painted into tile map. The nature of the
// brush element is unique to the layer type
template<typename B>
struct std::hash<sBrushElement<B>>
{
	size_t operator()(const sBrushElement<B>& obj) const
	{
		return hash<uint64_t>()(uint64_t(obj.pos.y) << 32 | uint64_t(obj.pos.x));
	}
};

// Tile layer templated adaptor class. Provides common infrastructure
// for all layers that are fundamentally tiles. The "tile" is described
// by the content container.
template <typename T, typename B>
class cTiledLayer : public cLayer
{
public:
	cTiledLayer(const std::string& name, LayerType t) : cLayer(name, t, ContentType::Tiles)
	{}

	~cTiledLayer()
	{}

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
	void ClearBrush()
	{
		setBrush.clear();
	}

	// Transfers brush into layer
	void ApplyBrush()
	{
		for (auto& element : setBrush)
			GetTile(element.pos) = element.content;		
	}

	// 
	void CreateBrush_Point(const olc::vi2d& vTile, std::shared_ptr<cGridSelection> gs, const cContentContainer<T>& content)
	{
		ClearBrush();

		if (gs)
		{
			for (const auto& cell : gs->setSelected)
			{
				olc::vi2d vOffsetFromRoot = cell - gs->vRoot;
				olc::vi2d vWorldCell = vTile + vOffsetFromRoot;
				setBrush.insert({ content.Get(cell), vWorldCell });
			}
		}
		else
		{
			setBrush.insert({ content.Get(vTile), vTile });
		}
	}

	void CreateBrush_Line(const olc::vi2d& vStart, const olc::vi2d& vEnd, std::shared_ptr<cGridSelection> gs, const cContentContainer<T>& content)
	{
		ClearBrush();

		auto Plot = [&](const olc::vi2d& vTile)
		{
			if (gs)
			{
				for (const auto& cell : gs->setSelected)
				{
					olc::vi2d vOffsetFromRoot = cell - gs->vRoot;
					olc::vi2d vWorldCell = vTile + vOffsetFromRoot;
					setBrush.insert({ content.Get(cell), vWorldCell });
				}
			}
			else
			{
				setBrush.insert({ content.Get(vTile), vTile });
			}
		};

		olc::vi2d vTileStart = vStart;
		olc::vi2d vTileEnd = vEnd;

		int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
		dx = vTileEnd.x - vTileStart.x; dy = vTileEnd.y - vTileStart.y;


		if (dx == 0) // Line is vertical
		{
			if (vTileEnd.y < vTileStart.y) std::swap(vTileStart.y, vTileEnd.y);
			for (y = vTileStart.y; y <= vTileEnd.y; y++) Plot({ vTileStart.x, y });
			return;
		}

		if (dy == 0) // Line is horizontal
		{
			if (vTileEnd.x < vTileStart.x) std::swap(vTileStart.x, vTileEnd.x);
			for (x = vTileStart.x; x <= vTileEnd.x; x++) Plot({ x, vTileStart.y });
			return;
		}

		// Line is Funk-aye
		dx1 = abs(dx); dy1 = abs(dy);
		px = 2 * dy1 - dx1;	py = 2 * dx1 - dy1;
		if (dy1 <= dx1)
		{
			if (dx >= 0)
			{
				x = vTileStart.x; y = vTileStart.y; xe = vTileEnd.x;
			}
			else
			{
				x = vTileEnd.x; y = vTileEnd.y; xe = vTileStart.x;
			}

			Plot({ x, y });

			for (i = 0; x < xe; i++)
			{
				x = x + 1;
				if (px < 0)
					px = px + 2 * dy1;
				else
				{
					if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) y = y + 1; else y = y - 1;
					px = px + 2 * (dy1 - dx1);
				}
				Plot({ x, y });
			}
		}
		else
		{
			if (dy >= 0)
			{
				x = vTileStart.x; y = vTileStart.y; ye = vTileEnd.y;
			}
			else
			{
				x = vTileEnd.x; y = vTileEnd.y; ye = vTileStart.y;
			}

			Plot({ x, y });

			for (i = 0; y < ye; i++)
			{
				y = y + 1;
				if (py <= 0)
					py = py + 2 * dx1;
				else
				{
					if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) x = x + 1; else x = x - 1;
					py = py + 2 * (dx1 - dy1);
				}
				Plot({ x, y });
			}
		}
	}

	void CreateBrush_Rectangle(const olc::vi2d& vStart, const olc::vi2d& vEnd, std::shared_ptr<cGridSelection> gs, const cContentContainer<T>& content)
	{
		ClearBrush();

		auto Plot = [&](const olc::vi2d& vTile)
		{
			if (gs)
			{
				for (const auto& cell : gs->setSelected)
				{
					olc::vi2d vOffsetFromRoot = cell - gs->vRoot;
					olc::vi2d vWorldCell = vTile + vOffsetFromRoot;
					setBrush.insert({ content.Get(cell), vWorldCell });
				}
			}
			else
			{
				setBrush.insert({ content.Get(vTile), vTile });
			}
		};

		olc::vi2d vTileStart = vStart;
		olc::vi2d vTileEnd = vEnd;

		if (vTileStart.x > vTileEnd.x) std::swap(vTileStart.x, vTileEnd.x);
		if (vTileStart.y > vTileEnd.y) std::swap(vTileStart.y, vTileEnd.y);

		for (int x = vTileStart.x; x <= vTileEnd.x; x++)
		{
			Plot({ x, vTileStart.y });
			Plot({ x, vTileEnd.y });
		}

		for (int y = vTileStart.y; y <= vTileEnd.y; y++)
		{
			Plot({ vTileStart.x, y });
			Plot({ vTileEnd.x, y });
		}
	}


	void CreateBrush_FillRectangle(const olc::vi2d& vStart, const olc::vi2d& vEnd, std::shared_ptr<cGridSelection> gs, const cContentContainer<T>& content)
	{
		ClearBrush();

		auto Plot = [&](const olc::vi2d& vTile)
		{
			if (gs)
			{
				for (const auto& cell : gs->setSelected)
				{
					olc::vi2d vOffsetFromRoot = cell - gs->vRoot;
					olc::vi2d vWorldCell = vTile + vOffsetFromRoot;
					setBrush.insert({ content.Get(cell), vWorldCell });
				}
			}
			else
			{
				setBrush.insert({ content.Get(vTile), vTile });
			}
		};

		olc::vi2d vTileStart = vStart;
		olc::vi2d vTileEnd = vEnd;

		if (vTileStart.x > vTileEnd.x) std::swap(vTileStart.x, vTileEnd.x);
		if (vTileStart.y > vTileEnd.y) std::swap(vTileStart.y, vTileEnd.y);

		for (int x = vTileStart.x; x <= vTileEnd.x; x++)
		{
			for (int y = vTileStart.y; y <= vTileEnd.y; y++)
			{
				Plot({ x, y });
			}
		}
	}


protected:
	std::vector<T> m_tiles;
	T NullItem = { 0 };	
	std::unordered_set<B> setBrush;
};

