#pragma once

#include <wx/wx.h>

#include "BaseGUI.h"

#include "cPrimaryRenderer.h"
#include "cArea.h"

class cMainFrame : public MainFrameBase
{
public:
	cMainFrame();
	virtual ~cMainFrame();

protected:
	cPrimaryRenderer* m_render = nullptr;

	std::shared_ptr<cArea> area = nullptr;
	std::shared_ptr<cLayer> m_layerSelected = nullptr;

	bool m_bLeftMouseDrag = false;

protected:
	void OnEditorMouseMove(cEditorMouseEvent& evt);
	void OnEditorMouseLeftUp(cEditorMouseEvent& evt);
	void OnEditorMouseLeftDown(cEditorMouseEvent& evt);
};	

