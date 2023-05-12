#include "domain.h"

Project::Project(string name, string customer, string dueDate, int cost, bool isDone) 
{
	this->name = name;
	this->customer = customer;
	this->dueDate = dueDate;
	this->cost = cost;
	this->isDone = isDone;
}
string Project::getName()
{
	return this->name;
}

string Project::getCustomer()
{
	return this->customer;
}

string Project::getDueDate()
{
	return this->dueDate;
}

int Project::getCost()
{
	return this->cost;
}

bool Project::getIsDone()
{
	return this->isDone;
}
