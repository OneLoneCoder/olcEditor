#pragma once
#include "BaseGUI.h"
#include "cMasterContext.h"
#include "cImageResource.h"
#include "cTiledResourceViewer.h"

class cImageResourceEditor : public ImageResourceEditorBase
{
public:
	cImageResourceEditor(wxWindow* parent, cMasterContext *glContext, std::shared_ptr<cImageResource> image);
	virtual ~cImageResourceEditor();

protected:
	void OnFileSourceChanged(wxFileDirPickerEvent& evt) override;
	void OnGridUpdate(wxSpinEvent& evt) override;

private:
	cTiledResourceViewer* m_image;
	std::shared_ptr<cImageResource> m_resource = nullptr;
};

