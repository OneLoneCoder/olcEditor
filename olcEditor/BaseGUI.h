///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/statusbr.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/menu.h>
#include <wx/bmpbuttn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/listctrl.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/splitter.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame
{
	private:

	protected:
		wxStatusBar* m_status;
		wxMenuBar* m_menubar1;
		wxMenu* m_menuFile;
		wxNotebook* m_toolbar;
		wxPanel* m_toolsBoolean;
		wxBitmapButton* m_btnBooleanClearSelection;
		wxBitmapButton* m_btnBooleanSelection;
		wxBitmapButton* m_btnBooleanMoveSelection;
		wxBitmapButton* m_btnBooleanFillSelection;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_btnTileDraw;
		wxBitmapButton* m_btnTileDrawLine;
		wxBitmapButton* m_btnTileDrawRect;
		wxBitmapButton* m_btnTileFillRect;
		wxBitmapButton* m_btnTileDrawCircle;
		wxBitmapButton* m_btnTileFillCircle;
		wxBitmapButton* m_btnTileFloodFill;
		wxPanel* m_panel5;
		wxBoxSizer* m_mainsizer;
		wxSplitterWindow* m_splitter;
		wxPanel* m_propspanel;
		wxPanel* m_panel1;
		wxListCtrl* m_listLayers;
		wxBitmapButton* m_btnAddLayer;
		wxBitmapButton* m_btnEraseLayer;
		wxBitmapButton* m_btnDuplicateLayer;
		wxBitmapButton* m_btnLayerMoveUp;
		wxBitmapButton* m_btnLayerMoveDown;
		wxStaticLine* m_staticline2;
		wxPropertyGrid* m_propLayer;
		wxStaticLine* m_staticline3;
		wxNotebook* m_nbPalette;
		wxPanel* m_renderpanel;
		wxBoxSizer* m_rendersizer;

		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonSelectClear( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSelectRegion( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSelectMove( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSelectFill( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonTileDraw( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonTileLine( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonTileDrawRect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonTileFillRect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonTileDrawCircle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonTileFillCircle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonTileFloodFill( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("OneLoneCoder - Editor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 854,610 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrameBase();

		void m_splitterOnIdle( wxIdleEvent& )
		{
			m_splitter->SetSashPosition( 200 );
			m_splitter->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrameBase::m_splitterOnIdle ), NULL, this );
		}

};

