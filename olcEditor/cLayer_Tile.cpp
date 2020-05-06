#include "cLayer_Tile.h"

cLayer_Tile::cLayer_Tile(const std::string& name) : cTiledLayerAdaptor(name, LayerType::Tile)
{
}

cLayer_Tile::~cLayer_Tile()
{
}

void cLayer_Tile::RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR)
{
}
