#pragma once
#include "departament.h"
class Surgery :
	public Departament
{
	int nbPatients;
public:
	Surgery(int nbPatients, string hospital, int nbDoctors) : Departament{ hospital,nbDoctors }, nbPatients{ nbPatients } {};
	int getnbPatients();
	bool isEfficient() override;
	string toString() override;
};