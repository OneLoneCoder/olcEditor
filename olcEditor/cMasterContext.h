#pragma once
#include <wx/glcanvas.h>
#include "common.h"

class cMasterContext : public wxGLCanvas
{
public:
	cMasterContext(wxWindow* parent);
	virtual ~cMasterContext();

private:
	wxGLContext *m_glContext = nullptr;

public:
	wxGLContext* GetContext();

	uint32_t CreateTexture();
	int DeleteTexture(const uint32_t id);
	int UseTexture(const uint32_t id);
	int UpdateTexture(const uint32_t id, olc::Sprite* spr);
};

