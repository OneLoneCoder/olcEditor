#include "cLayerSelectPanel.h"

wxDEFINE_EVENT(olcEVT_Layer_SelectionChange, cLayerChangeEvent);

cLayerSelectPanel::cLayerSelectPanel(wxWindow* parent, std::shared_ptr<cLayer> layer, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPanel(parent, id, pos, size, style, name)
{
	m_pLayer = layer;

	wxBoxSizer* szVert = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* szHoriz = new wxBoxSizer(wxHORIZONTAL);

	m_lblName = new wxStaticText(this, wxID_ANY, wxT("Layer Name"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL | wxST_NO_AUTORESIZE);
	m_lblName->Wrap(-1);
	m_lblName->SetMinSize(wxSize(80, -1));
	szHoriz->Add(m_lblName, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	m_slidOpacity = new wxSlider(this, wxID_ANY, 255, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_BOTH | wxSL_HORIZONTAL);
	szHoriz->Add(m_slidOpacity, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	m_togView = new wxBitmapToggleButton(this, wxID_ANY, wxBitmap(wxT("gfx/ico_layer_view_on.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxSize(24,24), wxBU_AUTODRAW | 0);
	szHoriz->Add(m_togView, 0, wxALL, 5);

	m_togLock = new wxBitmapToggleButton(this, wxID_ANY, wxBitmap(wxT("gfx/ico_layer_locked.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxSize(24, 24), wxBU_AUTODRAW | 0);
	szHoriz->Add(m_togLock, 0, wxALL, 5);

	m_btnEdit = new wxBitmapButton(this, wxID_ANY, wxBitmap(wxT("gfx/ico_layer_edit.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxSize(24, 24), wxBU_AUTODRAW | 0);
	szHoriz->Add(m_btnEdit, 0, wxALL, 5);

	m_btnSelect = new wxBitmapButton(this, wxID_ANY, wxBitmap(wxT("gfx/ico_layer_selected.png"), wxBITMAP_TYPE_ANY), wxDefaultPosition, wxSize(24, 24), wxBU_AUTODRAW | 0);
	szHoriz->Add(m_btnSelect, 0, wxALL, 5);

	szVert->Add(szHoriz, 0, wxEXPAND, 5);

	wxStaticLine *line = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	szVert->Add(line, 0, wxEXPAND, 5);

	this->SetSizer(szVert);
	this->Layout();

	m_lblName->SetLabel(m_pLayer->GetName());
	m_slidOpacity->SetValue(int(m_pLayer->GetFillOpacity() * 255.0f));
	m_togView->SetValue(m_pLayer->IsVisible());
	m_togLock->SetValue(m_pLayer->IsLocked());
	Select(m_pLayer->IsSelected());

	m_slidOpacity->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(cLayerSelectPanel::OnChangeOpacity), nullptr, this);
	m_togView->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cLayerSelectPanel::OnToggleView), nullptr, this);
	m_togLock->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cLayerSelectPanel::OnToggleLock), nullptr, this);
	m_btnEdit->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cLayerSelectPanel::OnButtonEdit), nullptr, this);
	m_btnSelect->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cLayerSelectPanel::OnButtonSelect), nullptr, this);
}

cLayerSelectPanel::~cLayerSelectPanel()
{
	m_slidOpacity->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(cLayerSelectPanel::OnChangeOpacity), nullptr, this);
	m_togView->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cLayerSelectPanel::OnToggleView), nullptr, this);
	m_togLock->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cLayerSelectPanel::OnToggleLock), nullptr, this);
	m_btnEdit->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cLayerSelectPanel::OnButtonEdit), nullptr, this);
	m_btnSelect->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cLayerSelectPanel::OnButtonSelect), nullptr, this);
}

void cLayerSelectPanel::OnChangeOpacity(wxScrollEvent& evt)
{
	m_pLayer->SetFillOpacity(float(m_slidOpacity->GetValue()) / 255.0f);
}

void cLayerSelectPanel::OnToggleView(wxCommandEvent& evt)
{
	m_pLayer->SetVisible(m_togView->GetValue());
}

void cLayerSelectPanel::OnToggleLock(wxCommandEvent& evt)
{
	m_pLayer->SetLocked(m_togLock->GetValue());
}

void cLayerSelectPanel::OnButtonEdit(wxCommandEvent& evt)
{
	cLayerPropertiesEditor dlg(this, m_pLayer);
	if (dlg.ShowModal() == wxID_OK)
	{
		m_lblName->SetLabel(m_pLayer->GetName());
		m_slidOpacity->SetValue(int(m_pLayer->GetFillOpacity() * 255.0f));
		m_togView->SetValue(m_pLayer->IsVisible());
		m_togLock->SetValue(m_pLayer->IsLocked());
	}
}

void cLayerSelectPanel::OnButtonSelect(wxCommandEvent& evt)
{
	Select(true);

	cLayerChangeEvent e(olcEVT_Layer_SelectionChange);
	e.SetLayer(m_pLayer);
	wxPostEvent(this->GetParent(), e);
}


void cLayerSelectPanel::Select(bool bb)
{
	m_pLayer->SetSelected(bb);

	if (bb)
		SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	else
		SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	Refresh();
}