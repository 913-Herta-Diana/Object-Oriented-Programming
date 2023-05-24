//#include "serviceUser.h"
//#include <iterator>
//#include <iostream>
//
//UserService::UserService(Repo repository)
//{
//	this->repository = repository;
//	this->basket = vector<Trench>();
//}
//
//vector<Trench> UserService::showBySize(string size)
//{
//	
//
//	vector<Trench> filteredRepo;
//	cout << repository.showAll().size();
//	//remove_copy_if(repository.showAll().begin(), repository.showAll().end(), filteredRepo.begin(), [&](const Trench current) { return current.getSize() != size; });
//	if (size == "")
//		return repository.showAll();
//	for (Trench current : repository.showAll())
//		if (current.getSize() == size)
//		{
//			cout << current.getSize() << " " << current.getColor() << "\n";
//			filteredRepo.push_back(current);
//		}
//	return filteredRepo;
//	
//}
//
//void UserService::addToBasket()
//{
//}
//
