#include <iostream>
#include "test.h"
#include "domain.h"
#include "repository.h"
#include "user.h"
using namespace std;

void testAdd()
{
	Player p1("a", "b", "c", 1);
	Player p2("d", "e", "f", 7);
	Player p3("d", "e", "f", 7);
	Repo repository;
	assert(repository.addPlayer(p1) == 1);
	assert(repository.addPlayer(p2) == 1);
	assert(repository.addPlayer(p3) == 0);
	cout << "Testing add...\n";

}

void testTeams()
{
	Player p1("a", "b", "c", 1);
	Player p2("d", "e", "f", 7);
	Player p3("x", "y", "f", 1);
	Repo repository;
	repository.addPlayer(p3);
	repository.addPlayer(p2);
	vector<Player> check;
	int index = -1;
	repository.showForTeamByGoals("f");
	for (Player current : repository.getVector())
	{
		index++;
		if (index == 5)
			assert(current.getName() == p3.getName() && current.getNationality() == p3.getNationality() && current.getTeam() == p3.getTeam() && current.getGoals() == p3.getGoals());
		else if (index==6)

			assert(current.getName() == p2.getName() && current.getNationality() == p2.getNationality() && current.getTeam() == p2.getTeam() && current.getGoals() == p2.getGoals());
	}
	assert(repository.totalGoals("f") == 8);
	cout << "Testing display by team, sorted and total goals...\n";
}
