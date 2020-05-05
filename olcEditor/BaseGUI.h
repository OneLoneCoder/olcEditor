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
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/notebook.h>
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
		wxNotebook* m_notebook1;
		wxPanel* m_panel3;
		wxButton* m_button3;
		wxButton* m_button4;
		wxButton* m_button5;
		wxButton* m_button6;
		wxButton* m_button7;
		wxButton* m_button8;
		wxButton* m_button9;
		wxButton* m_button10;
		wxPanel* m_panel4;
		wxPanel* m_panel5;
		wxBoxSizer* m_mainsizer;
		wxSplitterWindow* m_splitter;
		wxPanel* m_propspanel;
		wxPanel* m_panel1;
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

