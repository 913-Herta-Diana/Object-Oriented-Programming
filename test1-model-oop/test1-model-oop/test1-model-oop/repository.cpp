#include "repository.h"
#include <iostream>
Repo::Repo()
{
	this->repository = vector<Car>();
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
