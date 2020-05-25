#pragma once


#include "RenderToolkit.h"
#include "common.h"
enum class LayerType
{
	Undefined,
	Boolean,
	Integer,
	FloatingPoint,
	Character,
	Tile,
	Object,
	Geometry,
	Image
};


enum class ContentType
{
	Tiles,
	FreeForm
};


struct sToolBarButton
{	
	std::string sIconPath;
	std::string sButtonText;
	std::string sToolTipText;
};


class cLayer
{
public:
	cLayer();
	cLayer(const std::string& name, LayerType t, ContentType c);
	virtual ~cLayer();

	bool IsVisible() const; // FAIL PLEASE!!
	void SetVisible(bool b);

	bool IsLocked() const;
	void SetLocked(bool b);

	bool IsSelected() const;
	void SetSelected(bool b);

	float GetFillOpacity() const;
	void SetFillOpacity(float alpha);

	float GetLineOpacity() const;
	void SetLineOpacity(float alpha);

	void SetName(const std::string& name);
	const std::string& GetName() const;

	const LayerType GetType() const;
	const ContentType GetContentType() const;

	const olc::vf2d& GetWorldOffset() const;
	void SetWorldOffset(const olc::vf2d& offset);

	const olc::vi2d& GetUnitSize() const;
	void SetUnitSize(const olc::vi2d& size);


	virtual void RenderSelf(RenderToolkit& gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR);

	virtual const std::string GetLayerTypeName() const;
	virtual const std::vector<sToolBarButton> GetToolBarButtons() const;

	olc::vi2d GetLayerSize() const;
	olc::vi2d TileCoord(const olc::vf2d& vWorld) const;

	virtual void SetLayerSize(const olc::vi2d& size);

protected:
	

protected:
	std::string m_sName;
	float m_fFillOpacity = 1.0f;
	float m_fLineOpacity = 1.0f;
	bool m_bVisible = true;
	bool m_bLocked = false;
	bool m_bSelected = false;
	olc::vi2d m_vLayerSize = { 0, 0 };
	olc::vf2d m_vWorldOffset = { 0,0 };
	olc::vi2d m_vUnitSize = { 16,16 };
	LayerType m_type = LayerType::Undefined;
	ContentType m_content = ContentType::Tiles;
};




