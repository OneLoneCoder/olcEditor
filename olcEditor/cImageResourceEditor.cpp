#include "cImageResourceEditor.h"

cImageResourceEditor::cImageResourceEditor(wxWindow* parent, cMasterContext* glContext, std::shared_ptr<cImageResource> image) : ImageResourceEditorBase(parent)
{
	m_image = new cTiledResourceViewer(this, glContext->GetContext());
	m_imageSizer->Add(m_image, 1, wxALL | wxEXPAND, 5);

	m_resource = image;

	m_image->SetImageResource(m_resource);

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
	m_image->SetGridOffset({ m_offsetLeft->GetValue(), m_offsetTop->GetValue() });
	m_image->SetGridSize({ m_tileWidth->GetValue(), m_tileHeight->GetValue() });
	m_image->SetGridSpacing({ m_spaceHorizontal->GetValue(), m_spaceVertical->GetValue() });
}
