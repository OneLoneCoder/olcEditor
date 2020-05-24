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

	m_mainsizer = new wxBoxSizer( wxHORIZONTAL );

	m_splitter = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_LIVE_UPDATE );
	m_splitter->SetSashGravity( 0 );
	m_splitter->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrameBase::m_splitterOnIdle ), NULL, this );
	m_splitter->SetMinimumPaneSize( 300 );

	m_propspanel = new wxPanel( m_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_splitter2 = new wxSplitterWindow( m_propspanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3DSASH|wxSP_BORDER|wxSP_LIVE_UPDATE );
	m_splitter2->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrameBase::m_splitter2OnIdle ), NULL, this );
	m_splitter2->SetMinimumPaneSize( 200 );

	m_panel1 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_panelLayerList = new wxScrolledWindow( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxALWAYS_SHOW_SB|wxFULL_REPAINT_ON_RESIZE|wxVSCROLL );
	m_panelLayerList->SetScrollRate( 5, 5 );
	m_panelLayerList->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	m_sizerLayerList = new wxBoxSizer( wxVERTICAL );


	m_panelLayerList->SetSizer( m_sizerLayerList );
	m_panelLayerList->Layout();
	m_sizerLayerList->Fit( m_panelLayerList );
	bSizer3->Add( m_panelLayerList, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	wxString m_choiceLayerTypeChoices[] = { wxT("Basic Tile"), wxT("Geometry"), wxT("Boolean"), wxT("Integer"), wxT("Float"), wxT("Character") };
	int m_choiceLayerTypeNChoices = sizeof( m_choiceLayerTypeChoices ) / sizeof( wxString );
	m_choiceLayerType = new wxChoice( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceLayerTypeNChoices, m_choiceLayerTypeChoices, 0 );
	m_choiceLayerType->SetSelection( 0 );
	bSizer10->Add( m_choiceLayerType, 0, wxALL, 5 );

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


	m_panel1->SetSizer( bSizer3 );
	m_panel1->Layout();
	bSizer3->Fit( m_panel1 );
	m_panel8 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	m_staticline4 = new wxStaticLine( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer12->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );

	m_nbPalette = new wxNotebook( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_TOP );
	m_panel6 = new wxPanel( m_nbPalette, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_bpButton17 = new wxBitmapButton( m_panel6, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton17->SetBitmap( wxBitmap( wxT("gfx/ico_boolean_true.png"), wxBITMAP_TYPE_ANY ) );
	bSizer8->Add( m_bpButton17, 0, wxALL, 5 );

	m_bpButton18 = new wxBitmapButton( m_panel6, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton18->SetBitmap( wxBitmap( wxT("gfx/ico_boolean_false.png"), wxBITMAP_TYPE_ANY ) );
	bSizer8->Add( m_bpButton18, 0, wxALL, 5 );

	m_bpButton19 = new wxBitmapButton( m_panel6, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton19->SetBitmap( wxBitmap( wxT("gfx/ico_boolean_xor.png"), wxBITMAP_TYPE_ANY ) );
	bSizer8->Add( m_bpButton19, 0, wxALL, 5 );


	m_panel6->SetSizer( bSizer8 );
	m_panel6->Layout();
	bSizer8->Fit( m_panel6 );
	m_nbPalette->AddPage( m_panel6, wxT("Boolean"), false );
	m_panelImages = new wxPanel( m_nbPalette, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_sizerImagePreview = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	m_lbImages = new wxListBox( m_panelImages, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer15->Add( m_lbImages, 1, wxEXPAND|wxALL, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );

	m_btnAddImage = new wxBitmapButton( m_panelImages, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnAddImage->SetBitmap( wxBitmap( wxT("gfx/ico_layer_add.png"), wxBITMAP_TYPE_ANY ) );
	bSizer16->Add( m_btnAddImage, 0, wxALL, 5 );

	m_btnEraseImage = new wxBitmapButton( m_panelImages, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_btnEraseImage->SetBitmap( wxBitmap( wxT("gfx/ico_layer_erase.png"), wxBITMAP_TYPE_ANY ) );
	bSizer16->Add( m_btnEraseImage, 0, wxALL, 5 );


	bSizer15->Add( bSizer16, 0, 0, 5 );

	m_btnEditImageResource = new wxButton( m_panelImages, wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer15->Add( m_btnEditImageResource, 0, wxALL|wxEXPAND, 5 );


	m_sizerImagePreview->Add( bSizer15, 0, wxEXPAND, 5 );


	m_panelImages->SetSizer( m_sizerImagePreview );
	m_panelImages->Layout();
	m_sizerImagePreview->Fit( m_panelImages );
	m_nbPalette->AddPage( m_panelImages, wxT("Images"), true );

	bSizer12->Add( m_nbPalette, 1, wxALL|wxEXPAND, 5 );


	m_panel8->SetSizer( bSizer12 );
	m_panel8->Layout();
	bSizer12->Fit( m_panel8 );
	m_splitter2->SplitHorizontally( m_panel1, m_panel8, 200 );
	bSizer2->Add( m_splitter2, 1, wxEXPAND, 5 );


	m_propspanel->SetSizer( bSizer2 );
	m_propspanel->Layout();
	bSizer2->Fit( m_propspanel );
	m_renderpanel = new wxPanel( m_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN|wxTAB_TRAVERSAL );
	m_rendersizer = new wxBoxSizer( wxVERTICAL );

	m_toolbar = new wxNotebook( m_renderpanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FIXEDWIDTH|wxNB_TOP );
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

	m_checkBox1 = new wxCheckBox( m_toolsBoolean, wxID_ANY, wxT("Contiguous"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox1->SetValue(true);
	bSizer7->Add( m_checkBox1, 0, wxALL, 5 );


	m_toolsBoolean->SetSizer( bSizer7 );
	m_toolsBoolean->Layout();
	bSizer7->Fit( m_toolsBoolean );
	m_toolbar->AddPage( m_toolsBoolean, wxT("Boolean Layer"), true );
	m_panel5 = new wxPanel( m_toolbar, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_toolbar->AddPage( m_panel5, wxT("a page"), false );

	m_rendersizer->Add( m_toolbar, 0, wxEXPAND, 5 );


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
	m_btnAddLayer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonAddLayer ), NULL, this );
	m_btnEraseLayer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonEraseLayer ), NULL, this );
	m_btnDuplicateLayer->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonDuplicateLayer ), NULL, this );
	m_btnLayerMoveUp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonLayerMoveUp ), NULL, this );
	m_btnLayerMoveDown->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonLayerMoveDown ), NULL, this );
	m_lbImages->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( MainFrameBase::OnImageSelectChange ), NULL, this );
	m_btnAddImage->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnAddImage ), NULL, this );
	m_btnEraseImage->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnEraseImage ), NULL, this );
	m_btnEditImageResource->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnEditImage ), NULL, this );
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
	m_btnAddLayer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonAddLayer ), NULL, this );
	m_btnEraseLayer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonEraseLayer ), NULL, this );
	m_btnDuplicateLayer->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonDuplicateLayer ), NULL, this );
	m_btnLayerMoveUp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonLayerMoveUp ), NULL, this );
	m_btnLayerMoveDown->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnButtonLayerMoveDown ), NULL, this );
	m_lbImages->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( MainFrameBase::OnImageSelectChange ), NULL, this );
	m_btnAddImage->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnAddImage ), NULL, this );
	m_btnEraseImage->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnEraseImage ), NULL, this );
	m_btnEditImageResource->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnEditImage ), NULL, this );
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

