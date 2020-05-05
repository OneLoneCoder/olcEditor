#pragma once
#include "cLayer.h"



class cLayer_Boolean : public cLayer
{
public:
	cLayer_Boolean(const std::string& name = "Nameless Boolean Layer");
	~cLayer_Boolean();

public:
	void SetLayerSize(const olc::vi2d& size);
	olc::vi2d GetLayerSize() const;

	void SetTileSize(const olc::vi2d& size);
	olc::vi2d GetTileSize() const;

	int& GetTile(const olc::vi2d& pos);
	int& GetTile(const int x, const int y);

	void SetColourTrue(const olc::colour& col);
	olc::colour GetColourTrue() const;

	void SetColourFalse(const olc::colour& col);
	olc::colour GetColourFalse() const;

	void RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR) override;

protected:
	olc::colour m_colTrue = { 0, 1, 0 };
	olc::colour m_colFalse = { 1, 0, 0 };
	olc::vi2d m_vTileSize = { 32, 32 };
	olc::vi2d m_vLayerSize = { 0, 0 };
	std::vector<int> m_tiles;
	int NullBool = 0;
};

