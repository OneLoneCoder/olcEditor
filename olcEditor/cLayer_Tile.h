#pragma once
#include "cTiledLayer.h"
#include "cImageResource.h"


class cLayer_Tile : public cTiledLayerAdaptor<sTileDescription>
{
public:
	cLayer_Tile(const std::string& name, std::vector<std::shared_ptr<cImageResource>>& vImageResources);
	~cLayer_Tile();

public:
	void RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR) override;

protected:
	std::vector<std::shared_ptr<cImageResource>>& m_vImageResources;
};

