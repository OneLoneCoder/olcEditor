#include "cLayer.h"

cLayer::cLayer()
{
}

cLayer::cLayer(const std::string& name, LayerType t, ContentType c) : m_sName(name), m_type(t), m_content(c)
{	
}

cLayer::~cLayer()
{
}

bool cLayer::IsVisble() const
{
	return m_bVisible;
}

void cLayer::SetVisible(bool b)
{
	m_bVisible = b;
}

bool cLayer::IsLocked() const
{
	return m_bLocked;
}

void cLayer::SetLocked(bool b)
{
	m_bLocked = b;
}

float cLayer::GetFillOpacity() const
{
	return m_fFillOpacity;
}

void cLayer::SetFillOpacity(float alpha)
{
	m_fFillOpacity = alpha;
}

float cLayer::GetLineOpacity() const
{
	return m_fLineOpacity;
}

void cLayer::SetLineOpacity(float alpha)
{
	m_fLineOpacity = alpha;
}

void cLayer::SetName(const std::string& name)
{
	m_sName = name;
}

const std::string& cLayer::GetName() const
{
	return m_sName;
}

const LayerType cLayer::GetType() const
{
	return m_type;
}

const ContentType cLayer::GetContentType() const
{
	return m_content;
}

const olc::vf2d& cLayer::GetWorldOffset() const
{
	return m_vWorldOffset;
}

void cLayer::SetWorldOffset(const olc::vf2d& offset)
{
	m_vWorldOffset = offset;
}

void cLayer::RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR)
{

}

const std::string cLayer::GetLayerTypeName() const
{
	return "Nameless Layer Type";
}

const std::vector<sToolBarButton> cLayer::GetToolBarButtons() const
{
	return std::vector<sToolBarButton>();
}




