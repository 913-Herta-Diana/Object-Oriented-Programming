#include "user.h"

void User::UIadd()
{
	cout << "Insert type of appliance: \n";
	std::string type;
	cin >> type;
	if (type == "Fridge")
	{
		string id;
		cout << "ID is: \n";
		cin >> id;
		double weight;
		cout << "Weight: \n";
		cin >> weight;
		string eclass;
		cout << "Energy class is: \n";
		cin >> eclass;
		bool has;
		cout << "Freezer class is: \n";
		cin >> has;
		Appliance* data = new Refrigerator(id, weight,eclass,has);
		if (service.addAppliance(data) == 0)
		{
			cout << "Fridge already exists! \n";
			return;
		}
		else
		{
			cout << "fridge added! " << "\n";
		}
	}
	else if (type == "Dishwasher")
	{
		string id;
		cout << "ID is: \n";
		cin >> id;
		double weight;
		cout << "Weight: \n";
		cin >> weight;
		double Cycle;
		cout << "Cycle  is: \n";
		cin >> Cycle;
		string hour;
		cout << "Hour is: \n";
		cin >> hour;
		Appliance* data = new DishWasher(id, weight, Cycle, hour);
		if (service.addAppliance(data) == 0)
		{
			cout << "DishWasher already exists! \n";
			return;
		}
		else
			cout << "Dishwasher added! " << "\n";
	}
}

void User::UIshowAll()
{
	for (auto current : service.showAll())
		cout << current->toString() << "\n";
}

void User::UIshowAllByWeight()
{
	for (auto current : service.showAllByWeight())
		cout << current->toString() << "\n";
}

void User::UIsaveToFile()
{
	string filename;
	cout << "Insert file name: \n";
	cin >> filename;
	double value;
	cout << "Insert value: \n";
	cin >> value;
	service.saveToFile(filename, value);
	cout << "Successfully added to the file \n";

}

void User::runMenu()
{
	int run = 1;

	while (run)
	{
		int command;
		cout << "Insert command: ";
		cin >> command;
		switch (command)
		{
		case 0:
			run = 0;
			break;
		case 1:
			UIadd();
			break;
		case 2:
			UIshowAll();
			break;
		case 3:
			UIshowAllByWeight();
			break;
		case 4:
			UIsaveToFile();
			break;
		}

	}
}
