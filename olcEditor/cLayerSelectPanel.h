#pragma once
#include <wx/wx.h>
#include <wx/tglbtn.h>
#include <wx/statline.h>
#include "cLayer.h"
#include "cLayerPropertiesEditor.h"

class cLayerChangeEvent;
wxDECLARE_EVENT(olcEVT_Layer_SelectionChange, cLayerChangeEvent);
wxDECLARE_EVENT(olcEVT_Layer_RefreshPlease, cLayerChangeEvent);

class cLayerChangeEvent : public wxCommandEvent
{
public:
	cLayerChangeEvent(wxEventType commandType = olcEVT_Layer_SelectionChange, int id = 0) : wxCommandEvent(commandType, id) { }

	cLayerChangeEvent(const cLayerChangeEvent& event) : wxCommandEvent(event)
	{
		this->SetLayer(event.GetLayer());		
	}

	wxEvent* Clone() const { return new cLayerChangeEvent(*this); }

	std::shared_ptr<cLayer> GetLayer() const { return pLayer; }
	void SetLayer(std::shared_ptr<cLayer> layer) { pLayer = layer; }

private:
	std::shared_ptr<cLayer> pLayer;
};

typedef void (wxEvtHandler::* EditorLayerSelection)(cLayerChangeEvent&);
#define EditorLayerSelectHandler(func) wxEVENT_HANDLER_CAST(EditorLayerSelection, func) 

typedef void (wxEvtHandler::* EditorLayerRefresh)(cLayerChangeEvent&);
#define EditorLayerRefreshHandler(func) wxEVENT_HANDLER_CAST(EditorLayerRefresh, func) 

class cLayerSelectPanel : public wxPanel
{
public:
	cLayerSelectPanel(wxWindow* parent, std::shared_ptr<cLayer> layer, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString);
	~cLayerSelectPanel();

	void Select(bool bb);

private:
	wxStaticText* m_lblName = nullptr;
	wxSlider* m_slidOpacity = nullptr;
	wxBitmapToggleButton* m_togView = nullptr;
	wxBitmapToggleButton* m_togLock = nullptr;
	wxBitmapButton* m_btnEdit = nullptr;
	wxBitmapButton* m_btnSelect = nullptr;

	std::shared_ptr<cLayer> m_pLayer = nullptr;

protected:
	virtual void OnChangeOpacity(wxScrollEvent& evt);
	virtual void OnToggleView(wxCommandEvent& evt);
	virtual void OnToggleLock(wxCommandEvent& evt);
	virtual void OnButtonEdit(wxCommandEvent& evt);
	virtual void OnButtonSelect(wxCommandEvent& evt);
};

