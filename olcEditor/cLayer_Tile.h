#pragma once
#include "cTiledLayer.h"

struct sTileDescription
{
	uint32_t nResourceID = 0;
	olc::vf2d vSource = { 0,0 };
};

class cLayer_Tile : public cTiledLayerAdaptor<sTileDescription>
{
public:
	cLayer_Tile(const std::string& name = "Nameless SimpleTile Layer");
	~cLayer_Tile();

public:
	void RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR) override;
};

