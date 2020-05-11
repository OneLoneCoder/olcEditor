#include "cImageResource.h"

cImageResource::cImageResource(cMasterContext* glContext)
{
	m_gl = glContext;
	m_pSprite = std::make_unique<olc::Sprite>(1, 1);
	m_sFriendlyName = "Nameless Image";
}

cImageResource::~cImageResource()
{
	m_gl->DeleteTexture(m_nHardwareID);
}

bool cImageResource::SetImage(const std::string& sFilename)
{
	// Erase old image
	m_gl->DeleteTexture(m_nHardwareID);
	m_pSprite.reset();

	// Load New Image
	m_pSprite = std::make_unique<olc::Sprite>(sFilename);
	m_sFilePath = sFilename;

	// Create GPU Texture
	m_nHardwareID = m_gl->CreateTexture();
	m_gl->UpdateTexture(m_nHardwareID, m_pSprite.get());	
	return false;
}

void cImageResource::SetFriendlyName(const std::string& sName)
{
	m_sFriendlyName = sName;
}

void cImageResource::UseImage()
{
	m_gl->UseTexture(m_nHardwareID);
}

void cImageResource::Update()
{
	m_gl->UpdateTexture(m_nHardwareID, m_pSprite.get());
}

const std::string& cImageResource::GetFilePath() const
{
	return m_sFilePath;
}

const std::string& cImageResource::GetFriendlyName() const
{
	return m_sFriendlyName;
}

uint32_t cImageResource::GetHardwareID() const
{
	return m_nHardwareID;
}

uint32_t cImageResource::GetProjectID() const
{
	return m_nProjectID;
}

olc::Sprite* cImageResource::GetSprite() const
{
	return m_pSprite.get();
}

void cImageResource::SetGridSize(const olc::vi2d& size)
{
	m_vGridSize = size;
}

void cImageResource::SetGridOffset(const olc::vi2d& offset)
{
	m_vGridOffset = offset;
}

void cImageResource::SetGridSpacing(const olc::vi2d& spacing)
{
	m_vGridSpacing = spacing;
}

const olc::vi2d& cImageResource::GetGridSize() const
{
	return m_vGridSize;
}

const olc::vi2d& cImageResource::GetGridOffset() const
{
	return m_vGridOffset;
}

const olc::vi2d& cImageResource::GetGridSpacing() const
{
	return m_vGridSpacing;
}
