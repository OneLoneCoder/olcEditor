#include "cLayer_Boolean.h"



cLayer_Boolean::cLayer_Boolean(const std::string& name) : cTiledLayer(name, LayerType::Boolean)
{
}

cLayer_Boolean::~cLayer_Boolean()
{
}

void cLayer_Boolean::SetColourTrue(const olc::Pixel& col)
{
	m_colTrue = col;
}

olc::Pixel cLayer_Boolean::GetColourTrue() const
{
	return m_colTrue;
}

void cLayer_Boolean::SetColourFalse(const olc::Pixel& col)
{
	m_colFalse = col;
}

olc::Pixel cLayer_Boolean::GetColourFalse() const
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
				olc::Pixel p = GetColourFalse();
				p.a = uint8_t(GetFillOpacity() * float(p.a));
				gfx.FillRect(GetUnitSize() * olc::vf2d(float(x), float(y)), GetUnitSize(), p);
			}
			else
			{
				olc::Pixel p = GetColourTrue();
				p.a = uint8_t(GetFillOpacity() * float(p.a));
				gfx.FillRect(GetUnitSize() * olc::vf2d(float(x), float(y)), GetUnitSize(), p);
			}
		}
	}
}

void cLayer_Boolean::RenderBrush(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR)
{
	olc::vi2d vCellTL = { std::max(int(vWorldTL.x), 0), std::max(int(vWorldTL.y), 0) };
	olc::vi2d vCellBR = { std::min(int(vWorldBR.x), GetLayerSize().x), std::min(int(vWorldBR.y), GetLayerSize().y) };

	for (auto& cell : setBrush)
	{
		if (cell.content == 0)
		{
			olc::Pixel p = GetColourFalse();
			p.a = uint8_t(GetFillOpacity() * float(p.a) * 0.5f);
			gfx.FillRect(GetUnitSize() * olc::vf2d(cell.pos), GetUnitSize(), p);
		}
		else
		{
			olc::Pixel p = GetColourTrue();
			p.a = uint8_t(GetFillOpacity() * float(p.a) * 0.5f);
			gfx.FillRect(GetUnitSize() * olc::vf2d(cell.pos), GetUnitSize(), p);
		}
	}
}