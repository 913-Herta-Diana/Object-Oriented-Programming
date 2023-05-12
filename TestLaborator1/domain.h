#pragma once
#include <string>
using namespace std;
class Player {
	string name, nationality, team;
	int goals;
public:
	Player(string name, string nationality, string team, int goals);
	string getName();
	string getNationality();
	string getTeam();
	int getGoals();
};