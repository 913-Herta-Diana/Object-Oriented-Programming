#include "repository.h"

Repo::Repo()
{
	vector<Player>();
	populate();
}


bool Repo::addPlayer(Player newPlayer)
{
	//Adds a new Player object to the vector repository
	//Param nePlayer: player to be added
	//Returns true if the addition was succeesful, false otherwise
	for (Player current : repo)
		if (current.getName() == newPlayer.getName())
			return false;

	repo.push_back(newPlayer);
	return true;
}

vector<Player> Repo::displayAll()
{
	return this->repo;
}

vector<Player> Repo::showForTeamByGoals(string keyword)
{	//Param keyword: team to select players from
	//Return a vector of Player object with the same team
	vector<Player> sortedRepo;
	
	for (Player current : repo)
		if (current.getTeam() == keyword)
			sortedRepo.push_back(current);
		
	for (int i=0; i < sortedRepo.size() - 1; i++)
		for (int j = i + 1; j < sortedRepo.size(); j++)
			if (sortedRepo[i].getGoals() > sortedRepo[j].getGoals())
				swap(sortedRepo[i], sortedRepo[j]);
	
	

	return sortedRepo;
}

int Repo::totalGoals(string keyword)
{
	//Param keyword: team to select players from
	//Returns int value representing the total goals scored by the team
	int totalGoals = 0;
	for (Player current : repo)
		if (current.getTeam() == keyword)
			totalGoals += current.getGoals();
	return totalGoals;
}

vector<Player> Repo::getVector()
{
	return this->repo;
}

void Repo::populate()
{
	Player p1("Nora_Mork", "NOR", "Larvik", 83);
	Player p2("Isabelle_Gulden", "SWE", "CSM_Bucurest", 80);
	Player p3("Cristina_Neagu", "ROU", "Buducnost", 63);
	Player p4("Allison_Pineau", "FRA", "HCM_Baia_Mare", 82);
	Player p5("Nerea_Perea", "ESP", "FTC-Rail_Cargo_Hungaria", 59);
	addPlayer(p1);
	addPlayer(p2);
	addPlayer(p3);
	addPlayer(p4);
	addPlayer(p5);
}
