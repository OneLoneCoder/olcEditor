#include "cLayer_Boolean.h"



cLayer_Boolean::cLayer_Boolean(const std::string& name) : cTiledLayerAdaptor(name, LayerType::Boolean)
{
}

cLayer_Boolean::~cLayer_Boolean()
{
}

const std::string cLayer_Boolean::GetLayerTypeName() const
{
	return "Boolean";
}

const std::vector<sToolBarButton> cLayer_Boolean::GetToolBarButtons() const
{
	return std::vector<sToolBarButton>
	({
		{"Clear Selection", "./gfx/ico_select_clear.png", "Disables current selection areas"},
		{"Region Select", "./gfx/ico_select.png", "Select area, hold CTRL to add areas"},
		{"Move Selection", "./gfx/ico_select_move.png", "Move selected area"},
		{"Fill Selection", "./gfx/ico_select_fill.png", "Flood fill select area"},
		{"Draw", "./gfx/ico_draw_one.png", "Draw single tile"},
		{"Draw Line", "./gfx/ico_draw_line.png", "Draw a line"},
		{"Draw Rectangle", "./gfx/ico_draw_rect.png", "Draw a rectangle outline"},
		{"Fill Rectangle", "./gfx/ico_fill_rect.png", "Draw a filled rectangle"},
		{"Draw Circle", "./gfx/ico_draw_circle.png", "Draw a circular outline"},
		{"Fill Circle", "./gfx/ico_fill_circle.png", "Draw a filled circle"},
		{"Flood Fill", "./gfx/ico_draw_fill.png", "Flood fill draw"},
	});
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