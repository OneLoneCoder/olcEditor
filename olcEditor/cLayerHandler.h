#pragma once

#include <wx/wx.h>
#include "common.h"


class cLayerHandler
{
public:
	cLayerHandler();
	virtual ~cLayerHandler();


public:
	virtual wxPanel* GetToolbar();

};

