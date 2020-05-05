#include "cApp.h"

wxIMPLEMENT_APP(cApp);


cApp::cApp()
{
}


cApp::~cApp()
{

}


bool cApp::OnInit()
{
	wxInitAllImageHandlers();
	m_frame = new cMainFrame();
	m_frame->Show();
	return true;
}