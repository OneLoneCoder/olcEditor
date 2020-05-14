#include "cTiledLayer.h"

cTiledLayer::cTiledLayer(const std::string& name, LayerType t) : cLayer(name, t, ContentType::Tiles)
{

}

cTiledLayer::~cTiledLayer()
{
}

olc::vi2d cTiledLayer::GetLayerSize() const
{
	return m_vLayerSize;
}

void cTiledLayer::SetTileSize(const olc::vi2d& size)
{
	m_vTileSize = size;
}

olc::vi2d cTiledLayer::GetTileSize() const
{
	return m_vTileSize;
}


olc::vi2d cTiledLayer::TileCoord(const olc::vf2d& vWorld) const
{
	return { int(vWorld.x), int(vWorld.y) };
}