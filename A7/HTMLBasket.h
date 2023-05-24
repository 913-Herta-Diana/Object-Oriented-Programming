#pragma once
#include "FileBasket.h"
#include <windows.h>
class HTMLBasket:
	public FileBasket
{
public:
	void saveToFile() override;
	void displayFile() override;
};

