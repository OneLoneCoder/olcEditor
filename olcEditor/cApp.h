#pragma once

#include "wx/wx.h"

#include "cMainFrame.h"


class cApp : public wxApp
{
public:
	cApp();
	~cApp();

public:
	virtual bool OnInit();

private:
	cMainFrame* m_frame;
};

