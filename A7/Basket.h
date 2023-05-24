#pragma once
#include "domain.h"
#include <vector>
class Basket
{
protected:
	std::vector<Trench> basket;
	int current;

public:
	Basket();

	vector<Trench> getBasket();
	// Adds a song to the playlist.
	void add(const Trench& trench);

	// Returns the song that is currently playing.
	Trench getCurrentTrench();

	// Starts the playlist - plays the first song.
	void see();

	// Plays the next song in the playlist.
	void next();

	// Checks if the playlist is empty.
	bool isEmpty();

	//virtual ~Basket() {}

};

