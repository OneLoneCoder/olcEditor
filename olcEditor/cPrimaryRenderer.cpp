#include "cPrimaryRenderer.h"

cPrimaryRenderer::cPrimaryRenderer(wxWindow* parent) : wxGLCanvas(parent)
{
	m_glContext = new wxGLContext(this);

	Connect(wxEVT_PAINT, wxPaintEventHandler(cPrimaryRenderer::OnPaint));
	Connect(wxEVT_MOTION, wxMouseEventHandler(cPrimaryRenderer::OnMouseMove));
	Connect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(cPrimaryRenderer::OnMiddleMouseDown));
	Connect(wxEVT_MIDDLE_UP, wxMouseEventHandler(cPrimaryRenderer::OnMiddleMouseUp));
	Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(cPrimaryRenderer::OnMiddleMouseWheel));
}


cPrimaryRenderer::~cPrimaryRenderer()
{
	Disconnect(wxEVT_PAINT, wxPaintEventHandler(cPrimaryRenderer::OnPaint));
	Disconnect(wxEVT_MOTION, wxMouseEventHandler(cPrimaryRenderer::OnMouseMove));
	Disconnect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(cPrimaryRenderer::OnMiddleMouseDown));
	Disconnect(wxEVT_MIDDLE_UP, wxMouseEventHandler(cPrimaryRenderer::OnMiddleMouseUp));
	Disconnect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(cPrimaryRenderer::OnMiddleMouseWheel));
	delete m_glContext;
}

void cPrimaryRenderer::OnMiddleMouseWheel(wxMouseEvent& evt)
{
	vf2d mouse1 = ScreenToWorld({ float(evt.GetX()), float(evt.GetY()) });

	if (evt.GetWheelRotation() > 0)
	{
		m_scale.x *= 1.1f;
		m_scale.y *= 1.1f;
	}
	else
	{
		m_scale.x *= 0.9f;
		m_scale.y *= 0.9f;
	}

	vf2d mouse2 = ScreenToWorld({ float(evt.GetX()), float(evt.GetY()) });

	m_offset.x += (mouse1.x - mouse2.x);
	m_offset.y += (mouse1.y - mouse2.y);

	Refresh();
	evt.Skip();
}

void cPrimaryRenderer::OnMiddleMouseDown(wxMouseEvent& evt)
{
	m_bWorldDrag = true;
	m_startpan = { float(evt.GetX()), float(evt.GetY()) };
	evt.Skip();
}

void cPrimaryRenderer::OnMiddleMouseUp(wxMouseEvent& evt)
{
	m_bWorldDrag = false;
	evt.Skip();
}

void cPrimaryRenderer::OnMouseMove(wxMouseEvent& evt)
{
	m_cursor = ScreenToWorld({ float(evt.GetX()), float(evt.GetY()) });
	m_cursor.x = std::floor(m_cursor.x);
	m_cursor.y = std::floor(m_cursor.y);

	if (m_bWorldDrag)
	{
		vf2d mouse = { float(evt.GetX()), float(evt.GetY()) };
		m_offset.x -= (mouse.x - m_startpan.x) / m_scale.x;
		m_offset.y -= (mouse.y - m_startpan.y) / m_scale.y;
		m_startpan = mouse;
	
	}
	

	Refresh();
	evt.Skip();
}

void cPrimaryRenderer::OnPaint(wxPaintEvent& evt)
{
	SetCurrent(*m_glContext);
	wxPaintDC(this);
	glViewport(0, 0, (GLint)GetSize().x, (GLint)GetSize().y);	

	m_viewsize.x = float(GetSize().x) / 2.0f;
	m_viewsize.y = float(GetSize().y) / 2.0f;

	OnRender();	
	SwapBuffers();
}

vf2d cPrimaryRenderer::WorldToScreen(const vf2d& point)
{
	vf2d out;
	out.x = (point.x - m_offset.x) * m_scale.x;
	out.y = (point.y - m_offset.y) * m_scale.y;
	return out;
}

vf2d cPrimaryRenderer::ScreenToWorld(const vf2d& point)
{
	vf2d out;
	out.x = point.x / m_scale.x + m_offset.x;
	out.y = point.y / m_scale.y + m_offset.y;
	return out;
}

vf2d cPrimaryRenderer::ProjectToView(const vf2d& point)
{
	vf2d out;
	out.x = point.x / m_viewsize.x - 1.0f;
	out.y = -(point.y / m_viewsize.y - 1.0f);
	return out;
}

void cPrimaryRenderer::DrawLine(const vf2d& start, const vf2d& end, const float width)
{
	vf2d s = ProjectToView(WorldToScreen({ start.x, start.y }));
	vf2d e = ProjectToView(WorldToScreen({ end.x, end.y }));

	glLineWidth(width);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(s.x, s.y);
	glVertex2f(e.x, e.y);
	glEnd();
	glFlush();
}

void cPrimaryRenderer::DrawRect(const vf2d& start, const vf2d& size, const float width)
{
	vf2d s = ProjectToView(WorldToScreen({ start.x, start.y }));
	vf2d e = ProjectToView(WorldToScreen({ start.x+size.x, start.y+size.y }));

	glLineWidth(width);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(s.x, s.y);
	glVertex2f(s.x, e.y);
	glVertex2f(s.x, e.y);
	glVertex2f(e.x, e.y);
	glVertex2f(e.x, e.y);
	glVertex2f(e.x, s.y);
	glVertex2f(e.x, s.y);
	glVertex2f(s.x, s.y);
	glEnd();
	glFlush();
}

void cPrimaryRenderer::OnRender()
{
	glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	DrawLine({ -0, -0 }, { -0, 3 });
	DrawLine({ -0, 3 }, { 3, 3 });
	DrawLine({ 3, 3 }, { 3, -0 });
	DrawLine({ 3, -0 }, { -0, -0 });
	DrawLine({ -0, -0 }, { 3, 3 });


	// Draw Tile Grid
	vf2d vTopLeftWorld = ScreenToWorld({ 0,0 });
	vf2d vBottomRightWorld = ScreenToWorld({ m_viewsize.x * 2.0f, m_viewsize.y * 2.0f});

	vTopLeftWorld.x = std::floor(vTopLeftWorld.x);
	vTopLeftWorld.y = std::floor(vTopLeftWorld.y);


	for (float x = vTopLeftWorld.x - 1; x < vBottomRightWorld.x + 1; x += 1.0f)
	{
		DrawLine({ x, vTopLeftWorld.y }, { x, vBottomRightWorld.y });		
	}

	for (float y = vTopLeftWorld.y - 1; y < vBottomRightWorld.y + 1; y += 1.0f)
	{
		DrawLine({vTopLeftWorld.x, y }, { vBottomRightWorld.x, y });
	}


	DrawRect(m_cursor, { 1.0f, 1.0f }, 3);
}