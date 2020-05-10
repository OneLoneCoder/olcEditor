#include "cPanAndZoomRenderer.h"

cPanAndZoomRenderer::cPanAndZoomRenderer(wxWindow* parent, wxGLContext* gl) : wxGLCanvas(parent, -1, nullptr)
{
	if(gl == nullptr) gl = new wxGLContext(this);
	m_glContext = gl;
	
	Connect(wxEVT_PAINT, wxPaintEventHandler(cPanAndZoomRenderer::IntOnPaint));
	Connect(wxEVT_MOTION, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseMove));
	Connect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseMiddleDown));
	Connect(wxEVT_MIDDLE_UP, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseMiddleUp));
	Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseMiddleWheel));
	Connect(wxEVT_LEFT_UP, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseLeftUp));
	Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseLeftDown));
	Connect(wxEVT_RIGHT_UP, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseRightUp));
	Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseRightDown));
}

cPanAndZoomRenderer::~cPanAndZoomRenderer()
{
	Disconnect(wxEVT_PAINT, wxPaintEventHandler(cPanAndZoomRenderer::IntOnPaint));
	Disconnect(wxEVT_MOTION, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseMove));
	Disconnect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseMiddleDown));
	Disconnect(wxEVT_MIDDLE_UP, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseMiddleUp));
	Disconnect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseMiddleWheel));
	Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseLeftUp));
	Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseLeftDown));
	Disconnect(wxEVT_RIGHT_UP, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseRightUp));
	Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(cPanAndZoomRenderer::IntOnMouseRightDown));
}

void cPanAndZoomRenderer::IntOnPaint(wxPaintEvent& evt)
{
	SetCurrent(*m_glContext);
	wxPaintDC(this);
	glViewport(0, 0, (GLint)GetSize().x, (GLint)GetSize().y);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, 0);


	gfx.vWorldView = { float(GetSize().x) / 2.0f, float(GetSize().y) / 2.0f };

	OnRender();
	glFlush();
	SwapBuffers();
}

void cPanAndZoomRenderer::IntOnMouseLeftUp(wxMouseEvent& evt)
{
	olc::vf2d p = gfx.ScreenToWorld({ float(evt.GetX()), float(evt.GetY()) });
	OnMouseLeftUp(p, evt.ShiftDown(), evt.ControlDown());
	evt.Skip();
}

void cPanAndZoomRenderer::IntOnMouseLeftDown(wxMouseEvent& evt)
{
	olc::vf2d p = gfx.ScreenToWorld({ float(evt.GetX()), float(evt.GetY()) });
	OnMouseLeftDown(p, evt.ShiftDown(), evt.ControlDown());
	evt.Skip();
}

void cPanAndZoomRenderer::IntOnMouseMiddleUp(wxMouseEvent& evt)
{
	m_bWorldDrag = false;
	olc::vf2d p = gfx.ScreenToWorld({ float(evt.GetX()), float(evt.GetY()) });
	OnMouseMiddleUp(p, evt.ShiftDown(), evt.ControlDown());
	evt.Skip();
}

void cPanAndZoomRenderer::IntOnMouseMiddleDown(wxMouseEvent& evt)
{
	m_bWorldDrag = true;
	m_startpan = { float(evt.GetX()), float(evt.GetY()) };
	olc::vf2d p = gfx.ScreenToWorld({ float(evt.GetX()), float(evt.GetY()) });
	OnMouseMiddleDown(p, evt.ShiftDown(), evt.ControlDown());
	evt.Skip();
}

void cPanAndZoomRenderer::IntOnMouseRightUp(wxMouseEvent& evt)
{
	olc::vf2d p = gfx.ScreenToWorld({ float(evt.GetX()), float(evt.GetY()) });
	OnMouseRightUp(p, evt.ShiftDown(), evt.ControlDown());
	evt.Skip();
}

void cPanAndZoomRenderer::IntOnMouseRightDown(wxMouseEvent& evt)
{
	olc::vf2d p = gfx.ScreenToWorld({ float(evt.GetX()), float(evt.GetY()) });
	OnMouseRightDown(p, evt.ShiftDown(), evt.ControlDown());
	evt.Skip();
}

void cPanAndZoomRenderer::IntOnMouseMiddleWheel(wxMouseEvent& evt)
{
	olc::vf2d mouse1 = gfx.ScreenToWorld({ float(evt.GetX()), float(evt.GetY()) });

	if (evt.GetWheelRotation() > 0)
	{
		gfx.vWorldScale *= 1.1f;
	}
	else
	{
		gfx.vWorldScale *= 0.9f;
	}

	olc::vf2d mouse2 = gfx.ScreenToWorld({ float(evt.GetX()), float(evt.GetY()) });
	gfx.vWorldOffset += (mouse1 - mouse2);
	Refresh();
	evt.Skip();
}

void cPanAndZoomRenderer::IntOnMouseMove(wxMouseEvent& evt)
{
	if (m_bWorldDrag)
	{
		olc::vf2d mouse = { float(evt.GetX()), float(evt.GetY()) };
		gfx.vWorldOffset -= (mouse - m_startpan) / gfx.vWorldScale;
		m_startpan = mouse;
	}
	olc::vf2d p = gfx.ScreenToWorld({ float(evt.GetX()), float(evt.GetY()) });
	OnMouseMove(p, evt.ShiftDown(), evt.ControlDown());
	evt.Skip();
	Refresh();
}

void cPanAndZoomRenderer::OnMouseLeftUp(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
}

void cPanAndZoomRenderer::OnMouseLeftDown(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
}

void cPanAndZoomRenderer::OnMouseMiddleUp(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
}

void cPanAndZoomRenderer::OnMouseMiddleDown(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
}

void cPanAndZoomRenderer::OnMouseRightUp(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
}

void cPanAndZoomRenderer::OnMouseRightDown(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
}

void cPanAndZoomRenderer::OnMouseMove(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
}

void cPanAndZoomRenderer::OnRender()
{
}
