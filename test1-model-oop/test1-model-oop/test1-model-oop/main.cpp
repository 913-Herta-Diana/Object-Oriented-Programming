#include"domain.h"
#include"repository.h"
#include"service.h"
#include "ui.h"
#include "tests.h"
#include<iostream>
using namespace std;

int main()
{
	Repo repository{};
	Service service{repository};
	UI ui{ service };
	/*test_domain();
	test_repo();
	test_service();*/
	return 0;
	//ui.run_menu();
	/*service.initialiseService();
	vector<Car>new_car = service.getCarsService();
	for (int i = 0; i < new_car.size(); i++)
	{
		cout << new_car[i].GetColour() << "\n";
	}
	Car car1("Fiat", "Bravo", 2007, "red");
	service.removeService(car1);
	new_car = service.getCarsService();
	for (int i = 0; i < new_car.size(); i++)
	{
		cout << new_car[i].GetColour() << "\n";
	}
	cout << "\n \n";
	service.sortColourService();
	new_car = service.getCarsService();
	for (int i = 0; i < new_car.size(); i++)
	{
		cout << new_car[i].GetColour() << "\n";
	}
	cout << "\n \n";
	service.sortManufacturerModel();
	new_car = service.getCarsService();
	for (int i = 0; i < new_car.size(); i++)
	{
		cout << new_car[i].GetColour() << "\n";
	}*/
	/*cout << "\n";
	Car new_car("A", "B", 2, "C");
	service.addService(new_car);
	service.getCarsService();
	cout << "\n";
	service.removeService(new_car);
	service.getCarsService();
	cout << "\n";
	service.sortColourService();
	service.getCarsService();
	cout << "\n";
	service.sortManufacturerModel();
	service.getCarsService();
	cout << "\n";*/
	/*
	return 0;*/
}