#pragma once
#include <string>
using namespace std;
class Project {
	string name, customer, dueDate;
	int cost;
	bool isDone;
public:
	Project(string name, string customer, string dueDate, int cost, bool isDone);
	string getName();
	string getCustomer();
	string getDueDate();
	int getCost();
	bool getIsDone();
};