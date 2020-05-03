#pragma once

#include <wx/wx.h>
#include <wx/glcanvas.h>

struct vf2d
{
	float x;
	float y;
};

class cPrimaryRenderer : public wxGLCanvas
{
public:
	cPrimaryRenderer(wxWindow* parent);
	virtual ~cPrimaryRenderer();

protected:
	void OnRender();

	void DrawLine(const vf2d& start, const vf2d& end, const float width = 1.0f);
	void DrawRect(const vf2d& start, const vf2d& size, const float width = 1.0f);

	vf2d WorldToScreen(const vf2d& point);
	vf2d ScreenToWorld(const vf2d& point);
	vf2d ProjectToView(const vf2d& point);

protected:
	void OnPaint(wxPaintEvent& evt);
	void OnMiddleMouseDown(wxMouseEvent& evt);
	void OnMiddleMouseUp(wxMouseEvent& evt);
	void OnMiddleMouseWheel(wxMouseEvent& evt);
	void OnMouseMove(wxMouseEvent& evt);

private:
	wxGLContext* m_glContext;
	vf2d m_unitscale = { 1.0f, 1.0f };
	vf2d m_scale = {32.0f, 32.0f};
	vf2d m_offset = { 0.0f, 0.0f };	
	vf2d m_startpan = { 0.0f, 0.0f };
	vf2d m_viewsize = { 0,0 };
	vf2d m_cursor = { 0,0 };
	bool m_bWorldDrag = false;
	float m_fZoom = 1.0f;
};

