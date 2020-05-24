#include "cLayerPropertiesEditor.h"


cLayerPropertiesEditor::cLayerPropertiesEditor(wxWindow* parent, std::shared_ptr<cLayer> layer) : LayerPropertiesBase(parent)
{
	m_layer = layer;

	if (m_layer)
	{
		m_sliderLineOpacity->SetValue(uint8_t(m_layer->GetLineOpacity() * 255));
		m_sliderFillOpacity->SetValue(uint8_t(m_layer->GetFillOpacity() * 255));
		m_txtFriendlyName->SetValue(m_layer->GetName());
		m_cbVisible->SetValue(m_layer->IsVisible());
		m_cbLocked->SetValue(m_layer->IsLocked());
		m_tileWidth->SetValue(m_layer->GetUnitSize().x);
		m_tileHeight->SetValue(m_layer->GetUnitSize().y);
	}
}

cLayerPropertiesEditor::~cLayerPropertiesEditor()
{
}

void cLayerPropertiesEditor::OnGridUpdate(wxSpinEvent& evt)
{
}

void cLayerPropertiesEditor::OnButtonCancel(wxCommandEvent& evt)
{

	EndModal(wxID_CANCEL);
}

void cLayerPropertiesEditor::OnButtonOK(wxCommandEvent& evt)
{
	if (m_layer)
	{
		m_layer->SetName(m_txtFriendlyName->GetValue().ToStdString());
		m_layer->SetLineOpacity(float(m_sliderLineOpacity->GetValue()) / 255.0f);
		m_layer->SetFillOpacity(float(m_sliderFillOpacity->GetValue()) / 255.0f);		
		m_layer->SetVisible(m_cbVisible->GetValue());
		m_layer->SetLocked(m_cbLocked->GetValue());
		m_layer->SetUnitSize({ m_tileWidth->GetValue(), m_tileHeight->GetValue() });		
	}

	EndModal(wxID_OK);
}
