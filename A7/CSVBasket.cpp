#include "CSVBasket.h"
#include <iostream>
void CSVBasket::saveToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw AppException("Impossible to open this file!");
	cout << "csv";
	cout << this->basket.size()<<"this is the size";
	for (auto t : this->basket)
	{
		cout << "here";
		file << t << "\n";
}
	file.close();
	}

void CSVBasket::displayFile()
{
	
	string filename = this->filename;
	string aux = "\"" + filename + "\""; // if the path contains spaces, we must put it inside quotations
	//ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "C:\\Users\\herta\\Desktop\\UBB\\UBB_SEM2\\OOP\\OOP7\\basket.csv", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	string filePath = "C:\\Users\\herta\\Desktop\\UBB\\UBB_SEM2\\OOP\\OOP7\\basket.csv"; // Replace with the actual file path
	string command = "start excel \"" + filePath + "\"";
	system(command.c_str());
}
