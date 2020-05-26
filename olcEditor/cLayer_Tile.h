#pragma once
#include "cTiledLayer.h"
#include "cImageResource.h"
#include "cGridSelection.h"


class cLayer_Tile : public cTiledLayerAdaptor<sTileDescription, sBrushElement<sTileDescription>>
{
public:
	cLayer_Tile(const std::string& name, std::vector<std::shared_ptr<cImageResource>>& vImageResources);
	~cLayer_Tile();

public:
	void RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR) override;
	void RenderCursor(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR, std::shared_ptr<cImageResource> image, std::shared_ptr<cGridSelection> selection, const olc::vi2d& cursor);
	


protected:
	std::vector<std::shared_ptr<cImageResource>>& m_vImageResources;
};

