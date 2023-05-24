#include "FileBasket.h"

FileBasket::FileBasket(): Basket {}, filename{ "" }
{
}

void FileBasket::setFilename(const string& filename)
{
	this->filename = filename;
}

