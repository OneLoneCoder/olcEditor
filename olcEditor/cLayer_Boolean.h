#pragma once

#include "cTiledLayer.h"


class cLayer_Boolean : public cTiledLayerAdaptor<uint8_t>
{
public:
	cLayer_Boolean(const std::string& name = "Nameless Boolean Layer");
	~cLayer_Boolean();

public:
	void SetColourTrue(const olc::colour& col);
	olc::colour GetColourTrue() const;

	void SetColourFalse(const olc::colour& col);
	olc::colour GetColourFalse() const;

	void RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR) override;

protected:
	olc::colour m_colTrue = { 0, 1, 0 };
	olc::colour m_colFalse = { 1, 0, 0 };
};

