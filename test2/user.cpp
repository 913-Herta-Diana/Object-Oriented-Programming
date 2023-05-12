#include "user.h"
#include<iostream>
void User::UIadd()
{
	string type;
	cout << "Insert type: ";
	cin >> type;
	if (type == "neonatal")
	{
		string hospital;
		int nbDoctors;
		double averageGrade;
		cout << "Insert hosp: ";
		cin >> hospital;
		cout << "Insert doct: ";
		cin >> nbDoctors;
		cout << "Insert grade: ";
		cin >> averageGrade;
		Departament* dep = new Neonatal(averageGrade, hospital, nbDoctors);
		service.addDepartment(dep);



	}
	else if (type == "surgery")
	{
		string hospital;
		int nbDoctors;
		int nbPatients;
		cout << "Insert hosp: ";
		cin >> hospital;
		cout << "Insert doct: ";
		cin >> nbDoctors;
		cout << "Insert nbPat: ";
		cin >> nbPatients;
		Departament* dep = new Surgery(nbPatients, hospital, nbDoctors);
		service.addDepartment(dep);
	}
}

void User::UIshowAll()
{
	for (auto current : service.showAll())
		cout << current->toString()<<"\n";
}

void User::UIshowEfficient()
{
	for (auto current : service.showEfficient())
		cout << current->toString() << "\n";

}

void User::UIsaveToFile()
{
	string name;
	cout << "Insert file name: ";
	cin >> name;
	service.saveToFile(name);
}

void User::runMenu()
{
	int command;
	cout << "Menu:\n";
	while (1)
	{
		cout << "1 for add\n2 for show all\n3 for show efficient\n4 for save to file\n0 for exit\n\3";
		cin >> command;
		if (command == 1)
			UIadd();
		else if (command == 2)
			UIshowAll();
		else if (command == 3)
			UIshowEfficient();
		else if (command == 4)
			UIsaveToFile();
		else if (command == 0)
			break;
	}
}

