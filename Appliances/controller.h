#pragma once
#include "appliance.h"
#include <vector>
#include <fstream>
#include <algorithm>

#include "fridge.h"
#include "dishwash.h"

class Controller {
	vector<Appliance*> database;
public:
	Controller();
	bool addAppliance(Appliance* applianceToAdd);
	vector<Appliance*> showAll();
	vector<Appliance*> showAllByWeight();
	void saveToFile(string filename, double value);
	~Controller();
};