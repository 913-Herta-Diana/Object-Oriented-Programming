#pragma once
#include "appliance.h"
#include <string>
using namespace std;
class DishWasher :
	public Appliance
{
	double washingCycleLength;
	string consumedElectricityPerHour;
public:
	DishWasher(string id, double weight, double washingCycleLength, string consumedElectricityPerHour) : Appliance{ id,weight }, washingCycleLength{ washingCycleLength }, consumedElectricityPerHour{ consumedElectricityPerHour } {};
	double getWashingLength() const;
	string getConsumerElectricity() const;
	double consumedElectricy() override;
	string toString() override;
};