#include "repository.h"
#include <algorithm>
Repo::Repo()
{
	this->repo = vector<Project>();
}

bool Repo::addProject(Project newProject)
{
	/*Adds new project to the vector repository, return true if it was added
		or false if the Project already exists.*/
	for (Project currentProject : repo)
		if (currentProject.getName() == newProject.getName() && currentProject.getCustomer() == newProject.getCustomer())
			return false;
	repo.push_back(newProject);
	return true;
}

	

bool Repo::removeProject(Project deletedProject)
{
	int index=-1;
	for (Project currentProject : repo)
	{
		index++;
		if (currentProject.getName() == deletedProject.getName() && currentProject.getCustomer() == deletedProject.getCustomer())
			break;
	}
	if (index != -1)
	{
		for (int i = index; i < repo.size() - 1; i++)
			repo[i] = repo[i + 1];
		repo.pop_back();
		return true;
	}

	return false;
			
}


void Repo::sortByDate()

{
	string date1, date2;
	string separator = ".";
	for (int i = 0; i < repo.size() - 1; i++)
		for (int j = i + 1; j < repo.size(); j++)
		{
			date1 = repo[i].getDueDate();
			date2 = repo[j].getDueDate();

			int day1, month1, year1, day2, month2, year2;
			day1 = stoi(date1.substr(0, date1.find(separator)));
			date1 = date1.substr(date1.find_last_of(separator) + 1);
			month1 = stoi(date1.substr(0, date1.find(separator)));
			year1 = stoi(date1.substr(date1.find(separator) + 1));

			day2 = stoi(date2.substr(0, date2.find(separator)));
			date2 = date2.substr(date2.find(separator) + 1);
			month2 = stoi(date2.substr(0, date2.find(separator)));
			year2 = stoi(date2.substr(date2.find(separator) + 1));

			if (year1 > year2)
				swap(repo[i], repo[j]);
			else if (month1 > month2) 
				swap(repo[i], repo[j]);
			else if(day1 > day2)
				swap(repo[i], repo[j]);
		}
	
}

int Repo::totalCost()
{
	/*Iterates through the vector of Projects and return the total cost of them.*/
	int total = 0;
	for (Project currentProject : repo)
		total += currentProject.getCost();
	return total;

}

vector<Project> Repo::showAll()
{
	return repo;
}

vector<Project> Repo::sortContainingString(string keyword)
{
	vector<Project> sortedRepo;
	for (Project currentProject : repo)
		if (currentProject.getName().find(keyword) != std::string::npos)
			sortedRepo.push_back(currentProject);

	for (int i = 0; i < sortedRepo.size() - 1; i++)
		for (int j = i + 1; j < sortedRepo.size(); j++)
		{
			if (sortedRepo[i].getCustomer() > sortedRepo[j].getCustomer())
				swap(sortedRepo[i], sortedRepo[j]);
		}
	return sortedRepo;
}

vector<Project> Repo::getProjects()
{
	return this->repo;
}
