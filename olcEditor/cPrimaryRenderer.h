#pragma once


#include <wx/wx.h>
#include <wx/glcanvas.h>

#include "common.h"
#include "cArea.h"
#include "cLayer_Boolean.h"

#include "RenderToolkit.h"

class cEditorMouseEvent;
wxDECLARE_EVENT(olcEVT_Editor_MouseMove, cEditorMouseEvent);
wxDECLARE_EVENT(olcEVT_Editor_MouseLeftUp, cEditorMouseEvent);
wxDECLARE_EVENT(olcEVT_Editor_MouseLeftDown, cEditorMouseEvent);

class cEditorMouseEvent : public wxCommandEvent
{
public:
	cEditorMouseEvent(wxEventType commandType = olcEVT_Editor_MouseMove, int id = 0)
		: wxCommandEvent(commandType, id) { }

	cEditorMouseEvent(const cEditorMouseEvent& event)
		: wxCommandEvent(event)
	{
		this->SetTile(event.GetTile());		
		this->SetPixel(event.GetPixel());		
		this->SetWorld(event.GetWorld());		
	}

	// Required for sending with wxPostEvent()
	wxEvent* Clone() const { return new cEditorMouseEvent(*this); }

	olc::vi2d GetTile() const { return vTile; }
	olc::vi2d GetPixel() const { return vPixel; }	
	olc::vf2d GetWorld() const { return vWorld; }

	void SetTile(const olc::vi2d& n) { vTile = n;}
	void SetPixel(const olc::vi2d& n) { vPixel = n;}
	void SetWorld(const olc::vf2d& n) { vWorld = n;}
	
	
private:
	olc::vi2d vTile = { 0,0 };
	olc::vi2d vPixel = { 0,0 };
	olc::vf2d vWorld = { 0,0 };
};

typedef void (wxEvtHandler::*EditorMouseMoveFunction)(cEditorMouseEvent&);
#define EditorMouseMoveHandler(func) wxEVENT_HANDLER_CAST(EditorMouseMoveFunction, func) 

typedef void (wxEvtHandler::* EditorMouseLeftDownFunction)(cEditorMouseEvent&);
#define EditorMouseLeftDownHandler(func) wxEVENT_HANDLER_CAST(EditorMouseLeftDownFunction, func) 

typedef void (wxEvtHandler::* EditorMouseLeftUpFunction)(cEditorMouseEvent&);
#define EditorMouseLeftUpHandler(func) wxEVENT_HANDLER_CAST(EditorMouseLeftUpFunction, func) 

class cPrimaryRenderer : public wxGLCanvas
{
public:
	cPrimaryRenderer(wxWindow* parent);
	virtual ~cPrimaryRenderer();

	void SetArea(std::shared_ptr<cArea> area);

protected:
	void OnRender();
	//void RenderLayer_Boolean(cLayer_Boolean* layer, const olc::vf2d& vWorldTL, const olc::vf2d& vWorldBR);


public:
	/*void DrawLine(const olc::vf2d& start, const olc::vf2d& end, const olc::colour col, const float width = 1.0f);
	void DrawRect(const olc::vf2d& start, const olc::vf2d& size, const olc::colour col, const float width = 1.0f);
	void FillRect(const olc::vf2d& start, const olc::vf2d& size, const olc::colour col, const float width = 1.0f);

	olc::vf2d WorldToScreen(const olc::vf2d& point);
	olc::vf2d ScreenToWorld(const olc::vf2d& point);
	olc::vf2d ProjectToView(const olc::vf2d& point);*/

protected:
	void OnPaint(wxPaintEvent& evt);
	void OnMiddleMouseDown(wxMouseEvent& evt);
	void OnMiddleMouseUp(wxMouseEvent& evt);
	void OnMiddleMouseWheel(wxMouseEvent& evt);
	void OnMouseLeftUp(wxMouseEvent& evt);
	void OnMouseLeftDown(wxMouseEvent& evt);
	void OnMouseMove(wxMouseEvent& evt);

	cLayer_Boolean layer;

private:
	wxGLContext* m_glContext;
	RenderToolkit gfx;
	olc::vf2d m_unitscale = { 1.0f, 1.0f };
	olc::vf2d m_startpan = { 0.0f, 0.0f };
	olc::vf2d m_cursor = { 0,0 };
	bool m_bWorldDrag = false;
	float m_fZoom = 1.0f;

	std::shared_ptr<cArea> m_area = nullptr;
};

