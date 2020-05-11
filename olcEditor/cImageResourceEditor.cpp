#include "cImageResourceEditor.h"

cImageResourceEditor::cImageResourceEditor(wxWindow* parent, cMasterContext* glContext, std::shared_ptr<cImageResource> image) : ImageResourceEditorBase(parent)
{
	m_image = new cTiledResourceViewer(this, glContext->GetContext());
	m_imageSizer->Add(m_image, 1, wxALL | wxEXPAND, 5);

	m_resource = image;

	m_image->SetImageResource(m_resource);
	m_tileWidth->SetValue(m_resource->GetGridSize().x);
	m_tileHeight->SetValue(m_resource->GetGridSize().y);
	m_offsetLeft->SetValue(m_resource->GetGridOffset().x);
	m_offsetTop->SetValue(m_resource->GetGridOffset().y);
	m_spaceHorizontal->SetValue(m_resource->GetGridSpacing().x);
	m_spaceVertical->SetValue(m_resource->GetGridSpacing().y);
	m_txtFriendlyName->SetValue(m_resource->GetFriendlyName());
	m_txtFileName->SetPath(m_resource->GetFilePath());

	this->Layout();
}

cImageResourceEditor::~cImageResourceEditor()
{
}

void cImageResourceEditor::OnFileSourceChanged(wxFileDirPickerEvent& evt)
{
	m_resource->SetImage(evt.GetPath().ToStdString());	
	m_image->Refresh();
}

void cImageResourceEditor::OnGridUpdate(wxSpinEvent& evt)
{
	m_resource->SetGridOffset({ m_offsetLeft->GetValue(), m_offsetTop->GetValue() });
	m_resource->SetGridSize({ m_tileWidth->GetValue(), m_tileHeight->GetValue() });
	m_resource->SetGridSpacing({ m_spaceHorizontal->GetValue(), m_spaceVertical->GetValue() });
	m_image->Refresh();
}

void cImageResourceEditor::OnButtonOK(wxCommandEvent& event)
{
	m_resource->SetFriendlyName(m_txtFriendlyName->GetValue().ToStdString());
	EndModal(wxID_OK);
}

void cImageResourceEditor::OnButtonCancel(wxCommandEvent& event)
{
	EndModal(wxID_CANCEL);
}