ImageResourceEditorBase::ImageResourceEditorBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Friendly Name:") ), wxVERTICAL );

	m_txtFriendlyName = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( m_txtFriendlyName, 0, wxALL|wxEXPAND, 5 );


	bSizer10->Add( sbSizer4, 0, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Image File:") ), wxVERTICAL );

	m_txtFileName = new wxFilePickerCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxEmptyString, wxT("Select an image source"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_FILE_MUST_EXIST|wxFLP_OPEN );
	sbSizer2->Add( m_txtFileName, 0, wxALL|wxEXPAND, 5 );


	bSizer10->Add( sbSizer2, 0, wxEXPAND|wxALL, 5 );

	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Grid Properties:") ), wxHORIZONTAL );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->AddGrowableCol( 3 );
	fgSizer1->SetFlexibleDirection( wxHORIZONTAL );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText7 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Tile Size:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALL, 5 );

	m_staticText1 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer1->Add( m_staticText1, 0, wxALL, 5 );

	m_tileWidth = new wxSpinCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 4096, 16 );
	fgSizer1->Add( m_tileWidth, 0, wxALL, 5 );

	m_staticText2 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Height:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer1->Add( m_staticText2, 0, wxALL, 5 );

	m_tileHeight = new wxSpinCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 4096, 16 );
	fgSizer1->Add( m_tileHeight, 0, wxALL, 5 );

	m_staticText8 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Offset:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer1->Add( m_staticText8, 0, wxALL, 5 );

	m_staticText11 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Left:"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE );
	m_staticText11->Wrap( -1 );
	fgSizer1->Add( m_staticText11, 1, wxALL, 5 );

	m_offsetLeft = new wxSpinCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 4096, 0 );
	fgSizer1->Add( m_offsetLeft, 1, wxALL, 5 );

	m_staticText21 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Top:"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE );
	m_staticText21->Wrap( -1 );
	fgSizer1->Add( m_staticText21, 1, wxALL, 5 );

	m_offsetTop = new wxSpinCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 4096, 0 );
	fgSizer1->Add( m_offsetTop, 1, wxALL, 5 );

	m_staticText9 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Spacing:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer1->Add( m_staticText9, 0, wxALL, 5 );

	m_staticText10 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Horizontal:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	fgSizer1->Add( m_staticText10, 0, wxALL, 5 );

	m_spaceHorizontal = new wxSpinCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 4096, 0 );
	fgSizer1->Add( m_spaceHorizontal, 0, wxALL, 5 );

	m_staticText111 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Vertical:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	fgSizer1->Add( m_staticText111, 0, wxALL, 5 );

	m_spaceVertical = new wxSpinCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 4096, 0 );
	fgSizer1->Add( m_spaceVertical, 0, wxALL, 5 );


	sbSizer3->Add( fgSizer1, 1, wxEXPAND, 5 );


	bSizer10->Add( sbSizer3, 0, wxEXPAND|wxALL, 5 );


	bSizer10->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_button1 = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button1, 0, wxALL, 5 );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button2, 0, wxALL, 5 );


	bSizer10->Add( bSizer11, 0, wxEXPAND, 5 );


	bSizer9->Add( bSizer10, 1, wxEXPAND, 5 );

	m_imageSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Preview:") ), wxVERTICAL );


	bSizer9->Add( m_imageSizer, 1, wxEXPAND|wxALL, 5 );


	this->SetSizer( bSizer9 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_txtFileName->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ImageResourceEditorBase::OnFileSourceChanged ), NULL, this );
	m_tileWidth->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImageResourceEditorBase::OnGridUpdate ), NULL, this );
	m_tileHeight->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImageResourceEditorBase::OnGridUpdate ), NULL, this );
	m_offsetLeft->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImageResourceEditorBase::OnGridUpdate ), NULL, this );
	m_offsetTop->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImageResourceEditorBase::OnGridUpdate ), NULL, this );
	m_spaceHorizontal->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImageResourceEditorBase::OnGridUpdate ), NULL, this );
	m_spaceVertical->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImageResourceEditorBase::OnGridUpdate ), NULL, this );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ImageResourceEditorBase::OnButtonOK ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ImageResourceEditorBase::OnButtonCancel ), NULL, this );
}

