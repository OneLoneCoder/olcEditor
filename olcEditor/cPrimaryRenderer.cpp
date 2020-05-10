#include "cPrimaryRenderer.h"

wxDEFINE_EVENT(olcEVT_Editor_MouseMove, cEditorMouseEvent);
wxDEFINE_EVENT(olcEVT_Editor_MouseLeftUp, cEditorMouseEvent);
wxDEFINE_EVENT(olcEVT_Editor_MouseLeftDown, cEditorMouseEvent);
wxDEFINE_EVENT(olcEVT_Editor_MouseRightUp, cEditorMouseEvent);
wxDEFINE_EVENT(olcEVT_Editor_MouseRightDown, cEditorMouseEvent);

cPrimaryRenderer::cPrimaryRenderer(wxWindow* parent, wxGLContext* gl) : cPanAndZoomRenderer(parent, gl)
{
	gfx.vWorldScale = { 32.0f, 32.0f };
}


cPrimaryRenderer::~cPrimaryRenderer()
{

}


void cPrimaryRenderer::SetArea(std::shared_ptr<cArea> area)
{
	m_area = area;
	Refresh();
}

void cPrimaryRenderer::SetTileSelector(std::shared_ptr<cTileSelection> selector)
{
	m_selectTiles = selector;
}

void cPrimaryRenderer::OnRender()
{
	// Erase everything
	gfx.Clear(olc::PixelF(0.2f, 0.2f, 0.2f, 1.0f ));


	// Draw Tile Grid
	olc::vf2d vWorldTL = gfx.ScreenToWorld({ 0,0 });
	olc::vf2d vWorldBR = gfx.ScreenToWorld(gfx.vWorldView * 2.0f);

	vWorldTL.x = std::floor(vWorldTL.x);
	vWorldTL.y = std::floor(vWorldTL.y);
	vWorldBR.x = std::ceil(vWorldBR.x);
	vWorldBR.y = std::ceil(vWorldBR.y);

	// Draw Layers
	if (m_area != nullptr)
	{
		for (auto& layer : m_area->m_listLayers)
		{			
			layer->RenderSelf(gfx, vWorldTL, vWorldBR);
		}
	}

	// Draw Selection Grid
	if (m_selectTiles != nullptr)
	{
		m_selectTiles->RenderSelf(gfx, vWorldTL, vWorldBR);
	}

	// Draw 0 Axis
	gfx.DrawLine({ 0.0f, vWorldTL.y }, { 0.0f, vWorldBR.y }, olc::PixelF( 1, 1, 1, 0.5f ), 3);
	gfx.DrawLine({ vWorldTL.x, 0.0f }, { vWorldBR.x, 0.0f }, olc::PixelF(1, 1, 1, 0.5f ), 3);

	// Draw Overlay Grid
	for (float x = vWorldTL.x - 1; x < vWorldBR.x + 1; x += 1.0f)
	{
		gfx.DrawLine({ x, vWorldTL.y }, { x, vWorldBR.y }, olc::PixelF(1, 1, 1, 0.2f ));
	}

	for (float y = vWorldTL.y - 1; y < vWorldBR.y + 1; y += 1.0f)
	{
		gfx.DrawLine({ vWorldTL.x, y }, { vWorldBR.x, y }, olc::PixelF(1, 1, 1, 0.2f ));
	}

	if (m_bDrawingRegion)
	{
		gfx.FillRect(m_vRegionTL, m_vRegionBR - m_vRegionTL + olc::vi2d(1, 1), olc::PixelF(1, 1, 0, 0.2f ));
		gfx.DrawRect(m_vRegionTL, m_vRegionBR - m_vRegionTL + olc::vi2d(1, 1), olc::PixelF(1, 1, 1, 0.5f ), 6);
		gfx.DrawRect(m_vRegionTL, m_vRegionBR - m_vRegionTL + olc::vi2d(1, 1), olc::PixelF(1, 1, 0, 1.0f ), 3);
	}

	// Draw Mouse Cursor
	gfx.DrawRect(m_cursor, { 1.0f, 1.0f }, olc::PixelF(1, 1, 1, 0.5 ), 6);
	gfx.DrawRect(m_cursor, { 1.0f, 1.0f }, olc::PixelF( 0,0,0 ), 3);
}

cEditorMouseEvent cPrimaryRenderer::ConstructMouseEvent(const wxEventTypeTag<cEditorMouseEvent>& e, const olc::vf2d& vWorldPos, const bool bShift, const bool bControl, const olc::vi2d& vTileSize)
{
	cEditorMouseEvent evt(e);
	evt.SetWorld(vWorldPos);
	evt.SetTile(olc::vi2d(vWorldPos));
	evt.SetPixel({ int(float(vWorldPos.x - int(vWorldPos.x)) * float(vTileSize.x)),int(float(vWorldPos.y - int(vWorldPos.y)) * float(vTileSize.y)) });
	evt.SetControlHeld(bControl);
	evt.SetShiftHeld(bShift);
	return evt;
}


void cPrimaryRenderer::OnMouseLeftUp(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
	cEditorMouseEvent e = ConstructMouseEvent(olcEVT_Editor_MouseLeftUp, vWorldPos, bShift, bControl, m_vTileSize);	
	wxPostEvent(this->GetParent(), e);	
}

void cPrimaryRenderer::OnMouseLeftDown(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
	cEditorMouseEvent e = ConstructMouseEvent(olcEVT_Editor_MouseLeftDown, vWorldPos, bShift, bControl, m_vTileSize);
	wxPostEvent(this->GetParent(), e);
}

void cPrimaryRenderer::OnMouseMiddleUp(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
}

void cPrimaryRenderer::OnMouseMiddleDown(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
}

void cPrimaryRenderer::OnMouseRightUp(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
}

void cPrimaryRenderer::OnMouseRightDown(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
}

void cPrimaryRenderer::OnMouseMove(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
	cEditorMouseEvent e = ConstructMouseEvent(olcEVT_Editor_MouseMove, vWorldPos, bShift, bControl, m_vTileSize);
	wxPostEvent(this->GetParent(), e);
}

void cPrimaryRenderer::EnableRegionMode(bool b)
{
	m_bDrawingRegion = b;
}

void cPrimaryRenderer::SetTileRegion(const olc::vi2d& vRegionTL, const olc::vi2d& vRegionBR)
{
	m_vRegionTL = { float(std::min(vRegionTL.x, vRegionBR.x)), float(std::min(vRegionTL.y, vRegionBR.y)) };
	m_vRegionBR = { float(std::max(vRegionTL.x, vRegionBR.x)), float(std::max(vRegionTL.y, vRegionBR.y)) };
}

