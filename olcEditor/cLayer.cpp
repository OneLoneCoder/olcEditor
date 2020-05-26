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

bool cLayer::IsVisible() const
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

bool cLayer::IsSelected() const
{
	return m_bSelected;
}

void cLayer::SetSelected(bool b)
{
	m_bSelected = b;
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

const olc::vi2d& cLayer::GetUnitSize() const
{
	return m_vUnitSize;
}

void cLayer::SetUnitSize(const olc::vi2d& size)
{
	m_vUnitSize = size;
}

void cLayer::RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR)
{

}

void cLayer::RenderBrush(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR)
{

}

olc::vi2d cLayer::GetLayerSize() const
{
	return m_vLayerSize;
}


olc::vi2d cLayer::TileCoord(const olc::vf2d& vWorld) const
{
	return { int(vWorld.x / float(GetUnitSize().x)), int(vWorld.y / float(GetUnitSize().y)) };
}

void cLayer::SetLayerSize(const olc::vi2d& size)
{
	m_vLayerSize = size;
}




