#include "cLayer_Boolean.h"



cLayer_Boolean::cLayer_Boolean(const std::string& name) : cTiledLayerAdaptor(name, LayerType::Boolean)
{
}

cLayer_Boolean::~cLayer_Boolean()
{
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