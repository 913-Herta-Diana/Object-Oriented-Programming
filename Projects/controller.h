#pragma once
#include "repository.h"
class Service {
	Repo repository;
public:
	Service(Repo repository);
	bool SVaddProject(Project newProject);
	bool SVremoveProject(Project deletedProject);
	vector<Project> SVsortByDate();
	int SVtotalCost();
	vector<Project> SVshowAll();
	vector<Project> SVsortContainingString(string keyword);
	void populate();
};