#include "cImageResource.h"

cImageResource::cImageResource(cMasterContext* glContext)
{
	m_gl = glContext;
	m_pSprite = std::make_unique<olc::Sprite>(1, 1);
	m_sFriendlyName = "Nameless Image";
	m_nProjectID = g_nImageResourceGUID;
	g_nImageResourceGUID++;
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

sTileDescription cImageResource::GetTileDesc(const olc::vi2d& tile)
{
	olc::vi2d vPixelPos = (tile * (m_vGridSize + m_vGridSpacing)) + m_vGridOffset;

	olc::vf2d vTexturePos;
	vTexturePos.x = float(vPixelPos.x) / float(m_pSprite->vSize.x);
	vTexturePos.y = float(vPixelPos.y) / float(m_pSprite->vSize.y);
	olc::vf2d vTextureSize;
	vTextureSize.x = float(m_vGridSize.x) / float(m_pSprite->vSize.x);
	vTextureSize.y = float(m_vGridSize.y) / float(m_pSprite->vSize.y);
	
	sTileDescription d;
	d.nResourceID = m_nProjectID;
	d.vPosition = vTexturePos;
	d.vSize = vTextureSize;
	return d;
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

uint32_t cImageResource::g_nImageResourceGUID = 0;