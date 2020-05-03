#pragma once

#include <wx/wx.h>

#include "cPrimaryRenderer.h"


class cMainFrame : public wxFrame
{
public:
	cMainFrame();

protected:
	cPrimaryRenderer* m_render = nullptr;


};	

