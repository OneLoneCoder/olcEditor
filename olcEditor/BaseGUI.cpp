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

	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FIXEDWIDTH|wxNB_TOP );
	m_panel3 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_button3 = new wxButton( m_panel3, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button3, 0, wxALL, 5 );

	m_button4 = new wxButton( m_panel3, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button4, 0, wxALL, 5 );

	m_button5 = new wxButton( m_panel3, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button5, 0, wxALL, 5 );

	m_button6 = new wxButton( m_panel3, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button6, 0, wxALL, 5 );

	m_button7 = new wxButton( m_panel3, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button7, 0, wxALL, 5 );

	m_button8 = new wxButton( m_panel3, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button8, 0, wxALL, 5 );

	m_button9 = new wxButton( m_panel3, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button9, 0, wxALL, 5 );

	m_button10 = new wxButton( m_panel3, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button10, 0, wxALL, 5 );


	m_panel3->SetSizer( bSizer7 );
	m_panel3->Layout();
	bSizer7->Fit( m_panel3 );
	m_notebook1->AddPage( m_panel3, wxT("a page"), true );
	m_panel4 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook1->AddPage( m_panel4, wxT("a page"), false );
	m_panel5 = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook1->AddPage( m_panel5, wxT("a page"), false );

	bSizer4->Add( m_notebook1, 0, wxEXPAND, 5 );

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
