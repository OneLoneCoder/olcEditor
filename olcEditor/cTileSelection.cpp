#include "cTileSelection.h"

cTileSelection::cTileSelection()
{
}

void cTileSelection::All(std::shared_ptr<cTiledLayer> layer)
{
	setSelected.clear();
	setNotSelected.clear();

	for (int y = 0; y < layer->GetLayerSize().y; y++)
	{
		for (int x = 0; x < layer->GetLayerSize().x; x++)
		{
			setSelected.insert({ x, y });
		}
	}
}

void cTileSelection::None(std::shared_ptr<cTiledLayer> layer)
{
	setSelected.clear();
	setNotSelected.clear();

	for (int y = 0; y < layer->GetLayerSize().y; y++)
	{
		for (int x = 0; x < layer->GetLayerSize().x; x++)
		{
			setNotSelected.insert({ x, y });
		}
	}
}

void cTileSelection::Invert(std::shared_ptr<cTiledLayer> layer)
{
	std::swap(setSelected, setNotSelected);
}

void cTileSelection::Select(std::shared_ptr<cTiledLayer> layer, const olc::vi2d& pos)
{
	setNotSelected.erase(pos);
	setSelected.insert(pos);
}

void cTileSelection::Deselect(std::shared_ptr<cTiledLayer> layer, const olc::vi2d& pos)
{
	setSelected.erase(pos);
	setNotSelected.insert(pos);
}

void cTileSelection::Region(std::shared_ptr<cTiledLayer> layer, const olc::vi2d& tl, const olc::vi2d& br)
{
	olc::vi2d s = { std::min(tl.x, br.x), std::min(tl.y, br.y) };
	olc::vi2d e = { std::max(tl.x, br.x), std::max(tl.y, br.y) };
		
	for (int y = s.y; y <= e.y; y++)
	{
		for (int x = s.x; x <= e.x; x++)
		{
			Select(layer, { x, y });
		}
	}
}

void cTileSelection::RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR)
{
	for (auto& tile : setNotSelected)
	{
		olc::vf2d fTile = { float(tile.x), float(tile.y) };
		if (fTile.x >= vWorldTL.x && fTile.x < vWorldBR.x && fTile.y >= vWorldTL.y && fTile.y < vWorldBR.y)
		{
			gfx.FillRect(fTile, { 1.0f, 1.0f }, olc::PixelF(0,0,0,0.5f));
		}
	}
}

bool cTileSelection::InSelection(std::shared_ptr<cTiledLayer> layer, const olc::vi2d& pos)
{
	return setSelected.count(pos) > 0;
}
