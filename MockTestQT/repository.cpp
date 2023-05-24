#define _CRT_SECURE_NO_WARNINGS

#include "repository.h"
#include <iostream>
#include <fstream>
#include <cstring>
Repo::Repo()
{
	this->repository = vector<Car>();
	readFromFile();
}

void Repo::readFromFile()
{/*
	ifstream filein("cars.txt");
	string eachLine;
	Car c;
	while (filein >> eachLine)
	{
		repository.push_back(c);
	}
	filein.close();*/

	std::ifstream openFile("cars.txt");

	std::string line;

	while (openFile >> line)
	{
		std::string manufacturer = "-1", model = "-1", colour = "-1";
		int year = -1;

		char lineChar[100];
		std::strcpy(lineChar, line.c_str());

		char* attribute = strtok(lineChar, "|");

		while (attribute != NULL)
		{
			if (manufacturer == "-1")
				manufacturer = std::string(attribute);
			else if (model == "-1")
				model = std::string(attribute);
			else if (year == -1)
				year = std::atoi(attribute);
			else if (colour == "-1")
				colour = std::string(attribute);

			attribute = std::strtok(NULL, "|");
		}

		Car newCar(manufacturer, model, year, colour);

		this->repository.push_back(newCar);
	}

	openFile.close();
}

bool Repo::add(Car new_car)
{
	for (auto current_car : this->repository) {
		if (current_car.GetModel() == new_car.GetModel() && current_car.GetYear() == new_car.GetYear())
		{
			return false;
		}
	}
	this->repository.push_back(new_car);
	return true;
}

bool Repo::remove(Car new_car)
{
	int index = -1;
	for (int i = 0; i < sizeof(this->repository);i++) {
		if (repository[i].GetModel() == new_car.GetModel() && repository[i].GetYear() == new_car.GetYear())
		{
			index = i;
			break;
		}
	}
	if (index != -1) {
		for (int i = index; i < this->repository.size()-1; i++)
		{
			this->repository[i] = this->repository[i + 1];
		}
		repository.pop_back();
		return true;
	}
	return false;
}

vector<Car> Repo::sortColour()
{
	//declare a new vector -> stores the vintage cars
	vector<Car>new_repository;
	for (int i = 0; i < this->repository.size(); i++)
	{
		if (2023-repository[i].GetYear() > 45)
		{
			new_repository.push_back(repository[i]);
		}
	}
	//sort by colour
	for (int i = 0; i < new_repository.size() - 1; i++)
	{
		for (int j = i + 1; j < new_repository.size(); j++)
		{
			if (new_repository[i].GetColour()>new_repository[j].GetColour())
			{
				swap(new_repository[i],new_repository[j]);
			}
		}
	}
	return new_repository;
}

void Repo::sortManufacturerandModel()
{
	//sort by model
	for (int i = 0; i < this->repository.size() -1; i++)
	{
		for (int j = i + 1; j < this->repository.size(); j++)
		{
			if (repository[i].GetModel() > repository[j].GetModel() && repository[i].GetName() > repository[j].GetName())
			{
				swap(repository[i], repository[j]);
			}
		}
	}
}

vector<Car> Repo::getCars()
{
	return this->repository;
}

int Repo::getSize()
{
	return this->repository.size();
}

Car Repo::getCurrentCar(int position)
{
	return this->repository[position];
}
