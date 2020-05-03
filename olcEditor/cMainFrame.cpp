#include "cMainFrame.h"

cMainFrame::cMainFrame() : MainFrameBase(nullptr)
{

	m_render = new cPrimaryRenderer(this);
	m_mainsizer->Add(m_render, 1, wxEXPAND, 5);

	this->Layout();

	Connect(olcEVT_Editor_MouseMove, EditorMouseMoveHandler(cMainFrame::OnEditorMouseMove));
}

cMainFrame::~cMainFrame()
{
	Disconnect(olcEVT_Editor_MouseMove, EditorMouseMoveHandler(cMainFrame::OnEditorMouseMove));
}

void cMainFrame::OnEditorMouseMove(cEditorMouseMoveEvent& evt)
{
	m_status->SetStatusText(wxString::Format("Tile: %d, %d", evt.GetTileX(), evt.GetTileY()), 0);
	m_status->SetStatusText(wxString::Format("Pixel: %d, %d", evt.GetPixelX(), evt.GetPixelY()), 1);
	m_status->SetStatusText(wxString::Format("World: %f, %f", evt.GetWorldX(), evt.GetWorldY()), 2);
}