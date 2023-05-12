#pragma once
#include "domain.h"
#include <vector>
class Repo {
	vector<Project> repo;
public:
	Repo();
	bool addProject(Project newProject);
	bool removeProject(Project deletedProject);
	void sortByDate();
	int totalCost();
	vector<Project> showAll();
	vector<Project> sortContainingString(string keyword);
	vector<Project> getProjects();
};