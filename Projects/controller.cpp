#include "controller.h"


Service::Service(Repo repository)
{
	this->repository = repository;
	populate();
}

void Service::populate()
{
	Project p1("Stairs","Flin","20.08.2019",1,false);
	Project p2("name", "DeToate", "20.08.2015", 1, true);
	Project p3("MEna", "Valuations", "01.09.2018", 1, false);
	Project p4("Data Archiving", "Spitalul Judetean", "06.06.2016", 1, false);
	Project p5("Website", "Spitalul Judetean", "06.01.2017", 1, true);

	repository.addProject(p1);
	repository.addProject(p2);
	repository.addProject(p3);
	repository.addProject(p4);
	repository.addProject(p5);
}


bool Service::SVaddProject(Project newProject)
{
	return this->repository.addProject(newProject);
}

bool Service::SVremoveProject(Project deletedProject)
{
	return this->repository.removeProject(deletedProject);
}

vector<Project> Service::SVsortByDate()
{
	this->repository.sortByDate();
	return this->repository.getProjects();
}

int Service::SVtotalCost()
{
	return this->repository.totalCost();
}

vector<Project> Service::SVshowAll()
{
	return this->repository.showAll();
}

vector<Project> Service::SVsortContainingString(string keyword)
{
	return this->repository.sortContainingString(keyword);
}
