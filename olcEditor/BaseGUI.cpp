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

	m_bpButton1 = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton1->SetBitmap( wxBitmap( wxT("gfx/ico_select_clear.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_bpButton1, 0, wxALL, 5 );

	m_bpButton2 = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton2->SetBitmap( wxBitmap( wxT("gfx/ico_select.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_bpButton2, 0, wxALL, 5 );

	m_bpButton3 = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton3->SetBitmap( wxBitmap( wxT("gfx/ico_select_move.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_bpButton3, 0, wxALL, 5 );

	m_bpButton5 = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton5->SetBitmap( wxBitmap( wxT("gfx/ico_select_fill.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_bpButton5, 0, wxALL, 5 );

	m_staticline1 = new wxStaticLine( m_toolsBoolean, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer7->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	m_bpButton6 = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton6->SetBitmap( wxBitmap( wxT("gfx/ico_draw_one.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_bpButton6, 0, wxALL, 5 );

	m_bpButton7 = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton7->SetBitmap( wxBitmap( wxT("gfx/ico_draw_line.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_bpButton7, 0, wxALL, 5 );

	m_bpButton8 = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton8->SetBitmap( wxBitmap( wxT("gfx/ico_draw_rect.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_bpButton8, 0, wxALL, 5 );

	m_bpButton9 = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton9->SetBitmap( wxBitmap( wxT("gfx/ico_fill_rect.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_bpButton9, 0, wxALL, 5 );

	m_bpButton10 = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton10->SetBitmap( wxBitmap( wxT("gfx/ico_draw_circle.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_bpButton10, 0, wxALL, 5 );

	m_bpButton11 = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton11->SetBitmap( wxBitmap( wxT("gfx/ico_fill_circle.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_bpButton11, 0, wxALL, 5 );

	m_bpButton12 = new wxBitmapButton( m_toolsBoolean, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton12->SetBitmap( wxBitmap( wxT("gfx/ico_draw_fill.png"), wxBITMAP_TYPE_ANY ) );
	bSizer7->Add( m_bpButton12, 0, wxALL, 5 );


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

	m_listCtrl1 = new wxListCtrl( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON|wxLC_LIST );
	bSizer3->Add( m_listCtrl1, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_bpButton13 = new wxBitmapButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton13->SetBitmap( wxBitmap( wxT("gfx/ico_layer_add.png"), wxBITMAP_TYPE_ANY ) );
	bSizer10->Add( m_bpButton13, 0, wxALL, 5 );

	m_bpButton14 = new wxBitmapButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton14->SetBitmap( wxBitmap( wxT("gfx/ico_layer_erase.png"), wxBITMAP_TYPE_ANY ) );
	bSizer10->Add( m_bpButton14, 0, wxALL, 5 );

	m_bpButton15 = new wxBitmapButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton15->SetBitmap( wxBitmap( wxT("gfx/ico_layer_duplicate.png"), wxBITMAP_TYPE_ANY ) );
	bSizer10->Add( m_bpButton15, 0, wxALL, 5 );

	m_bpButton16 = new wxBitmapButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton16->SetBitmap( wxBitmap( wxT("gfx/ico_layer_moveup.png"), wxBITMAP_TYPE_ANY ) );
	bSizer10->Add( m_bpButton16, 0, wxALL, 5 );

	m_bpButton17 = new wxBitmapButton( m_panel1, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	m_bpButton17->SetBitmap( wxBitmap( wxT("gfx/ico_layer_movedown.png"), wxBITMAP_TYPE_ANY ) );
	bSizer10->Add( m_bpButton17, 0, wxALL, 5 );


	bSizer3->Add( bSizer10, 0, wxEXPAND, 5 );

	m_staticline2 = new wxStaticLine( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	m_propertyGrid1 = new wxPropertyGrid(m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_DEFAULT_STYLE);
	m_propertyGridItem1 = m_propertyGrid1->Append( new wxStringProperty( wxT("Name"), wxT("Name") ) );
	m_propertyGridItem2 = m_propertyGrid1->Append( new wxStringProperty( wxT("Name"), wxT("Name") ) );
	m_propertyGridItem3 = m_propertyGrid1->Append( new wxStringProperty( wxT("Name"), wxT("Name") ) );
	m_propertyGridItem4 = m_propertyGrid1->Append( new wxStringProperty( wxT("Name"), wxT("Name") ) );
	bSizer3->Add( m_propertyGrid1, 0, wxALL|wxEXPAND, 5 );

	m_staticline3 = new wxStaticLine( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );

	m_panel8 = new wxPanel( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer3->Add( m_panel8, 1, wxEXPAND | wxALL, 5 );


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
}

MainFrameBase::~MainFrameBase()
{
}
