#pragma once
#include "cPanAndZoomRenderer.h"
#include "cImageResource.h"

class cTiledResourceViewer : public cPanAndZoomRenderer
{
public:
	cTiledResourceViewer(wxWindow* parent, wxGLContext* gl);
	virtual ~cTiledResourceViewer();

	void SetImageResource(std::shared_ptr<cImageResource> image);
	void SetGridSize(const olc::vi2d& size);
	void SetGridOffset(const olc::vi2d& offset);
	void SetGridSpacing(const olc::vi2d& spacing);

protected:
	void OnRender() override;

private:
	std::shared_ptr<cImageResource> m_image;
	olc::vi2d m_vGridOffset;
	olc::vi2d m_vGridSpacing;
	olc::vi2d m_vGridSize = { 16, 16 };
};

