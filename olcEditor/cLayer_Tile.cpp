#include "cLayer_Tile.h"

cLayer_Tile::cLayer_Tile(const std::string& name, std::vector<std::shared_ptr<cImageResource>>& vImageResources) : cTiledLayerAdaptor(name, LayerType::Tile), m_vImageResources(vImageResources)
{
}

cLayer_Tile::~cLayer_Tile()
{
}

void cLayer_Tile::RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR)
{
	olc::vi2d vCellTL = { std::max(int(vWorldTL.x), 0), std::max(int(vWorldTL.y), 0) };
	olc::vi2d vCellBR = { std::min(int(vWorldBR.x), GetLayerSize().x), std::min(int(vWorldBR.y), GetLayerSize().y) };

	for (int y = vCellTL.y; y < vCellBR.y; y++)
	{
		for (int x = vCellTL.x; x < vCellBR.x; x++)
		{
			if (GetTile(x, y).exist && !m_vImageResources.empty())
			{
				olc::Pixel tint = olc::Pixel(255, 255, 255, uint8_t(GetFillOpacity() * 255.0f));
				gfx.DrawSubImage(m_vImageResources[GetTile(x, y).nResourceID]->GetHardwareID(), GetUnitSize() * olc::vf2d(float(x), float(y)), GetUnitSize(), GetTile(x, y).vPosition, GetTile(x, y).vSize, tint);
			}
		}
	}
}

void cLayer_Tile::RenderCursor(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR, std::shared_ptr<cImageResource> image, std::shared_ptr<cGridSelection> selection, const olc::vi2d& cursor)
{
	for (const auto& cell : selection->setSelected)
	{
		olc::vi2d vTilePos = cursor;
		olc::vi2d vOffsetFromRoot = cell - selection->vRoot;
		olc::vi2d vWorldCell = vTilePos + vOffsetFromRoot;
		gfx.DrawSubImage(image->GetHardwareID(), vWorldCell * GetUnitSize(), GetUnitSize(), image->GetTileDesc(cell).vPosition, image->GetTileDesc(cell).vSize, { 255, 255, 255, 128 });
	}
}

