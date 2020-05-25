#pragma once
#include "BaseGUI.h"
#include "cLayer.h"

class cLayerPropertiesEditor : public LayerPropertiesBase
{
public:
	cLayerPropertiesEditor(wxWindow* parent, std::shared_ptr<cLayer> layer);
	virtual ~cLayerPropertiesEditor();

protected:
	void OnGridUpdate(wxSpinEvent& evt) override;
	void OnButtonCancel(wxCommandEvent& evt) override;
	void OnButtonOK(wxCommandEvent& evt) override;
	void OnTintChanged(wxColourPickerEvent& evt) override;

private:
	std::shared_ptr<cLayer> m_layer = nullptr;

};

