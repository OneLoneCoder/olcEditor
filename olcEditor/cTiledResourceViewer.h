#pragma once
#include "cPanAndZoomRenderer.h"
#include "cImageResource.h"
#include "cTransientSelection.h"

class cTiledResourceViewer : public cPanAndZoomRenderer
{
public:
	cTiledResourceViewer(wxWindow* parent, wxGLContext* gl);
	virtual ~cTiledResourceViewer();

	void SetImageResource(std::shared_ptr<cImageResource> image);
	const cTransientSelection& GetSelection() const;

protected:
	void OnRender() override;
	void OnMouseLeftUp(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl) override;
	void OnMouseLeftDown(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl) override;
	void OnMouseMove(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl) override;

private:
	std::shared_ptr<cImageResource> m_image;
	cTransientSelection m_selection;
	bool m_bDragging = false;
	olc::vi2d m_vStartDrag = { 0,0 };
};

