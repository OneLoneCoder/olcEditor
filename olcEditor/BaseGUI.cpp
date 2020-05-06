///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BaseGUI.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_status = this->CreateStatusBar( 3, wxSTB_DEFAULT_STYLE|wxSTB_SIZEGRIP, wxID_ANY );
	m_menubar1 = new wxMenuBar( 0 );
	m_menuFile = new wxMenu();
	m_menubar1->Append( m_menuFile, wxT("File") );

	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_toolbar = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FIXEDWIDTH|wxNB_TOP );
	m_toolsBoolean = new wxPanel( m_toolbar, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_btnBooleanClearSelection = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnBooleanClearSelection->SetBitmap( wxBitmap( wxT("gfx/ico_select_clear.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_btnBooleanClearSelection, 0, wxALL, 5 );

	m_btnBooleanSelection = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnBooleanSelection->SetBitmap( wxBitmap( wxT("gfx/ico_select.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_btnBooleanSelection, 0, wxALL, 5 );

	m_btnBooleanMoveSelection = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnBooleanMoveSelection->SetBitmap( wxBitmap( wxT("gfx/ico_select_move.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_btnBooleanMoveSelection, 0, wxALL, 5 );

	m_btnBooleanFillSelection = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnBooleanFillSelection->SetBitmap( wxBitmap( wxT("gfx/ico_select_fill.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_btnBooleanFillSelection, 0, wxALL, 5 );

	m_staticline1 = new wxStaticLine( m_toolsBoolean, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer7->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	m_btnTileDraw = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnTileDraw->SetBitmap( wxBitmap( wxT("gfx/ico_draw_one.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_btnTileDraw, 0, wxALL, 5 );

	m_btnTileDrawLine = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnTileDrawLine->SetBitmap( wxBitmap( wxT("gfx/ico_draw_line.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_btnTileDrawLine, 0, wxALL, 5 );

	m_btnTileDrawRect = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnTileDrawRect->SetBitmap( wxBitmap( wxT("gfx/ico_draw_rect.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_btnTileDrawRect, 0, wxALL, 5 );

	m_btnTileFillRect = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnTileFillRect->SetBitmap( wxBitmap( wxT("gfx/ico_fill_rect.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_btnTileFillRect, 0, wxALL, 5 );

	m_btnTileDrawCircle = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnTileDrawCircle->SetBitmap( wxBitmap( wxT("gfx/ico_draw_circle.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_btnTileDrawCircle, 0, wxALL, 5 );

	m_btnTileFillCircle = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnTileFillCircle->SetBitmap( wxBitmap( wxT("gfx/ico_fill_circle.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_btnTileFillCircle, 0, wxALL, 5 );

	m_btnTileFloodFill = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnTileFloodFill->SetBitmap( wxBitmap( wxT("gfx/ico_draw_fill.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_btnTileFloodFill, 0, wxALL, 5 );


	m_toolsBoolean->SetSizer( bSizer7 );
	m_toolsBoolean->Layout();
	bSizer7->Fit( m_toolsBoolean );
	m_toolbar->AddPage( m_toolsBoolean, wxT("Boolean Layer"), true );
	m_panel5 = new wxPanel( m_toolbar, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_toolbar->AddPage( m_panel5, wxT("a page"), false );

	bSizer4->Add( m_toolbar, 0, wxEXPAND, 5 );

	m_mainsizer = new wxBoxSizer( wxHORIZONTAL );

	m_splitter = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_LIVE_UPDATE );
	m_splitter->SetSashGravity( 0 );
	m_splitter->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrameBase::m_splitterOnIdle ), NULL, this );

	m_propspanel = new wxPanel( m_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_panel1 = new wxPanel( m_propspanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_listLayers = new wxListCtrl( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT );
	bSizer3->Add( m_listLayers, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_btnAddLayer = new wxBitmapButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnAddLayer->SetBitmap( wxBitmap( wxT("gfx/ico_layer_add.png"), wxBITMAP_TYPE_ANY ) );
	bSizer10->Add( m_btnAddLayer, 0, wxALL, 5 );

	m_btnEraseLayer = new wxBitmapButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnEraseLayer->SetBitmap( wxBitmap( wxT("gfx/ico_layer_erase.png"), wxBITMAP_TYPE_ANY ) );
	bSizer10->Add( m_btnEraseLayer, 0, wxALL, 5 );

	m_btnDuplicateLayer = new wxBitmapButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnDuplicateLayer->SetBitmap( wxBitmap( wxT("gfx/ico_layer_duplicate.png"), wxBITMAP_TYPE_ANY ) );
	bSizer10->Add( m_btnDuplicateLayer, 0, wxALL, 5 );

	m_btnLayerMoveUp = new wxBitmapButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnLayerMoveUp->SetBitmap( wxBitmap( wxT("gfx/ico_layer_moveup.png"), wxBITMAP_TYPE_ANY ) );
	bSizer10->Add( m_btnLayerMoveUp, 0, wxALL, 5 );

	m_btnLayerMoveDown = new wxBitmapButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnLayerMoveDown->SetBitmap( wxBitmap( wxT("gfx/ico_layer_movedown.png"), wxBITMAP_TYPE_ANY ) );
	bSizer10->Add( m_btnLayerMoveDown, 0, wxALL, 5 );


	bSizer3->Add( bSizer10, 0, wxEXPAND, 5 );

	m_staticline2 = new wxStaticLine( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	m_propLayer = new wxPropertyGrid(m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_DEFAULT_STYLE);
	bSizer3->Add( m_propLayer, 0, wxALL|wxEXPAND, 5 );

	m_staticline3 = new wxStaticLine( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );

	m_nbPalette = new wxNotebook( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	bSizer3->Add( m_nbPalette, 1, wxEXPAND | wxALL, 5 );


	m_panel1->SetSizer( bSizer3 );
	m_panel1->Layout();
	bSizer3->Fit( m_panel1 );
	bSizer2->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );


	m_propspanel->SetSizer( bSizer2 );
	m_propspanel->Layout();
	bSizer2->Fit( m_propspanel );
	m_renderpanel = new wxPanel( m_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	m_rendersizer = new wxBoxSizer( wxVERTICAL );


	m_renderpanel->SetSizer( m_rendersizer );
	m_renderpanel->Layout();
	m_rendersizer->Fit( m_renderpanel );
	m_splitter->SplitVertically( m_propspanel, m_renderpanel, 200 );
	m_mainsizer->Add( m_splitter, 1, wxEXPAND, 5 );


	bSizer4->Add( m_mainsizer, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_btnBooleanClearSelection->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonSelectClear ), NULL, this );
	m_btnBooleanSelection->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonSelectRegion ), NULL, this );
	m_btnBooleanMoveSelection->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonSelectMove ), NULL, this );
	m_btnBooleanFillSelection->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonSelectFill ), NULL, this );
	m_btnTileDraw->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonTileDraw ), NULL, this );
	m_btnTileDrawLine->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonTileLine ), NULL, this );
	m_btnTileDrawRect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonTileDrawRect ), NULL, this );
	m_btnTileFillRect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonTileFillRect ), NULL, this );
	m_btnTileDrawCircle->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonTileDrawCircle ), NULL, this );
	m_btnTileFillCircle->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonTileFillCircle ), NULL, this );
	m_btnTileFloodFill->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonTileFloodFill ), NULL, this );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	m_btnBooleanClearSelection->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonSelectClear ), NULL, this );
	m_btnBooleanSelection->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonSelectRegion ), NULL, this );
	m_btnBooleanMoveSelection->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonSelectMove ), NULL, this );
	m_btnBooleanFillSelection->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonSelectFill ), NULL, this );
	m_btnTileDraw->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonTileDraw ), NULL, this );
	m_btnTileDrawLine->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonTileLine ), NULL, this );
	m_btnTileDrawRect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonTileDrawRect ), NULL, this );
	m_btnTileFillRect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonTileFillRect ), NULL, this );
	m_btnTileDrawCircle->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonTileDrawCircle ), NULL, this );
	m_btnTileFillCircle->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonTileFillCircle ), NULL, this );
	m_btnTileFloodFill->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonTileFloodFill ), NULL, this );

}
