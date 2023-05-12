#include "controller.h"
Controller::Controller()
{
	Appliance* fridge1 = new Refrigerator("B1",20.5,"A+",false);
	Appliance* fridge2 = new Refrigerator("Vladimirescu", 1200, "A", true);
	Appliance* fridge3= new Refrigerator("Curtici", 1300, "A++", true);

	Appliance* dish1 = new DishWasher("Cluj-Napoca", 1960, 50, "47");
	Appliance* dish2 = new DishWasher("Dej", 1960, 90, "85");
	Appliance* dish3 = new DishWasher("Baia Mare", 1960, 100, "3");

	this->addAppliance(fridge1);
	this->addAppliance(fridge2);
	this->addAppliance(fridge3);

	this->addAppliance(dish1);
	this->addAppliance(dish2);
	this->addAppliance(dish3);
}
bool Controller::addAppliance(Appliance* applianceToAdd)
{
	for (auto current : database)
		if (current->getID() == applianceToAdd->getID())
			return false;
	database.push_back(applianceToAdd);
	return true;
}

vector<Appliance*> Controller::showAll()
{
	return database;
}

vector<Appliance*> Controller::showAllByWeight()
{
	std::sort(
		database.begin(),
		database.end(),
		[](Appliance* appliance1, Appliance* appliance2) { return appliance1->getWeight() < appliance2->getWeight(); }
	);

	return database;
}

void Controller::saveToFile(string filename, double value)
{
	ofstream fout(filename);
	vector<Appliance*> appliances;
	copy_if(database.begin(), database.end(), back_inserter(appliances), [&](Appliance* app) {return app->consumedElectricy() < value; });
	for (auto current : appliances)
	fout << current->toString() << "\n";
		
	fout.close();
}

Controller::~Controller()
{
	this->database.erase(this->database.begin(), this->database.end());
	this->database.clear();
}
