#include "cLayer_Boolean.h"



cLayer_Boolean::cLayer_Boolean(const std::string& name) : cLayer(name, LayerType::Boolean)
{
}

cLayer_Boolean::~cLayer_Boolean()
{
}

void cLayer_Boolean::SetLayerSize(const olc::vi2d& size)
{
	// Create temporary of new vector
	std::vector<int> newmap;
	newmap.resize(size.x * size.y);
	std::fill(newmap.begin(), newmap.end(), 0);

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

olc::vi2d cLayer_Boolean::GetLayerSize() const
{
	return m_vLayerSize;
}

void cLayer_Boolean::SetTileSize(const olc::vi2d& size)
{
	m_vTileSize = size;
}

olc::vi2d cLayer_Boolean::GetTileSize() const
{
	return m_vTileSize;
}

int& cLayer_Boolean::GetTile(const olc::vi2d& pos)
{
	return GetTile(pos.x, pos.y);
}

int& cLayer_Boolean::GetTile(const int x, const int y)
{
	if (x >= 0 && x < m_vLayerSize.x && y >= 0 && y < m_vLayerSize.y)
	{
		return m_tiles[y * m_vLayerSize.x + x];
	}
	else
		return NullBool;
}

void cLayer_Boolean::SetColourTrue(const olc::colour& col)
{
	m_colTrue = col;
}

olc::colour cLayer_Boolean::GetColourTrue() const
{
	return m_colTrue;
}

void cLayer_Boolean::SetColourFalse(const olc::colour& col)
{
	m_colFalse = col;
}

olc::colour cLayer_Boolean::GetColourFalse() const
{
	return m_colFalse;
}

void cLayer_Boolean::RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR)
{
	olc::vi2d vCellTL = { std::max(int(vWorldTL.x), 0), std::max(int(vWorldTL.y), 0) };
	olc::vi2d vCellBR = { std::min(int(vWorldBR.x), GetLayerSize().x), std::min(int(vWorldBR.y), GetLayerSize().y) };

	for (int y = vCellTL.y; y < vCellBR.y; y++)
	{
		for (int x = vCellTL.x; x < vCellBR.x; x++)
		{
			if (GetTile(x, y) == 0)
			{
				gfx.FillRect({ float(x), float(y) }, { 1.0f, 1.0f }, GetColourFalse());
			}
			else
			{
				gfx.FillRect({ float(x), float(y) }, { 1.0f, 1.0f }, GetColourTrue());
			}
		}
	}
}