#include "cMainFrame.h"

cMainFrame::cMainFrame() : MainFrameBase(nullptr)
{
	// Create Master Context, then hide it - this is a wxWidgets peculiarity
	// as it requires a window in order to construct the context
	m_glMasterContext = new cMasterContext(this);
	m_glMasterContext->Hide();
	m_glContext = m_glMasterContext->GetContext();

	// Create selection conveyors
	m_selectionGrid = std::make_shared<cGridSelection>();
	m_selectTile = std::make_shared<cTileSelection>();

	// Create Project structure
	area = std::make_shared<cArea>();
	

	// Construct GUI
	m_render = new cPrimaryRenderer(m_renderpanel, m_glContext, m_selectionGrid);
	m_rendersizer->Add(m_render, 1, wxEXPAND, 5);
	m_rendersizer->Layout();

	

	//for (int i = 0; i < 20; i++)
	//{
	//	cLayerSelectPanel* pnl = new cLayerSelectPanel(m_panelLayerList);
	//	m_sizerLayerList->Add(pnl, 0, wxEXPAND, 5); // Good

	//}

	// yeah

	m_sizerLayerList->Layout();

	m_render->SetArea(area);
	m_render->SetTileSelector(m_selectTile);

	//m_selectTile->All(layer);

	m_drawTool = DrawingTool::TileDrawSingle;


	// Image Palette Preview
	m_tiledImageViewer = new cTiledResourceViewer(m_panelImages, m_glContext, m_selectionGrid);
	m_sizerImagePreview->Add(m_tiledImageViewer, 1, wxEXPAND, 5);
	m_panelImages->Layout();

	this->Layout();

	Connect(olcEVT_Editor_MouseMove, EditorMouseMoveHandler(cMainFrame::OnEditorMouseMove));
	Connect(olcEVT_Editor_MouseLeftUp, EditorMouseLeftUpHandler(cMainFrame::OnEditorMouseLeftUp));
	Connect(olcEVT_Editor_MouseLeftDown, EditorMouseLeftDownHandler(cMainFrame::OnEditorMouseLeftDown));
	Connect(olcEVT_Layer_SelectionChange, EditorLayerSelectHandler(cMainFrame::OnLayerSelectionChanged));
	

	

}

cMainFrame::~cMainFrame()
{
	Disconnect(olcEVT_Editor_MouseMove, EditorMouseMoveHandler(cMainFrame::OnEditorMouseMove));
	Disconnect(olcEVT_Editor_MouseLeftUp, EditorMouseLeftUpHandler(cMainFrame::OnEditorMouseLeftUp));
	Disconnect(olcEVT_Editor_MouseLeftDown, EditorMouseLeftDownHandler(cMainFrame::OnEditorMouseLeftDown));
	Disconnect(olcEVT_Layer_SelectionChange, EditorLayerSelectHandler(cMainFrame::OnLayerSelectionChanged));
}


