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


olc::vi2d cTiledLayer::TileCoord(const olc::vf2d& vWorld) const
{
	return { int(vWorld.x / float(GetUnitSize().x)), int(vWorld.y / float(GetUnitSize().y)) };
}