ImageResourceEditorBase::~ImageResourceEditorBase()
{
	// Disconnect Events
	m_txtFileName->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ImageResourceEditorBase::OnFileSourceChanged ), NULL, this );
	m_tileWidth->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImageResourceEditorBase::OnGridUpdate ), NULL, this );
	m_tileHeight->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImageResourceEditorBase::OnGridUpdate ), NULL, this );
	m_offsetLeft->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImageResourceEditorBase::OnGridUpdate ), NULL, this );
	m_offsetTop->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImageResourceEditorBase::OnGridUpdate ), NULL, this );
	m_spaceHorizontal->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImageResourceEditorBase::OnGridUpdate ), NULL, this );
	m_spaceVertical->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ImageResourceEditorBase::OnGridUpdate ), NULL, this );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ImageResourceEditorBase::OnButtonOK ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ImageResourceEditorBase::OnButtonCancel ), NULL, this );

}

MyPanel1::MyPanel1( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer16->Add( m_staticText10, 1, wxALL|wxEXPAND, 5 );

	m_button5 = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button5, 0, wxALL, 5 );

	m_button6 = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button6, 0, wxALL, 5 );


	this->SetSizer( bSizer16 );
	this->Layout();
}

MyPanel1::~MyPanel1()
{
}

