#pragma once

#include <wx/wx.h>

#include "BaseGUI.h"

#include "cMasterContext.h"
#include "cPrimaryRenderer.h"
#include "cArea.h"
#include "cTileSelection.h"
#include "cImageResourceEditor.h"
#include "cTiledResourceViewer.h"

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

	DrawingTool m_drawTool = DrawingTool::TileSelectRegion;
	olc::vi2d m_vTileRegionTL = { 0,0 };
	olc::vi2d m_vTileRegionBR = { 0,0 };

	std::vector<std::shared_ptr<cImageResource>> m_vecImageResources;

	cMasterContext* m_glMasterContext = nullptr;
	wxGLContext* m_glContext = nullptr;
	

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
};	

