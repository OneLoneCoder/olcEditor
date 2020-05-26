#pragma once

#include "cTiledLayer.h"

class cContentContainerBoolean : public cContentContainer<uint8_t>
{
public:
	cContentContainerBoolean(bool b)
	{
		m_nContent = b ? 1 : 0;
	}

	const uint8_t Get(const olc::vi2d& vPos) const override
	{
		return m_nContent;
	}

private:
	uint8_t m_nContent = 0;
};


class cLayer_Boolean : public cTiledLayer<uint8_t, sBrushElement<uint8_t>>
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
	void RenderBrush(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR) override;

protected:
	olc::Pixel m_colTrue = { 0, 255, 0 };
	olc::Pixel m_colFalse = { 255, 0, 0, 0 };
};