LayerPropertiesBase::LayerPropertiesBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Friendly Name:") ), wxVERTICAL );

	m_txtFriendlyName = new wxTextCtrl( sbSizer6->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer6->Add( m_txtFriendlyName, 0, wxALL|wxEXPAND, 5 );


	bSizer18->Add( sbSizer6, 0, wxEXPAND|wxALL, 5 );

	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Grid Properties:") ), wxHORIZONTAL );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->AddGrowableCol( 3 );
	fgSizer1->SetFlexibleDirection( wxHORIZONTAL );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText7 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Tile Size:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer1->Add( m_staticText7, 0, wxALL, 5 );

	m_staticText1 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer1->Add( m_staticText1, 0, wxALL, 5 );

	m_tileWidth = new wxSpinCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 4096, 16 );
	fgSizer1->Add( m_tileWidth, 0, wxALL, 5 );

	m_staticText2 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Height:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer1->Add( m_staticText2, 0, wxALL, 5 );

	m_tileHeight = new wxSpinCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 4096, 16 );
	fgSizer1->Add( m_tileHeight, 0, wxALL, 5 );

	m_staticText8 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Offset:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer1->Add( m_staticText8, 0, wxALL, 5 );

	m_staticText11 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Left:"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE );
	m_staticText11->Wrap( -1 );
	fgSizer1->Add( m_staticText11, 1, wxALL, 5 );

	m_offsetLeft = new wxSpinCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 4096, 0 );
	fgSizer1->Add( m_offsetLeft, 1, wxALL, 5 );

	m_staticText21 = new wxStaticText( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Top:"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE );
	m_staticText21->Wrap( -1 );
	fgSizer1->Add( m_staticText21, 1, wxALL, 5 );

	m_offsetTop = new wxSpinCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 4096, 0 );
	fgSizer1->Add( m_offsetTop, 1, wxALL, 5 );


	sbSizer3->Add( fgSizer1, 0, wxEXPAND, 5 );


	bSizer18->Add( sbSizer3, 1, wxEXPAND|wxALL, 5 );

	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Layer Properties:") ), wxVERTICAL );

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );

	m_cbLocked = new wxCheckBox( sbSizer10->GetStaticBox(), wxID_ANY, wxT("Locked"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	bSizer19->Add( m_cbLocked, 0, wxALL, 5 );

	m_cbVisible = new wxCheckBox( sbSizer10->GetStaticBox(), wxID_ANY, wxT("Visible"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	m_cbVisible->SetValue(true);
	bSizer19->Add( m_cbVisible, 0, wxALL, 5 );


	sbSizer10->Add( bSizer19, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText29 = new wxStaticText( sbSizer10->GetStaticBox(), wxID_ANY, wxT("Fill Opacity:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	bSizer20->Add( m_staticText29, 0, wxALL, 5 );

	m_sliderFillOpacity = new wxSlider( sbSizer10->GetStaticBox(), wxID_ANY, 255, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_VALUE_LABEL );
	bSizer20->Add( m_sliderFillOpacity, 1, wxALL, 5 );

	m_staticText30 = new wxStaticText( sbSizer10->GetStaticBox(), wxID_ANY, wxT("Line Opacity:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	bSizer20->Add( m_staticText30, 0, wxALL, 5 );

	m_sliderLineOpacity = new wxSlider( sbSizer10->GetStaticBox(), wxID_ANY, 255, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_VALUE_LABEL );
	bSizer20->Add( m_sliderLineOpacity, 1, wxALL, 5 );


	sbSizer10->Add( bSizer20, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( sbSizer10->GetStaticBox(), wxID_ANY, wxT("Tint:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer21->Add( m_staticText31, 0, wxALL, 5 );

	m_colourPicker1 = new wxColourPickerCtrl( sbSizer10->GetStaticBox(), wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE|wxCLRP_USE_TEXTCTRL );
	bSizer21->Add( m_colourPicker1, 0, wxALL, 5 );


	sbSizer10->Add( bSizer21, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );

	m_cbTileScaling = new wxCheckBox( sbSizer10->GetStaticBox(), wxID_ANY, wxT("Pixel Coherance"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	bSizer22->Add( m_cbTileScaling, 0, wxALL, 5 );


	sbSizer10->Add( bSizer22, 1, wxEXPAND, 5 );


	bSizer18->Add( sbSizer10, 1, wxEXPAND|wxALL, 5 );


	bSizer18->Add( 0, 0, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer19a;
	bSizer19a = new wxBoxSizer( wxHORIZONTAL );


	bSizer19a->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button7 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19a->Add( m_button7, 0, wxALL, 5 );

	m_button8 = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19a->Add( m_button8, 0, wxALL, 5 );


	bSizer18->Add( bSizer19a, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer18 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_tileWidth->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LayerPropertiesBase::OnGridUpdate ), NULL, this );
	m_tileHeight->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LayerPropertiesBase::OnGridUpdate ), NULL, this );
	m_offsetLeft->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LayerPropertiesBase::OnGridUpdate ), NULL, this );
	m_offsetTop->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LayerPropertiesBase::OnGridUpdate ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LayerPropertiesBase::OnButtonCancel ), NULL, this );
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LayerPropertiesBase::OnButtonOK ), NULL, this );
}

LayerPropertiesBase::~LayerPropertiesBase()
{
	// Disconnect Events
	m_tileWidth->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LayerPropertiesBase::OnGridUpdate ), NULL, this );
	m_tileHeight->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LayerPropertiesBase::OnGridUpdate ), NULL, this );
	m_offsetLeft->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LayerPropertiesBase::OnGridUpdate ), NULL, this );
	m_offsetTop->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LayerPropertiesBase::OnGridUpdate ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LayerPropertiesBase::OnButtonCancel ), NULL, this );
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LayerPropertiesBase::OnButtonOK ), NULL, this );

}

