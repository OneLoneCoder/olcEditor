#pragma once

#include <wx/wx.h>
#include <wx/glcanvas.h>

#include "common.h"
#include "RenderToolkit.h"

class cPanAndZoomRenderer : public wxGLCanvas
{
public:
	cPanAndZoomRenderer(wxWindow* parent, wxGLContext *gl);
	virtual ~cPanAndZoomRenderer();

private:
	// Mouse Events
	void IntOnPaint(wxPaintEvent& evt);
	void IntOnMouseLeftUp(wxMouseEvent& evt);
	void IntOnMouseLeftDown(wxMouseEvent& evt);
	void IntOnMouseMiddleUp(wxMouseEvent& evt);
	void IntOnMouseMiddleDown(wxMouseEvent& evt);
	void IntOnMouseRightUp(wxMouseEvent& evt);
	void IntOnMouseRightDown(wxMouseEvent& evt);
	void IntOnMouseMiddleWheel(wxMouseEvent& evt);	
	void IntOnMouseMove(wxMouseEvent& evt);

protected:
	virtual void OnMouseLeftUp(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl);
	virtual void OnMouseLeftDown(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl);
	virtual void OnMouseMiddleUp(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl);
	virtual void OnMouseMiddleDown(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl);
	virtual void OnMouseRightUp(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl);
	virtual void OnMouseRightDown(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl);
	virtual void OnMouseMove(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl);

	// Render Event
	virtual void OnRender();


protected:
	RenderToolkit gfx;

private:
	wxGLContext* m_glContext;

	olc::vf2d m_unitscale = { 1.0f, 1.0f };
	olc::vf2d m_startpan = { 0.0f, 0.0f };
	bool m_bWorldDrag = false;
};

