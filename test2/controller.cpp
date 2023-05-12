#include "controller.h"

Controller::Controller()
{
	Departament* s1 = new Surgery(2,"hospital1",43);
	Departament* s2 = new Surgery(100, "hospital2", 43);
	Departament* n1 = new Neonatal(9.0, "hospital3", 43);
	Departament* n2 = new Neonatal(6.0, "hospital3", 43);
	this->addDepartment(s1);
	this->addDepartment(n1);
	this->addDepartment(s2);
	this->addDepartment(n2);
}

void Controller::addDepartment(Departament* departmentToAdd)
{
	database.push_back(departmentToAdd);
}

vector<Departament*> Controller::showAll()
{
	return this->database;
}

vector<Departament*> Controller::showEfficient()
{
	vector<Departament*> efficientDataBase;
	//copy_if(database.begin(), database.end(), back_inserter(efficientDataBase), [&](Departament* dep) {return dep->isEfficient(); });
	for(auto current: database)
		if (current->isEfficient()==true)
			efficientDataBase.push_back(current);
	return efficientDataBase;
}

void Controller::saveToFile(string filename)
{
	ofstream fout(filename);
	vector<Departament*> sorted;

	for (auto current : database)
		if(current->isEfficient()==true)
			fout << current->toString() << " | " << "is efficient" << "\n";
		else
			fout << current->toString() << " | " << "not efficient" << "\n";

}

Controller::~Controller()
{
	 
	 database.clear();
}
