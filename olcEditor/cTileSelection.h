#pragma once

#include "cTiledLayer.h"

#undef None

class cTileSelection
{
public:
	cTileSelection();

public:
	void All(std::shared_ptr<cLayer> layer);
	void Nothing(std::shared_ptr<cLayer> layer);
	void Invert(std::shared_ptr<cLayer> layer);
	void Select(std::shared_ptr<cLayer> layer, const olc::vi2d& pos);
	void Deselect(std::shared_ptr<cLayer> layer, const olc::vi2d& pos);
	void Region(std::shared_ptr<cLayer> layer, const olc::vi2d& tl, const olc::vi2d& br);
	bool InSelection(std::shared_ptr<cLayer> layer, const olc::vi2d& pos);

	void RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR);

public:
	std::unordered_set<olc::vi2d> setSelected;
	std::unordered_set<olc::vi2d> setNotSelected;
};

