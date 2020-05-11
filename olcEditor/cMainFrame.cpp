#include "cMainFrame.h"

cMainFrame::cMainFrame() : MainFrameBase(nullptr)
{
	// Create Master Context, then hide it - this is a wxWidgets peculiarity
	// as it requires a window in order to construct the context
	m_glMasterContext = new cMasterContext(this);
	m_glMasterContext->Hide();
	m_glContext = m_glMasterContext->GetContext();


	area = std::make_shared<cArea>();
	auto layer = std::make_shared<cLayer_Boolean>();
	layer->SetLayerSize({ 64, 64 });
	area->m_listLayers.push_back(layer);
	m_layerSelected = area->m_listLayers.front();

	m_render = new cPrimaryRenderer(m_renderpanel, m_glContext);
	m_rendersizer->Add(m_render, 1, wxEXPAND, 5);
	m_rendersizer->Layout();

	m_selectTile = std::make_shared<cTileSelection>();


	m_render->SetArea(area);
	m_render->SetTileSelector(m_selectTile);

	m_selectTile->All(layer);

	m_drawTool = DrawingTool::TileDrawSingle;


	// Image Palette Preview
	m_tiledImageViewer = new cTiledResourceViewer(m_panelImages, m_glContext);
	m_sizerImagePreview->Add(m_tiledImageViewer, 1, wxEXPAND, 5);
	m_panelImages->Layout();

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
		if (m_layerSelected->GetContentType() == ContentType::Tiles)
		{
			auto layer = std::dynamic_pointer_cast<cLayer_Boolean>(m_layerSelected);

			if (m_drawTool == DrawingTool::TileSelectRegion)
			{
				m_vTileRegionBR = evt.GetTile();
				m_render->SetTileRegion(m_vTileRegionTL, m_vTileRegionBR);
			}

			if (m_drawTool == DrawingTool::TileDrawSingle)
			{
				if (m_selectTile->InSelection(layer, evt.GetTile()))
				{
					layer->GetTile(evt.GetTile()) = 1;
				}
			}
		}

		m_render->Refresh();
	}
}

void cMainFrame::OnEditorMouseLeftUp(cEditorMouseEvent& evt)
{
	if (m_layerSelected == nullptr)
		return;
	m_bLeftMouseDrag = false;

	if (m_layerSelected->GetContentType() == ContentType::Tiles)
	{
		if (m_drawTool == DrawingTool::TileSelectRegion)
		{
			m_vTileRegionBR = evt.GetTile();
			m_render->SetTileRegion(m_vTileRegionTL, m_vTileRegionBR);
			m_selectTile->Region(std::dynamic_pointer_cast<cTiledLayer>(m_layerSelected), m_vTileRegionTL, m_vTileRegionBR);			
		}
	}

	m_render->EnableRegionMode(false);

	m_render->Refresh();
}

void cMainFrame::OnEditorMouseLeftDown(cEditorMouseEvent& evt)
{
	if (m_layerSelected == nullptr)
		return;

	m_bLeftMouseDrag = true;

	if (m_layerSelected->GetContentType() == ContentType::Tiles)
	{
		auto layer = std::dynamic_pointer_cast<cLayer_Boolean>(m_layerSelected);

		if (m_drawTool == DrawingTool::TileSelectRegion)
		{
			m_vTileRegionTL = evt.GetTile();
			m_vTileRegionBR = evt.GetTile();
			m_render->SetTileRegion(m_vTileRegionTL, m_vTileRegionBR);
			m_render->EnableRegionMode(true);
			if(!evt.GetControlHeld())
				m_selectTile->None(layer);			
		}

		if (m_drawTool == DrawingTool::TileDrawSingle)
		{
			if (m_selectTile->InSelection(layer, evt.GetTile()))
			{
				layer->GetTile(evt.GetTile()) = 1;
			}
		}
	}

	m_render->Refresh();
}

void cMainFrame::OnButtonSelectClear(wxCommandEvent& evt)
{
	if (m_layerSelected != nullptr)
	{
		if (m_layerSelected->GetContentType() == ContentType::Tiles)
		{
			m_selectTile->All(std::dynamic_pointer_cast<cTiledLayer>(m_layerSelected));
		}
	}

	m_render->Refresh();
}

void cMainFrame::OnButtonSelectRegion(wxCommandEvent& evt)
{
	m_drawTool = DrawingTool::TileSelectRegion;

	if (m_layerSelected != nullptr)
	{
		if (m_layerSelected->GetContentType() == ContentType::Tiles)
		{
			m_selectTile->None(std::dynamic_pointer_cast<cTiledLayer>(m_layerSelected));
		}
	}

	m_render->Refresh();
}

void cMainFrame::OnButtonSelectMove(wxCommandEvent& evt)
{
	
	
}

void cMainFrame::OnButtonSelectFill(wxCommandEvent& evt)
{

}

void cMainFrame::OnButtonTileDraw(wxCommandEvent& evt)
{
	m_drawTool = DrawingTool::TileDrawSingle;
}

void cMainFrame::OnButtonTileLine(wxCommandEvent& evt)
{

}

void cMainFrame::OnButtonTileDrawRect(wxCommandEvent& evt)
{

}

void cMainFrame::OnButtonTileFillRect(wxCommandEvent& evt)
{

}

void cMainFrame::OnButtonTileDrawCircle(wxCommandEvent& evt)
{

}

void cMainFrame::OnButtonTileFillCircle(wxCommandEvent& evt)
{

}

void cMainFrame::OnButtonTileFloodFill(wxCommandEvent& evt)
{

}

void cMainFrame::UpdateImageList()
{
	// Clear the list box
	m_lbImages->Clear();

	// Add friendly names
	for (auto& i : m_vecImageResources)
		m_lbImages->AppendString(i->GetFriendlyName());

}


void cMainFrame::OnAddImage(wxCommandEvent& evt)
{
	// Create new Image Resource
	std::shared_ptr<cImageResource> newImage = std::make_shared<cImageResource>(m_glMasterContext);

	// Pop-up Resource Editor
	cImageResourceEditor dlg(this, m_glMasterContext, newImage);
	if (dlg.ShowModal() == wxID_OK)
	{
		// Resource accepted, add to list
		m_vecImageResources.push_back(newImage);

		// Refresh the image list
		UpdateImageList();
	}
}

void cMainFrame::OnEraseImage(wxCommandEvent& evt)
{
	
}

void cMainFrame::OnEditImage(wxCommandEvent& evt)
{	
	int idx = m_lbImages->GetSelection();
	if (idx >= 0)
	{
		cImageResourceEditor dlg(this, m_glMasterContext, m_vecImageResources[idx]);
		if (dlg.ShowModal() == wxID_OK)
		{
			// Refresh the image list
			UpdateImageList();
			m_lbImages->Select(idx);
			m_lbImages->EnsureVisible(idx);
		}
	}
}

void cMainFrame::OnImageSelectChange(wxCommandEvent& evt)
{
	m_tiledImageViewer->SetImageResource(m_vecImageResources[evt.GetSelection()]);
}
