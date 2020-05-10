#include "cMasterContext.h"

cMasterContext::cMasterContext(wxWindow* parent) : wxGLCanvas(parent, -1, nullptr)
{
	m_glContext = new wxGLContext(this);	
	//SetCurrent(*m_glContext);
}

cMasterContext::~cMasterContext()
{
	delete m_glContext;
}

wxGLContext* cMasterContext::GetContext()
{
	return m_glContext;
}

uint32_t cMasterContext::CreateTexture()
{
	uint32_t id = 0;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	return id;
}

int cMasterContext::DeleteTexture(const uint32_t id)
{
	glDeleteTextures(1, &id);
	return 0;
}

int cMasterContext::UseTexture(const uint32_t id)
{
	glBindTexture(GL_TEXTURE_2D, id);
	return 1;
}

int cMasterContext::UpdateTexture(const uint32_t id, olc::Sprite* spr)
{
	glBindTexture(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, spr->vSize.x, spr->vSize.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, spr->GetData());
	return 1;
}