void cMainFrame::OnEditorMouseMove(cEditorMouseEvent& evt)
{
	//m_status->SetStatusText(wxString::Format("Tile: %d, %d", evt.GetTile().x, evt.GetTile().y), 0);
	//m_status->SetStatusText(wxString::Format("Pixel: %d, %d", evt.GetPixel().x, evt.GetPixel().y), 1);
	//m_status->SetStatusText(wxString::Format("World: %f, %f", evt.GetWorld().x, evt.GetWorld().y), 2);	

	if (m_bLeftMouseDrag)
	{
		if (m_layerSelected->GetContentType() == ContentType::Tiles)
		{
			if (m_layerSelected->GetType() == LayerType::Boolean)
			{
				auto layer = std::dynamic_pointer_cast<cLayer_Boolean>(m_layerSelected);

				if (m_drawTool == DrawingTool::TileSelectRegion)
				{
					m_vTileRegionBR = layer->TileCoord(evt.GetWorld());
					m_render->SetTileRegion(m_vTileRegionTL, m_vTileRegionBR);
				}

				if (m_drawTool == DrawingTool::TileDrawSingle)
				{
					if (m_selectTile->InSelection(layer, layer->TileCoord(evt.GetWorld())))
					{
						layer->GetTile(layer->TileCoord(evt.GetWorld())) = 1;
					}
				}
			}

			if (m_layerSelected->GetType() == LayerType::Tile)
			{
				auto layer = std::dynamic_pointer_cast<cLayer_Tile>(m_layerSelected);

				if (m_drawTool == DrawingTool::TileSelectRegion)
				{
					m_vTileRegionBR = layer->TileCoord(evt.GetWorld());
					m_render->SetTileRegion(m_vTileRegionTL, m_vTileRegionBR);
				}

				if (m_drawTool == DrawingTool::TileDrawSingle)
				{
					for (const auto& cell : m_selectionGrid->setSelected)
					{
						olc::vi2d vTilePos = layer->TileCoord(evt.GetWorld());
						olc::vi2d vOffsetFromRoot = cell - m_selectionGrid->vRoot;
						olc::vi2d vWorldCell = vTilePos + vOffsetFromRoot;
						if (m_selectTile->InSelection(layer, vWorldCell)) // mask
						{
							layer->GetTile(vWorldCell) = m_vecImageResources[m_lbImages->GetSelection()]->GetTileDesc(cell);
							layer->GetTile(vWorldCell).exist = true;
						}
					}
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
		if (m_layerSelected->GetType() == LayerType::Boolean)
		{
			auto layer = std::dynamic_pointer_cast<cLayer_Boolean>(m_layerSelected);

			if (m_drawTool == DrawingTool::TileSelectRegion)
			{
				m_vTileRegionBR = layer->TileCoord(evt.GetWorld());
				m_render->SetTileRegion(m_vTileRegionTL, m_vTileRegionBR);
				m_selectTile->Region(layer, m_vTileRegionTL, m_vTileRegionBR);
			}
		}

		if (m_layerSelected->GetType() == LayerType::Tile)
		{
			auto layer = std::dynamic_pointer_cast<cLayer_Tile>(m_layerSelected);

			if (m_drawTool == DrawingTool::TileSelectRegion)
			{
				m_vTileRegionBR = layer->TileCoord(evt.GetWorld());
				m_render->SetTileRegion(m_vTileRegionTL, m_vTileRegionBR);
				m_selectTile->Region(layer, m_vTileRegionTL, m_vTileRegionBR);
			}
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
		if (m_layerSelected->GetType() == LayerType::Boolean)
		{
			auto layer = std::dynamic_pointer_cast<cLayer_Boolean>(m_layerSelected);

			if (m_drawTool == DrawingTool::TileSelectRegion)
			{
				m_vTileRegionTL = layer->TileCoord(evt.GetWorld());
				m_vTileRegionBR = layer->TileCoord(evt.GetWorld());
				m_render->SetTileRegion(m_vTileRegionTL, m_vTileRegionBR);
				m_render->EnableRegionMode(true);
				if (!evt.GetControlHeld())
					m_selectTile->Nothing(layer);
			}

			if (m_drawTool == DrawingTool::TileDrawSingle)
			{
				if (m_selectTile->InSelection(layer, layer->TileCoord(evt.GetWorld())))
				{
					layer->GetTile(layer->TileCoord(evt.GetWorld())) = 1;
				}
			}
		}

		if (m_layerSelected->GetType() == LayerType::Tile)
		{
			auto layer = std::dynamic_pointer_cast<cLayer_Tile>(m_layerSelected);

			if (m_drawTool == DrawingTool::TileSelectRegion)
			{
				m_vTileRegionTL = layer->TileCoord(evt.GetWorld());
				m_vTileRegionBR = layer->TileCoord(evt.GetWorld());
				m_render->SetTileRegion(m_vTileRegionTL, m_vTileRegionBR);
				m_render->EnableRegionMode(true);
				if (!evt.GetControlHeld())
					m_selectTile->Nothing(layer);
			}

			if (m_drawTool == DrawingTool::TileDrawSingle)
			{				
				for (const auto& cell : m_selectionGrid->setSelected)
				{
					olc::vi2d vTilePos = layer->TileCoord(evt.GetWorld());
					olc::vi2d vOffsetFromRoot = cell - m_selectionGrid->vRoot;
					olc::vi2d vWorldCell = vTilePos + vOffsetFromRoot;
					if (m_selectTile->InSelection(layer, vWorldCell)) // mask
					{
						layer->GetTile(vWorldCell) = m_vecImageResources[m_lbImages->GetSelection()]->GetTileDesc(cell);	
						layer->GetTile(vWorldCell).exist = true;
					}
				}
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
			m_selectTile->Nothing(std::dynamic_pointer_cast<cTiledLayer>(m_layerSelected));
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
		m_lbImages->Select(m_lbImages->GetCount()-1);
		m_lbImages->EnsureVisible(m_lbImages->GetCount() - 1);
		m_tiledImageViewer->SetImageResource(m_vecImageResources[m_lbImages->GetCount() - 1]);
		m_render->SetSelectedImageResource(m_vecImageResources[m_lbImages->GetCount() - 1]);
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
	m_render->SetSelectedImageResource(m_vecImageResources[evt.GetSelection()]);
}



void cMainFrame::UpdateLayerList()
{
	// 1) Clear panel
	m_sizerLayerList->Clear(true);

	// 2) Repopulate
	for (auto& layer : area->vecLayers)
	{
		cLayerSelectPanel* pnl = new cLayerSelectPanel(m_panelLayerList, layer);
		m_sizerLayerList->Add(pnl, 0, wxEXPAND, 5);
	}

	m_panelLayerList->Layout();
	


	/*m_listLayers->Clear();
	for (auto& layer : area->vecLayers)
		m_listLayers->AppendString(layer->GetName());

	int idx = std::distance(area->vecLayers.begin(), std::find(area->vecLayers.begin(), area->vecLayers.end(), m_layerSelected));
	m_listLayers->Select(idx);
	m_listLayers->EnsureVisible(idx);*/
}

void cMainFrame::OnButtonAddLayer(wxCommandEvent& evt)
{
	// Mystery Code!

	// You can ask!

	// Always speack to your profs/line managers
	// be open with them
	// it shows you are actually invested in the issue

	//"Basic Tile" "Geometry" "Boolean" "Integer" "Float" "Character"
	int n = m_choiceLayerType->GetSelection();
	switch (n)
	{
	case 0:
	{
		for (auto& l : area->vecLayers)	if (l) l->SetSelected(false);

		auto layer = std::make_shared<cLayer_Tile>("Tiled Layer", m_vecImageResources);
		layer->SetLayerSize({ 64, 64 });
		area->vecLayers.push_back(layer);
		m_layerSelected = layer;
		m_render->SetSelectedLayer(m_layerSelected);
		m_selectTile->All(layer);		
		m_layerSelected->SetSelected(true);		
		UpdateLayerList();
	}
	break;

	}


	
}

void cMainFrame::OnButtonEraseLayer(wxCommandEvent& evt)
{
}

void cMainFrame::OnButtonDuplicateLayer(wxCommandEvent& evt)
{
}

void cMainFrame::OnButtonLayerMoveUp(wxCommandEvent& evt)
{
	int d = std::distance(area->vecLayers.begin(), std::find(area->vecLayers.begin(), area->vecLayers.end(), m_layerSelected));

	if (d > 0)
	{
		std::swap(area->vecLayers[d], area->vecLayers[d - 1]);
		UpdateLayerList();
		m_render->Refresh();
	}	
}

void cMainFrame::OnButtonLayerMoveDown(wxCommandEvent& evt)
{
	int d = std::distance(area->vecLayers.begin(), std::find(area->vecLayers.begin(), area->vecLayers.end(), m_layerSelected));

	if (d < area->vecLayers.size() - 1)
	{
		std::swap(area->vecLayers[d], area->vecLayers[d + 1]);
		UpdateLayerList();
		m_render->Refresh();
	}
}

void cMainFrame::OnLayerSelectionChanged(cLayerChangeEvent& evt)
{
	// Unset all layers
	for(auto& l : area->vecLayers)
		if (l) l->SetSelected(false);

	// Set new layer
	m_layerSelected = evt.GetLayer();
	m_layerSelected->SetSelected(true);
	m_render->SetSelectedLayer(m_layerSelected);
	m_render->Refresh();

	// Brute force
	UpdateLayerList();
}


