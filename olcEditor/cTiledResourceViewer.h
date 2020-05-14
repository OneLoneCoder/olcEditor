#pragma once
#include "cPanAndZoomRenderer.h"
#include "cImageResource.h"
#include "cGridSelection.h"

class cTiledResourceViewer : public cPanAndZoomRenderer
{
public:
	cTiledResourceViewer(wxWindow* parent, wxGLContext* gl, std::shared_ptr<cGridSelection> gridselect);
	virtual ~cTiledResourceViewer();

	void SetImageResource(std::shared_ptr<cImageResource> image);

protected:
	void OnRender() override;
	void OnMouseLeftUp(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl) override;
	void OnMouseLeftDown(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl) override;
	void OnMouseMove(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl) override;

private:
	std::shared_ptr<cImageResource> m_image;
	std::shared_ptr<cGridSelection> m_selection;
	bool m_bDragging = false;
	olc::vi2d m_vStartDrag = { 0,0 };
};

