#pragma once
#include "cPanAndZoomRenderer.h"
#include "cImageResource.h"

class cTiledResourceViewer : public cPanAndZoomRenderer
{
public:
	cTiledResourceViewer(wxWindow* parent, wxGLContext* gl);
	virtual ~cTiledResourceViewer();

	void SetImageResource(std::shared_ptr<cImageResource> image);
	

protected:
	void OnRender() override;

private:
	std::shared_ptr<cImageResource> m_image;
	
};

