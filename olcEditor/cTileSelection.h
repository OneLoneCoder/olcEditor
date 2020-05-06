#pragma once

#include "cTiledLayer.h"

namespace std
{
	template<>
	struct hash<olc::vi2d>
	{
		size_t operator()(const olc::vi2d& obj) const
		{
			return hash<uint64_t>()(size_t(obj.y) << 32 | size_t(obj.x));
		}
	};
}

class cTileSelection
{
public:
	cTileSelection();

public:
	void All(std::shared_ptr<cTiledLayer> layer);
	void None(std::shared_ptr<cTiledLayer> layer);
	void Invert(std::shared_ptr<cTiledLayer> layer);
	void Select(std::shared_ptr<cTiledLayer> layer, const olc::vi2d& pos);
	void Deselect(std::shared_ptr<cTiledLayer> layer, const olc::vi2d& pos);
	void Region(std::shared_ptr<cTiledLayer> layer, const olc::vi2d& tl, const olc::vi2d& br);
	bool InSelection(std::shared_ptr<cTiledLayer> layer, const olc::vi2d& pos);

	void RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR);

public:
	std::unordered_set<olc::vi2d> setSelected;
	std::unordered_set<olc::vi2d> setNotSelected;
};

