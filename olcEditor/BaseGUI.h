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
		wxBitmapButton* m_bpButton1;
		wxBitmapButton* m_bpButton2;
		wxBitmapButton* m_bpButton3;
		wxBitmapButton* m_bpButton5;
		wxStaticLine* m_staticline1;
		wxBitmapButton* m_bpButton6;
		wxBitmapButton* m_bpButton7;
		wxBitmapButton* m_bpButton8;
		wxBitmapButton* m_bpButton9;
		wxBitmapButton* m_bpButton10;
		wxBitmapButton* m_bpButton11;
		wxBitmapButton* m_bpButton12;
		wxPanel* m_panel5;
		wxBoxSizer* m_mainsizer;
		wxSplitterWindow* m_splitter;
		wxPanel* m_propspanel;
		wxPanel* m_panel1;
		wxListCtrl* m_listCtrl1;
		wxBitmapButton* m_bpButton13;
		wxBitmapButton* m_bpButton14;
		wxBitmapButton* m_bpButton15;
		wxBitmapButton* m_bpButton16;
		wxBitmapButton* m_bpButton17;
		wxStaticLine* m_staticline2;
		wxPropertyGrid* m_propertyGrid1;
		wxPGProperty* m_propertyGridItem1;
		wxPGProperty* m_propertyGridItem2;
		wxPGProperty* m_propertyGridItem3;
		wxPGProperty* m_propertyGridItem4;
		wxStaticLine* m_staticline3;
		wxPanel* m_panel8;
		wxPanel* m_renderpanel;
		wxBoxSizer* m_rendersizer;

	public:

		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("OneLoneCoder - Editor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 854,610 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrameBase();

		void m_splitterOnIdle( wxIdleEvent& )
		{
			m_splitter->SetSashPosition( 200 );
			m_splitter->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrameBase::m_splitterOnIdle ), NULL, this );
		}

};

