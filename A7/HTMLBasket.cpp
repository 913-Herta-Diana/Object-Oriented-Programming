#include "HTMLBasket.h"
#include "FileBasket.h"
#include <iostream>
void HTMLBasket::saveToFile()
{
	ofstream file(this->filename);
	file << "<!DOCTYPE html>\n<html>\n<head>\n<title>Trench Information</title>\n</head>\n<body>\n";
	file << "<table border=\"1\">\n<tr>\n<td>Size</td>\n<td>Color</td>\n<td>Price</td>\n<td>Photo</td>\n</tr>\n";

	for (Trench t : this->getBasket())
	{
		cout << "got here";
		file << "<tr>\n<td>" << t.getSize() << "</td>\n<td>" << t.getColor() << "</td>\n<td>" << to_string(t.getPrice()) << "</td>\n<td>" << to_string(t.getQuantity()) << "</td>\n<td><img src=\"" << t.getPhoto() << "\" alt=\"Trench photo\" height=\"100\"></td>\n</tr>\n";
		
	}
	file.close();
}

void HTMLBasket::displayFile()
{
	LPCTSTR helpFile = TEXT("C:\\Users\\herta\\Desktop\\UBB\\UBB_SEM2\\OOP\\OOP7\\basket.html");
	ShellExecute(NULL, L"open", helpFile, NULL, NULL, SW_SHOWNORMAL);
	system("PAUSE");
	/*ShellExecute(NULL, "open", "C:\\Users\\herta\\Desktop\\UBB\\UBB_SEM2\\OOP\\OOP7\\basket.html",NULL, NULL, SW_SHOWNORMAL);*/
}
