#pragma once
#include "Basket.h"
#include <fstream>
#include "exception.h"
#include <Windows.h>
class FileBasket : public Basket 
{
	protected:
		std::string filename;
		
	public:
		FileBasket();
		virtual ~FileBasket() {}

		void setFilename(const string& filename);
		virtual void saveToFile() = 0;
		virtual void displayFile() = 0;

	};


