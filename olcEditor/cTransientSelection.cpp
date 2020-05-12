#include "cTransientSelection.h"

cTransientSelection::cTransientSelection()
{
}

void cTransientSelection::Clear()
{
	setSelected.clear();
}

void cTransientSelection::Select(const olc::vi2d& pos)
{
	setSelected.insert(pos);
	vRoot = pos;
}

void cTransientSelection::Deselect(const olc::vi2d& pos)
{
	setSelected.erase(pos);
}

void cTransientSelection::Region(const olc::vi2d& tl, const olc::vi2d& br)
{
	olc::vi2d s = { std::min(tl.x, br.x), std::min(tl.y, br.y) };
	olc::vi2d e = { std::max(tl.x, br.x), std::max(tl.y, br.y) };

	for (int y = s.y; y <= e.y; y++)
	{
		for (int x = s.x; x <= e.x; x++)
		{
			Select({ x, y });
		}
	}
}

bool cTransientSelection::InSelection(const olc::vi2d& pos)
{
	return setSelected.count(pos) > 0;
}
