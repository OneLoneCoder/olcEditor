#pragma once

#include "common.h"




class cGridSelection
{
public:
	cGridSelection();

public:
	void Clear();
	void Select(const olc::vi2d& pos);
	void Deselect(const olc::vi2d& pos);
	void Region(const olc::vi2d& tl, const olc::vi2d& br);
	bool InSelection(const olc::vi2d& pos);

public:
	std::unordered_set<olc::vi2d> setSelected;
	olc::vi2d vRoot;
};