LayerPanelBase::LayerPanelBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );

	m_lblLayerType = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_lblLayerType->Wrap( -1 );
	m_lblLayerType->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );
	m_lblLayerType->SetMinSize( wxSize( 80,-1 ) );

	bSizer23->Add( m_lblLayerType, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slideLayerOpacity = new wxSlider( this, wxID_ANY, 255, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_HORIZONTAL );
	bSizer23->Add( m_slideLayerOpacity, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_bpButton22 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton22->SetBitmap( wxBitmap( wxT("gfx/ico_layer_view_on.png"), wxBITMAP_TYPE_ANY ) );
	bSizer23->Add( m_bpButton22, 0, wxALL, 5 );

	m_bpButton23 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton23->SetBitmap( wxBitmap( wxT("gfx/ico_layer_unlocked.png"), wxBITMAP_TYPE_ANY ) );
	bSizer23->Add( m_bpButton23, 0, wxALL, 5 );

	m_bpButton24 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton24->SetBitmap( wxBitmap( wxT("gfx/ico_layer_edit.png"), wxBITMAP_TYPE_ANY ) );
	bSizer23->Add( m_bpButton24, 0, wxALL, 5 );

	m_bpButton25 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton25->SetBitmap( wxBitmap( wxT("gfx/ico_layer_selected.png"), wxBITMAP_TYPE_ANY ) );
	bSizer23->Add( m_bpButton25, 0, wxALL, 5 );


	bSizer25->Add( bSizer23, 0, wxEXPAND, 5 );

	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer25->Add( m_staticline4, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer231;
	bSizer231 = new wxBoxSizer( wxHORIZONTAL );

	m_lblLayerType1 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL|wxST_NO_AUTORESIZE );
	m_lblLayerType1->Wrap( -1 );
	m_lblLayerType1->SetMinSize( wxSize( 80,-1 ) );

	bSizer231->Add( m_lblLayerType1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slideLayerOpacity1 = new wxSlider( this, wxID_ANY, 255, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_HORIZONTAL );
	bSizer231->Add( m_slideLayerOpacity1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_bpButton221 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton221->SetBitmap( wxBitmap( wxT("gfx/ico_layer_view_on.png"), wxBITMAP_TYPE_ANY ) );
	bSizer231->Add( m_bpButton221, 0, wxALL, 5 );

	m_bpButton231 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton231->SetBitmap( wxBitmap( wxT("gfx/ico_layer_unlocked.png"), wxBITMAP_TYPE_ANY ) );
	bSizer231->Add( m_bpButton231, 0, wxALL, 5 );

	m_bpButton241 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton241->SetBitmap( wxBitmap( wxT("gfx/ico_layer_edit.png"), wxBITMAP_TYPE_ANY ) );
	bSizer231->Add( m_bpButton241, 0, wxALL, 5 );

	m_bpButton251 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton251->SetBitmap( wxBitmap( wxT("gfx/ico_layer_selected.png"), wxBITMAP_TYPE_ANY ) );
	bSizer231->Add( m_bpButton251, 0, wxALL, 5 );


	bSizer25->Add( bSizer231, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer25 );
	this->Layout();

	// Connect Events
	m_slideLayerOpacity->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
}

LayerPanelBase::~LayerPanelBase()
{
	// Disconnect Events
	m_slideLayerOpacity->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );
	m_slideLayerOpacity1->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( LayerPanelBase::OnLayerChangeOpacity ), NULL, this );

}
