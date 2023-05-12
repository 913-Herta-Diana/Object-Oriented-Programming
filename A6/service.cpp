#include "service.h"
//TODO: VALIDATIONS!!!!!!!!!!!!!!

Service::Service(Repo repository)
{
	this->repository = repository;
	this->basket = vector<Trench>();
}
bool Service::SVadd(Trench newTrench)
{
	
	return this->repository.addTrench(newTrench);
}

bool Service::SVremove(Trench removedTrench)
{
	return this->repository.removeTrench(removedTrench);
}

bool Service::SVupdate(Trench updatedTrench)
{
	return this->repository.updateTrench(updatedTrench);
}

vector<Trench> Service::SVshowAll()
{

	return this->repository.showAll();

}

vector<Trench> Service::SVshowBySize(string size)
{


	vector<Trench> filteredRepo;
	//remove_copy_if(repository.showAll().begin(), repository.showAll().end(), filteredRepo.begin(), [&](const Trench current) { return current.getSize() != size; });
	if (size.empty()) //TODO: HOW TO EMPTY
		return repository.showAll();
	for (Trench current : repository.showAll())
		if (current.getSize() == size)
			filteredRepo.push_back(current);
		
	return filteredRepo;

}

vector<Trench> Service::SVgetBasket()
{
	return this->basket;
}

void Service::SVaddToBasket(Trench addedTrench)
{
	basket.push_back(addedTrench);
}



float Service::SVseeTotalPrice()
{
	float totalSum = 0;
	for (Trench current : basket)
		totalSum += current.getPrice();
	return totalSum;

}
