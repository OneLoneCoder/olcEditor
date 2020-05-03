#pragma once

#include <wx/wx.h>

#include "BaseGUI.h"

#include "cPrimaryRenderer.h"


class cMainFrame : public MainFrameBase
{
public:
	cMainFrame();
	virtual ~cMainFrame();

protected:
	cPrimaryRenderer* m_render = nullptr;

protected:
	void OnEditorMouseMove(cEditorMouseMoveEvent& evt);
};	

