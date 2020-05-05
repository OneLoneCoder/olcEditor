#pragma once


#include "cLayer.h"

class cArea
{
public:
	cArea();
	virtual ~cArea();

	std::list<std::shared_ptr<cLayer>> m_listLayers;
};

