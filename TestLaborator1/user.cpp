#include "user.h"
#include <iostream>
using namespace std;

void User::UIadd()
{
	string name, nationality, team;
	int goals;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter nationality: ";
	cin >> nationality;
	cout << "Enter team: ";
	cin >> team;
	cout << "Enter goals: ";
	cin >> goals;
	cin.get();
	cout << "\n";
	if (repository.addPlayer(Player(name, nationality, team, goals)) == 1)
		cout << "Successfully added!\n";
	else
		cout << "Already there!\n";


}

void User::UIdisplayAll()
{
	for (Player current : repository.getVector())
		cout << current.getName() << " | " << current.getNationality() << " | " << current.getTeam() << " | " << current.getGoals()<<"\n";
}

void User::UIshowByTeam()
{
	string team;
	cout << "Enter team: ";
	cin >> team;
	for(Player current: repository.showForTeamByGoals(team))
		cout << current.getName() << " | " << current.getNationality() << " | " << current.getTeam() << " | " << current.getGoals() << "\n";
	cout << "Total goals: " << repository.totalGoals(team)<<"\n";


}
void printMenu()
{
	cout << "1.Add\n2.Show all\n3.Show by team + total goals\n";
}
void User::runMenu()
{
	int command;
	while (true) 
	{
		printMenu();
		cout << "Enter command: ";
		cin >> command;
		if (command == 1)
			UIadd();
		else if (command == 2)
			UIdisplayAll();
		else if (command == 3)
			UIshowByTeam();
		else if (command == 0)
			break;

	}
}
