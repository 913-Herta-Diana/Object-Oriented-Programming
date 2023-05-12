#include "user.h"
#include <iostream>

using namespace std;


void printMenu()
{
	cout << "1.Add Project\n2.Remove Project\n3.Show sorted by date\n4.Total Cost\n5.Show that contain given string, descending\n6.Show all\n0.Exit\n";
}
void UserInterface::UIadd()
{
	cout << "Enter name:";
	string name;
	cin >> name;
	cout << "Enter customer:";
	string customer;
	cin >> customer;
	cout << "Enter dueDate:";
	string dueDate;
	cin >> dueDate;
	cout << "Enter cost:";
	int cost;
	cin >> cost;
	cout << "Enter isDone:";
	bool isDone;
	cin >> isDone;
	cin.get();
	if (service.SVaddProject(Project(name, customer, dueDate, cost, isDone)) == true) {
		cout << "Project added\n";
	}
	else {
		cout << "Project already exists\n";
	}
}

void UserInterface::UIremove()
{
	cout << "Enter name:";
	string name;
	cin >> name;
	cout << "Enter customer:";
	string customer;
	cin >> customer;
	cout << "Enter dueDate:";
	string dueDate;

	cin >> dueDate;
	cout << "Enter cost:";
	int cost;
	cin >> cost;
	cout << "Enter isDone:";
	bool isDone;
	cin >> isDone;
	cin.get();
	if (service.SVremoveProject(Project(name, customer, dueDate, cost, isDone)) == true) {
		cout << "Project removed\n";
	}
	else {
		cout << "Project doesn't exists\n";
	}
}

void UserInterface::UIshowSort()
{
	for(Project current: service.SVsortByDate())
		cout << current.getName() << ";" << current.getCustomer() << ";" << current.getDueDate() << ";" << current.getCost() << ";" << current.getIsDone()<<"\n";

}

void UserInterface::UICost()
{
	cout<<"The total cost is: "<<service.SVtotalCost()<<"\n";
}

void UserInterface::UIStringMatch(string keyword)
{
	for (Project current : service.SVsortContainingString(keyword))
		cout << current.getName() << ";" << current.getCustomer() << ";" << current.getDueDate() << ";" << current.getCost() << ";" << current.getIsDone()<<"\n";


}

void UserInterface::UIshowAll()
{
	cout << "Im here";
	for (Project current : service.SVshowAll())
		cout << current.getName() << ";" << current.getCustomer() << ";" << current.getDueDate() << ";" << current.getCost() << ";" << current.getIsDone()<<"\n";
}


void UserInterface::runMenu()
{
	
	while (true)
	{
		printMenu();
		int command;
		cout << "Insert command: ";
		cin >> command;
		if (command == 1)
			UIadd();
		else if (command == 2)
			UIremove();
		else if (command == 3)
			UIshowSort();
		else if (command == 4)
			UICost();
		else if (command == 5)

		{
			string keyword;
			cout << "Insert keyword: ";
			cin >> keyword;
			UIStringMatch(keyword);
		}
		else if (command == 6)
			UIshowAll();
		else if (command == 0)
			break;

	
			
	}
}
