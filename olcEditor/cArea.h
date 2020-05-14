#pragma once


#include "cLayer.h"

class cArea
{
public:
	cArea();
	virtual ~cArea();

	std::vector<std::shared_ptr<cLayer>> vecLayers;
};

