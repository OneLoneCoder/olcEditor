#include "cPrimaryRenderer.h"

wxDEFINE_EVENT(olcEVT_Editor_MouseMove, cEditorMouseEvent);
wxDEFINE_EVENT(olcEVT_Editor_MouseLeftUp, cEditorMouseEvent);
wxDEFINE_EVENT(olcEVT_Editor_MouseLeftDown, cEditorMouseEvent);

cPrimaryRenderer::cPrimaryRenderer(wxWindow* parent) : wxGLCanvas(parent)
{
	m_glContext = new wxGLContext(this);

	Connect(wxEVT_PAINT, wxPaintEventHandler(cPrimaryRenderer::OnPaint));
	Connect(wxEVT_MOTION, wxMouseEventHandler(cPrimaryRenderer::OnMouseMove));
	Connect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(cPrimaryRenderer::OnMiddleMouseDown));
	Connect(wxEVT_MIDDLE_UP, wxMouseEventHandler(cPrimaryRenderer::OnMiddleMouseUp));
	Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(cPrimaryRenderer::OnMiddleMouseWheel));
	Connect(wxEVT_LEFT_UP, wxMouseEventHandler(cPrimaryRenderer::OnMouseLeftUp));
	Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(cPrimaryRenderer::OnMouseLeftDown));
	
	gfx.vWorldScale = { 32.0f, 32.0f };
}


cPrimaryRenderer::~cPrimaryRenderer()
{
	Disconnect(wxEVT_PAINT, wxPaintEventHandler(cPrimaryRenderer::OnPaint));
	Disconnect(wxEVT_MOTION, wxMouseEventHandler(cPrimaryRenderer::OnMouseMove));
	Disconnect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(cPrimaryRenderer::OnMiddleMouseDown));
	Disconnect(wxEVT_MIDDLE_UP, wxMouseEventHandler(cPrimaryRenderer::OnMiddleMouseUp));
	Disconnect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(cPrimaryRenderer::OnMiddleMouseWheel));
	Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(cPrimaryRenderer::OnMouseLeftUp));
	Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(cPrimaryRenderer::OnMouseLeftDown));
	delete m_glContext;
}


void cPrimaryRenderer::SetArea(std::shared_ptr<cArea> area)
{
	m_area = area;
	Refresh();
}

void cPrimaryRenderer::OnMiddleMouseWheel(wxMouseEvent& evt)
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


void cPrimaryRenderer::OnMouseLeftUp(wxMouseEvent& evt)
{
	cEditorMouseEvent e(olcEVT_Editor_MouseLeftUp);
	olc::vf2d mouse = gfx.ScreenToWorld({ float(evt.GetX()), float(evt.GetY()) });
	e.SetWorld(mouse);
	e.SetPixel({ int((e.GetWorld().x - int(mouse.x)) * float(32)), int((e.GetWorld().y - int(mouse.y)) * float(32)) });
	e.SetTile(olc::vi2d(mouse));
	wxPostEvent(this->GetParent(), e);
	evt.Skip();
}

void cPrimaryRenderer::OnMouseLeftDown(wxMouseEvent& evt)
{
	cEditorMouseEvent e(olcEVT_Editor_MouseLeftDown);
	olc::vf2d mouse = gfx.ScreenToWorld({ float(evt.GetX()), float(evt.GetY()) });
	e.SetWorld(mouse);
	e.SetPixel({ int((e.GetWorld().x - int(mouse.x)) * float(32)), int((e.GetWorld().y - int(mouse.y)) * float(32)) });
	e.SetTile(olc::vi2d(mouse));
	wxPostEvent(this->GetParent(), e);
	evt.Skip();
	evt.Skip();
}

void cPrimaryRenderer::OnMouseMove(wxMouseEvent& evt)
{
	cEditorMouseEvent e(olcEVT_Editor_MouseMove);

	m_cursor = gfx.ScreenToWorld({ float(evt.GetX()), float(evt.GetY()) });
	e.SetWorld(m_cursor);	
	m_cursor.x = std::floor(m_cursor.x);
	m_cursor.y = std::floor(m_cursor.y);
	e.SetPixel((e.GetWorld() - m_cursor) * float(32));	
	e.SetTile(olc::vi2d(m_cursor));

	if (m_bWorldDrag)
	{
		olc::vf2d mouse = { float(evt.GetX()), float(evt.GetY()) };
		gfx.vWorldOffset -= (mouse - m_startpan) / gfx.vWorldScale;
		m_startpan = mouse;
	}

	wxPostEvent(this->GetParent(), e);
	Refresh();
	evt.Skip();
}

void cPrimaryRenderer::OnPaint(wxPaintEvent& evt)
{
	SetCurrent(*m_glContext);
	wxPaintDC(this);
	glViewport(0, 0, (GLint)GetSize().x, (GLint)GetSize().y);	

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);


	gfx.vWorldView = { float(GetSize().x) / 2.0f, float(GetSize().y) / 2.0f };

	OnRender();	
	glFlush();
	SwapBuffers();
}


void cPrimaryRenderer::OnRender()
{
	// Erase everything
	gfx.Clear({ 0.2f, 0.2f, 0.2f, 1.0f });


	// Draw Tile Grid
	olc::vf2d vWorldTL = gfx.ScreenToWorld({ 0,0 });
	olc::vf2d vWorldBR = gfx.ScreenToWorld(gfx.vWorldView * 2.0f);

	vWorldTL.x = std::floor(vWorldTL.x);
	vWorldTL.y = std::floor(vWorldTL.y);
	vWorldBR.x = std::ceil(vWorldBR.x);
	vWorldBR.y = std::ceil(vWorldBR.y);

	// Draw Layer
	if (m_area != nullptr)
	{
		for (auto& layer : m_area->m_listLayers)
		{			
			layer->RenderSelf(gfx, vWorldTL, vWorldBR);
		}
	}

	// Draw 0 Axis
	gfx.DrawLine({ 0.0f, vWorldTL.y }, { 0.0f, vWorldBR.y }, { 1, 1, 1, 0.5f }, 3);
	gfx.DrawLine({ vWorldTL.x, 0.0f }, { vWorldBR.x, 0.0f }, { 1, 1, 1, 0.5f }, 3);

	// Draw Overlay Grid
	for (float x = vWorldTL.x - 1; x < vWorldBR.x + 1; x += 1.0f)
	{
		gfx.DrawLine({ x, vWorldTL.y }, { x, vWorldBR.y }, { 1, 1, 1, 0.2f });
	}

	for (float y = vWorldTL.y - 1; y < vWorldBR.y + 1; y += 1.0f)
	{
		gfx.DrawLine({ vWorldTL.x, y }, { vWorldBR.x, y }, { 1, 1, 1, 0.2f });
	}

	// Draw 0 Axis

	gfx.DrawRect(m_cursor, { 1.0f, 1.0f }, { 1, 1, 0 }, 3);
}

