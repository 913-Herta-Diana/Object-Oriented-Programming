#pragma once
#include "departament.h"
#include "neonatal.h"
#include "surgery.h"
#include <vector>

#include <iterator>
#include <fstream>
class Controller {
	vector<Departament*> database;
public:
	Controller();
	void addDepartment(Departament* departmentToAdd);
	vector<Departament*> showAll();
	vector<Departament*> showEfficient();
	void saveToFile(string filename);
	~Controller();
};