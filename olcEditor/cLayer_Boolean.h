#pragma once

#include "cTiledLayer.h"


class cLayer_Boolean : public cTiledLayerAdaptor<uint8_t>
{
public:
	cLayer_Boolean(const std::string& name = "Nameless Boolean Layer");
	~cLayer_Boolean();

public:
	void SetColourTrue(const olc::Pixel& col);
	olc::Pixel GetColourTrue() const;

	void SetColourFalse(const olc::Pixel& col);
	olc::Pixel GetColourFalse() const;

	void RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR) override;

	const std::string GetLayerTypeName() const override;
	const std::vector<sToolBarButton> GetToolBarButtons() const override;

protected:
	olc::Pixel m_colTrue = { 0, 255, 0 };
	olc::Pixel m_colFalse = { 255, 0, 0 };
};

