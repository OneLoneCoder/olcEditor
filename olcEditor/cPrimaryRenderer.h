#pragma once

#include <wx/wx.h>
#include <wx/glcanvas.h>

struct vf2d
{
	float x;
	float y;
};

class cEditorMouseMoveEvent;
wxDECLARE_EVENT(olcEVT_Editor_MouseMove, cEditorMouseMoveEvent);

class cEditorMouseMoveEvent : public wxCommandEvent
{
public:
	cEditorMouseMoveEvent(wxEventType commandType = olcEVT_Editor_MouseMove, int id = 0)
		: wxCommandEvent(commandType, id) { }

	cEditorMouseMoveEvent(const cEditorMouseMoveEvent& event)
		: wxCommandEvent(event)
	{
		this->SetTileX(event.GetTileX());
		this->SetTileY(event.GetTileY());
		this->SetPixelX(event.GetPixelX());
		this->SetPixelY(event.GetPixelY());
		this->SetWorldX(event.GetWorldX());
		this->SetWorldY(event.GetWorldY());
	}

	// Required for sending with wxPostEvent()
	wxEvent* Clone() const { return new cEditorMouseMoveEvent(*this); }

	int GetTileX() const { return nTileX; }
	int GetTileY() const { return nTileY; }
	int GetPixelX() const { return nPixelX; }
	int GetPixelY() const { return nPixelY; }
	float GetWorldX() const { return fWorldX; }
	float GetWorldY() const { return fWorldY; }

	void SetTileX(const int& n) { nTileX = n;}
	void SetTileY(const int& n) { nTileY = n;}
	void SetPixelX(const int& n) { nPixelX = n;}
	void SetPixelY(const int& n) { nPixelY = n;}
	void SetWorldX(const float& n) { fWorldX = n;}
	void SetWorldY(const float& n) { fWorldY = n;}
	 

private:
	int nTileX = 0;
	int nTileY = 0;
	int nPixelX = 0;
	int nPixelY = 0;
	float fWorldX = 0;
	float fWorldY = 0;
};

typedef void (wxEvtHandler::*EditorMouseMoveFunction)(cEditorMouseMoveEvent&);
#define EditorMouseMoveHandler(func) wxEVENT_HANDLER_CAST(EditorMouseMoveFunction, func) 

class cPrimaryRenderer : public wxGLCanvas
{
public:
	cPrimaryRenderer(wxWindow* parent);
	virtual ~cPrimaryRenderer();

protected:
	void OnRender();

	void DrawLine(const vf2d& start, const vf2d& end, const float width = 1.0f);
	void DrawRect(const vf2d& start, const vf2d& size, const float width = 1.0f);

	vf2d WorldToScreen(const vf2d& point);
	vf2d ScreenToWorld(const vf2d& point);
	vf2d ProjectToView(const vf2d& point);

protected:
	void OnPaint(wxPaintEvent& evt);
	void OnMiddleMouseDown(wxMouseEvent& evt);
	void OnMiddleMouseUp(wxMouseEvent& evt);
	void OnMiddleMouseWheel(wxMouseEvent& evt);
	void OnMouseMove(wxMouseEvent& evt);

private:
	wxGLContext* m_glContext;
	vf2d m_unitscale = { 1.0f, 1.0f };
	vf2d m_scale = {32.0f, 32.0f};
	vf2d m_offset = { 0.0f, 0.0f };	
	vf2d m_startpan = { 0.0f, 0.0f };
	vf2d m_viewsize = { 0,0 };
	vf2d m_cursor = { 0,0 };
	bool m_bWorldDrag = false;
	float m_fZoom = 1.0f;
};

