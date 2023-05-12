#pragma once
#include "departament.h"
class Neonatal :
	public Departament
{
	double averageGradeNewBorns;
public:
	Neonatal(double averageGradeNewBorns,string hospital, int nbDoctors) : Departament{ hospital,nbDoctors }, averageGradeNewBorns{ averageGradeNewBorns } {};
	double getAverageGradeNewBorn();
	bool isEfficient() override;
	string toString() override;
};