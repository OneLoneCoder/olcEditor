#include "cMainFrame.h"

cMainFrame::cMainFrame() : MainFrameBase(nullptr)
{
	area = std::make_shared<cArea>();
	auto layer = std::make_shared<cLayer_Boolean>();
	layer->SetLayerSize({ 64, 64 });
	area->m_listLayers.push_back(layer);
	m_layerSelected = area->m_listLayers.front();

	m_render = new cPrimaryRenderer(m_renderpanel);
	m_rendersizer->Add(m_render, 1, wxEXPAND, 5);
	m_rendersizer->Layout();

	m_render->SetArea(area);

	this->Layout();

	Connect(olcEVT_Editor_MouseMove, EditorMouseMoveHandler(cMainFrame::OnEditorMouseMove));
	Connect(olcEVT_Editor_MouseLeftUp, EditorMouseLeftUpHandler(cMainFrame::OnEditorMouseLeftUp));
	Connect(olcEVT_Editor_MouseLeftDown, EditorMouseLeftDownHandler(cMainFrame::OnEditorMouseLeftDown));
}

cMainFrame::~cMainFrame()
{
	Disconnect(olcEVT_Editor_MouseMove, EditorMouseMoveHandler(cMainFrame::OnEditorMouseMove));
	Disconnect(olcEVT_Editor_MouseLeftUp, EditorMouseLeftUpHandler(cMainFrame::OnEditorMouseLeftUp));
	Disconnect(olcEVT_Editor_MouseLeftDown, EditorMouseLeftDownHandler(cMainFrame::OnEditorMouseLeftDown));
}

void cMainFrame::OnEditorMouseMove(cEditorMouseEvent& evt)
{
	m_status->SetStatusText(wxString::Format("Tile: %d, %d", evt.GetTile().x, evt.GetTile().y), 0);
	m_status->SetStatusText(wxString::Format("Pixel: %d, %d", evt.GetPixel().x, evt.GetPixel().y), 1);
	m_status->SetStatusText(wxString::Format("World: %f, %f", evt.GetWorld().x, evt.GetWorld().y), 2);	

	if (m_bLeftMouseDrag)
	{
		switch (m_layerSelected->GetType())
		{
		case LayerType::Boolean:
		{
			auto layer = (cLayer_Boolean*)m_layerSelected.get();
			layer->GetTile(evt.GetTile()) = 1;
			m_render->Refresh();
		}
		break;
		}
	}
}

void cMainFrame::OnEditorMouseLeftUp(cEditorMouseEvent& evt)
{
	if (m_layerSelected == nullptr)
		return;

	m_bLeftMouseDrag = false;
}

void cMainFrame::OnEditorMouseLeftDown(cEditorMouseEvent& evt)
{
	if (m_layerSelected == nullptr)
		return;

	m_bLeftMouseDrag = true;

	switch (m_layerSelected->GetType())
	{
		case LayerType::Boolean:
		{
			auto layer = (cLayer_Boolean*)m_layerSelected.get();
			layer->GetTile(evt.GetTile()) = 1;
			m_render->Refresh();
		}
		break;
	}
}