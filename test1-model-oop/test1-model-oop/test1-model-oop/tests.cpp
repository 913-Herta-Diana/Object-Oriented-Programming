#include <iostream>
#include "domain.h"
#include "repository.h"
#include "service.h"
#include <assert.h>
using namespace std;

void test_domain()
{
	Car new_car("Fiat","Bravo",2007,"red");

	assert(new_car.GetYear()==2007);
	assert(new_car.GetName()=="Fiat");
	assert(new_car.GetColour()=="red");
	assert(new_car.GetModel()=="Bravo");
}

void test_repo()
{
	Repo repository{};
	
	//add
	Car new_car("Fiat", "Bravo", 2007, "red");
	assert(repository.add(new_car)==1);

	//remove
	Car new_car2("Audi", "A5", 2007, "blue");
	repository.add(new_car2);
	assert(repository.remove(new_car2) == 1);

	Car new_car3("Fiat", "Idea", 2003, "black");
	repository.add(new_car3);
	Car new_car4("BMW", "Coupe", 2013, "pink");
	repository.add(new_car4);
	Car new_car5("Ford", "Fiesta", 1976, "yellow");
	repository.add(new_car5);
	Car new_car6("Opel", "Corsa", 1974, "red");

	//sort colour
	std::vector<Car>sort1 = repository.sortColour();
	for (int i = 0; i < sort1.size()-1; i++)
	{
		assert(sort1[i].GetColour() < sort1[i + 1].GetColour());
	}

	//sort2
	repository.sortManufacturerandModel();
	//std::cout << repository.getCurrentCar(0).GetModel();
	assert(repository.getCurrentCar(0).GetModel() == "Bravo");
}

void test_service()
{
	Repo repository{};
	Service service{ repository };

	//init
	service.initialiseService();
	assert(service.getCurrentCarService(0).GetName() == "Fiat");
	assert(service.getCurrentCarService(0).GetYear() == 2007);
	assert(service.getCurrentCarService(0).GetColour() == "red");
	assert(service.getCurrentCarService(0).GetModel() == "Bravo");

	Car new_car6("Opel", "Corsa", 1974, "red");
	assert(service.addService(new_car6) == 1);

	Car new_car7("Audi", "A6", 2020, "grey");
	service.addService(new_car7);
	assert(service.removeService(new_car7) == 1);

	std::vector<Car> sort1 = service.sortColourService();
	for (int i = 0; i < sort1.size() - 1; i++)
	{
		assert(sort1[i].GetColour() < sort1[i + 1].GetColour());
	}

	std::vector<Car> sort2 = service.sortManufacturerModel();
	std::cout << repository.getCurrentCar(0).GetModel();
	assert(service.getCurrentCarService(0).GetModel() == "Bravo");
}