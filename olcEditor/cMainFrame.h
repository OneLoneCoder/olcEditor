#pragma once

#include <wx/wx.h>

#include "BaseGUI.h"

#include "cMasterContext.h"
#include "cPrimaryRenderer.h"
#include "cArea.h"
#include "cTileSelection.h"
#include "cGridSelection.h"
#include "cImageResourceEditor.h"
#include "cTiledResourceViewer.h"
#include "cLayer_Boolean.h"
#include "cLayer_Tile.h"

class cMainFrame : public MainFrameBase
{
public:
	cMainFrame();
	virtual ~cMainFrame();

protected:
	cPrimaryRenderer* m_render = nullptr;

	std::shared_ptr<cArea> area = nullptr;
	std::shared_ptr<cLayer> m_layerSelected = nullptr;
	std::shared_ptr<cTileSelection> m_selectTile = nullptr;
	bool m_bLeftMouseDrag = false;

	DrawingTool m_drawTool = DrawingTool::TileDrawSingle;
	olc::vi2d m_vTileRegionTL = { 0,0 };
	olc::vi2d m_vTileRegionBR = { 0,0 };

	std::vector<std::shared_ptr<cImageResource>> m_vecImageResources;

	cMasterContext* m_glMasterContext = nullptr;
	wxGLContext* m_glContext = nullptr;

	std::shared_ptr<cGridSelection> m_selectionGrid = nullptr;
	cTiledResourceViewer* m_tiledImageViewer;

protected:
	void UpdateImageList();
	void UpdateLayerList();
	

protected:
	void OnEditorMouseMove(cEditorMouseEvent& evt);
	void OnEditorMouseLeftUp(cEditorMouseEvent& evt);
	void OnEditorMouseLeftDown(cEditorMouseEvent& evt);

	void OnButtonSelectClear(wxCommandEvent& evt) override;
	void OnButtonSelectRegion(wxCommandEvent& evt) override;
	void OnButtonSelectMove(wxCommandEvent& evt) override;
	void OnButtonSelectFill(wxCommandEvent& evt) override;

	void OnButtonTileDraw(wxCommandEvent& evt) override;
	void OnButtonTileLine(wxCommandEvent& evt) override;
	void OnButtonTileDrawRect(wxCommandEvent& evt) override;
	void OnButtonTileFillRect(wxCommandEvent& evt) override;
	void OnButtonTileDrawCircle(wxCommandEvent& evt) override;
	void OnButtonTileFillCircle(wxCommandEvent& evt) override;
	void OnButtonTileFloodFill(wxCommandEvent& evt) override;

	void OnAddImage(wxCommandEvent& evt) override;
	void OnEraseImage(wxCommandEvent& evt) override;
	void OnEditImage(wxCommandEvent& evt) override;
	void OnImageSelectChange(wxCommandEvent& evt) override;

	// Layer Manipulation
	void OnButtonAddLayer(wxCommandEvent& evt) override;
	void OnButtonEraseLayer(wxCommandEvent& evt) override;
	void OnButtonDuplicateLayer(wxCommandEvent& evt) override;
	void OnButtonLayerMoveUp(wxCommandEvent& evt) override;
	void OnButtonLayerMoveDown(wxCommandEvent& evt) override;
	void OnLayerSelectionChanged(wxCommandEvent& evt) override;

};	

