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
	olc::vf2d vWorldView = { 1, 1 };
	//olc::vf2d vWorldUnit = { 1, 1 };

public:
	olc::vf2d WorldToScreen(const olc::vf2d& point);
	olc::vf2d ScreenToWorld(const olc::vf2d& point);
	//olc::vf2d LayerToScreen(const olc::vf2d& point);
	//olc::vf2d ScreenToLayer(const olc::vf2d& point);
	olc::vf2d ProjectToView(const olc::vf2d& point);

public:
	void Clear(const olc::Pixel& colour);
	void DrawLine(const olc::vf2d& start, const olc::vf2d& end, const olc::Pixel col, const float width = 1.0f);
	void DrawRect(const olc::vf2d& start, const olc::vf2d& size, const olc::Pixel col, const float width = 1.0f);
	void FillRect(const olc::vf2d& start, const olc::vf2d& size, const olc::Pixel col, const float width = 1.0f);
	void DrawImage(int nResourceID, const olc::vf2d& start, const olc::vf2d& size, const olc::Pixel col = { 255,255,255 });
	void DrawSubImage(int nResourceID, const olc::vf2d& pos, const olc::vf2d& size, const olc::vf2d& sourcepos, const olc::vf2d& sourcesize, const olc::Pixel col = { 255,255,255 });
};

