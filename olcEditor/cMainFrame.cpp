#include "cMainFrame.h"

cMainFrame::cMainFrame() : wxFrame(nullptr, wxID_ANY, "OneLoneCoder - Editor", wxPoint(30, 30), wxSize(800, 800))
{
	wxBoxSizer* boxSizer;
	boxSizer = new wxBoxSizer(wxVERTICAL);

	m_render = new cPrimaryRenderer(this);
	boxSizer->Add(m_render, 1, wxEXPAND, 5);

	this->SetSizer(boxSizer);
	this->Layout();
}