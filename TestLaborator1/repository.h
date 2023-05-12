#pragma once
#include "domain.h"
#include <vector>
class Repo {
	vector<Player> repo;
public:
	Repo();
	bool addPlayer(Player newPlayer);
	vector<Player> displayAll();
	vector<Player> showForTeamByGoals(string keyword);
	int totalGoals(string keyword);
	vector<Player> getVector();
	void populate();


};