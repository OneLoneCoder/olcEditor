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
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/listctrl.h>
#include <wx/listbox.h>
#include <wx/splitter.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/filepicker.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/dialog.h>

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
		wxCheckBox* m_checkBox1;
		wxPanel* m_panel5;
		wxBoxSizer* m_mainsizer;
		wxSplitterWindow* m_splitter;
		wxPanel* m_propspanel;
		wxSplitterWindow* m_splitter2;
		wxPanel* m_panel1;
		wxListCtrl* m_listLayers;
		wxBitmapButton* m_btnAddLayer;
		wxBitmapButton* m_btnEraseLayer;
		wxBitmapButton* m_btnDuplicateLayer;
		wxBitmapButton* m_btnLayerMoveUp;
		wxBitmapButton* m_btnLayerMoveDown;
		wxStaticLine* m_staticline2;
		wxPanel* m_panel8;
		wxStaticLine* m_staticline4;
		wxNotebook* m_nbPalette;
		wxPanel* m_panel6;
		wxBitmapButton* m_bpButton17;
		wxBitmapButton* m_bpButton18;
		wxBitmapButton* m_bpButton19;
		wxPanel* m_panelImages;
		wxBoxSizer* m_sizerImagePreview;
		wxListBox* m_lbImages;
		wxBitmapButton* m_btnAddImage;
		wxBitmapButton* m_btnEraseImage;
		wxButton* m_btnEditImageResource;
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
		virtual void OnImageSelectChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddImage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEraseImage( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditImage( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("OneLoneCoder - Editor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 854,610 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrameBase();

		void m_splitterOnIdle( wxIdleEvent& )
		{
			m_splitter->SetSashPosition( 200 );
			m_splitter->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrameBase::m_splitterOnIdle ), NULL, this );
		}

		void m_splitter2OnIdle( wxIdleEvent& )
		{
			m_splitter2->SetSashPosition( 200 );
			m_splitter2->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrameBase::m_splitter2OnIdle ), NULL, this );
		}

};

///////////////////////////////////////////////////////////////////////////////
/// Class ImageResourceEditorBase
///////////////////////////////////////////////////////////////////////////////
class ImageResourceEditorBase : public wxDialog
{
	private:

	protected:
		wxTextCtrl* m_txtFriendlyName;
		wxFilePickerCtrl* m_txtFileName;
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText1;
		wxSpinCtrl* m_tileWidth;
		wxStaticText* m_staticText2;
		wxSpinCtrl* m_tileHeight;
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText11;
		wxSpinCtrl* m_offsetLeft;
		wxStaticText* m_staticText21;
		wxSpinCtrl* m_offsetTop;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxSpinCtrl* m_spaceHorizontal;
		wxStaticText* m_staticText111;
		wxSpinCtrl* m_spaceVertical;
		wxButton* m_button1;
		wxButton* m_button2;
		wxStaticBoxSizer* m_imageSizer;

		// Virtual event handlers, overide them in your derived class
		virtual void OnFileSourceChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void OnGridUpdate( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnButtonOK( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonCancel( wxCommandEvent& event ) { event.Skip(); }


	public:

		ImageResourceEditorBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Image Resource Properties"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1010,572 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ImageResourceEditorBase();

};

