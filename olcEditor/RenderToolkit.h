#pragma once

#include <wx/wx.h>
#include <wx/glcanvas.h>

#include "common.h"

class RenderToolkit
{
public:
	RenderToolkit();

public:
	olc::vf2d vWorldOffset = { 0,0 };
	olc::vf2d vWorldScale = { 1, 1 };
	olc::vf2d vWorldView = { 1,1 };

public:
	olc::vf2d WorldToScreen(const olc::vf2d& point);
	olc::vf2d ScreenToWorld(const olc::vf2d& point);
	olc::vf2d ProjectToView(const olc::vf2d& point);

public:
	void Clear(const olc::colour& colour);
	void DrawLine(const olc::vf2d& start, const olc::vf2d& end, const olc::colour col, const float width = 1.0f);
	void DrawRect(const olc::vf2d& start, const olc::vf2d& size, const olc::colour col, const float width = 1.0f);
	void FillRect(const olc::vf2d& start, const olc::vf2d& size, const olc::colour col, const float width = 1.0f);
};

