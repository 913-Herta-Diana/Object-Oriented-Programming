#pragma once
#include <string>
using namespace std;
class Departament {
protected:
	string hospital;
	int nbDoctors;
public:
	Departament(string hospital, int nbDoctors) : hospital{ hospital }, nbDoctors{ nbDoctors } {};
	virtual bool isEfficient()=0;
	virtual string toString()=0;
	string getHospital();
	int getNbDoctors();
};