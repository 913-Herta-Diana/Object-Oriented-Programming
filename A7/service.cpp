#include "service.h"
#include "exception.h"
#include <fstream>
#include <iostream>

Service::Service(Repo repository,FileBasket* file)
{
	this->repository = repository;
	this->file = file;
	//this->basket = vector<Trench>();
}
void Service::setFileType(FileBasket* file)
{
	this->file = file;
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

	return this->file->getBasket();
}

void Service::SVaddToBasket(Trench& addedTrench)
{
	if (this->file == nullptr)
		return;
	this->file->add(addedTrench);
	/*basket.push_back(addedTrench);*/
}



float Service::SVseeTotalPrice()
{
	float totalSum = 0;
	for (Trench current : file->getBasket())
		totalSum += current.getPrice();
	return totalSum;

}

void Service::startBasket()
{
	if (this->file == nullptr)
		return;
	this->file->see();
}

void Service::nextSongBasket()
{
	if (this->file == nullptr)
		return;
	this->file->next();
}

//void Service::saveBasket(const std::string& filename)
//{
//	if (this->file == nullptr)
//		return;
//
//	this->file->setFilename(filename);
//	this->file->saveToFile();
//}



void Service::SVsaveToFile(string filename)
{
	if (this->file == nullptr)
	{
		cout << "null";
		return;
	}

	this->file->setFilename(filename);
	cout << "ser";
	this->file->saveToFile();
	this->file->displayFile();
	cout << "saved";
}
//void Service::SVsaveToCSV()
//{
//	if (file == nullptr)
//		return;
//	this->file->setFilename("basket.csv");
//	file->saveToFile();
//}
//
//void Service::SVsaveToHTML()
//{
//	if (file == nullptr)
//		return;
//	this->file->setFilename("basket.csv");
//	file->saveToFile();
//}



