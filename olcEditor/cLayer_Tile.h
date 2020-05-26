#pragma once
#include "cTiledLayer.h"
#include "cImageResource.h"
#include "cGridSelection.h"

struct sTileDescription
{
	uint32_t nResourceID = 0;
	olc::vf2d vPosition = { 0,0 };
	olc::vf2d vSize = { 0,0 };
	uint32_t nTileIndex = 0;
	bool exist = false;
};


class cContentContainerTiles : public cContentContainer<sTileDescription>
{
public:
	cContentContainerTiles(std::shared_ptr<cImageResource> image)
	{
		m_pImage = image;
	}

	const sTileDescription Get(const olc::vi2d& vPos) const override
	{
		olc::vi2d vPixelPos = (vPos * (m_pImage->GetGridSize() + m_pImage->GetGridSpacing())) + m_pImage->GetGridOffset();

		olc::vf2d vTexturePos;
		vTexturePos.x = float(vPixelPos.x) / float(m_pImage->GetSprite()->vSize.x);
		vTexturePos.y = float(vPixelPos.y) / float(m_pImage->GetSprite()->vSize.y);
		olc::vf2d vTextureSize;
		vTextureSize.x = float(m_pImage->GetGridSize().x) / float(m_pImage->GetSprite()->vSize.x);
		vTextureSize.y = float(m_pImage->GetGridSize().y) / float(m_pImage->GetSprite()->vSize.y);

		sTileDescription d;
		d.nResourceID = m_pImage->GetProjectID();
		d.vPosition = vTexturePos;
		d.vSize = vTextureSize;
		d.exist = true;
		return d;
	}

private:
	std::shared_ptr<cImageResource> m_pImage = nullptr;
};

class cLayer_Tile : public cTiledLayer<sTileDescription, sBrushElement<sTileDescription>>
{
public:
	cLayer_Tile(const std::string& name, std::vector<std::shared_ptr<cImageResource>>& vImageResources);
	~cLayer_Tile();

public:
	void RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR) override;
	void RenderBrush(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR) override;
	
protected:
	std::vector<std::shared_ptr<cImageResource>>& m_vImageResources;
};

