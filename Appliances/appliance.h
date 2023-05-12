#pragma once
#include <string>
using namespace std;
class Appliance {
protected:
	string id;
	double weight;
public:
	Appliance(string id, double weight) : id{ id }, weight{ weight } {};
	string getID();
	double getWeight();
	virtual double consumedElectricy() = 0;
	virtual string toString() = 0;
};