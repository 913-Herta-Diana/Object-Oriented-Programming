#pragma once
#include "FileBasket.h"
class CSVBasket: public FileBasket
{

	public:

		void saveToFile() override;
		void displayFile() override;

};

