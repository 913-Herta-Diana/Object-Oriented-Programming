#pragma once
#include "appliance.h"
#include <string>
using namespace std;
class Refrigerator :
	public Appliance
{
	string electricityUsageClass;
	bool hasFreezer;
public:
	Refrigerator(string id, double weight, string electricityUsage, bool hasFreezer) : Appliance{id,weight}, electricityUsageClass { electricityUsage }, hasFreezer{ hasFreezer } {};
	double consumedElectricy() override;
	string toString() override;
	string getElectricityUsageClass() const;
	bool getHasFreezer() const;
};