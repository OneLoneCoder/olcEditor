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
			if (!m_vImageResources.empty())
			{
				gfx.DrawSubImage(m_vImageResources[GetTile(x, y).nResourceID]->GetHardwareID(), { float(x), float(y) }, { 1.0f, 1.0f }, GetTile(x, y).vPosition, GetTile(x, y).vSize);
			}
		}
	}

	glBindTexture(GL_TEXTURE_2D, 0);
}
