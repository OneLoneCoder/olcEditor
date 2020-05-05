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



class cLayer
{
public:
	cLayer();
	cLayer(const std::string& name, LayerType t);
	virtual ~cLayer();

	bool IsVisble() const;
	void SetVisible(bool b);

	bool IsLocked() const;
	void SetLocked(bool b);

	float GetFillOpacity() const;
	void SetFillOpacity(float alpha);

	float GetLineOpacity() const;
	void SetLineOpacity(float alpha);

	void SetName(const std::string& name);
	const std::string& GetName() const;

	const LayerType GetType() const;

	const olc::vf2d& GetWorldOffset() const;
	void SetWorldOffset(const olc::vf2d& offset);


	virtual void RenderSelf(RenderToolkit &gfx, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR);

protected:
	std::string m_sName;
	float m_fFillOpacity = 1.0f;
	float m_fLineOpacity = 1.0f;
	bool m_bVisible = true;
	bool m_bLocked = false;
	olc::vf2d m_vWorldOffset;
	LayerType m_type = LayerType::Undefined;
};

