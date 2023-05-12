#include "repository.h"
#include "exception.h"
Repo::Repo()
{
	this->repo = vector<Trench>();
	populate();
}

bool Repo::addTrench(Trench newTrench)
{
	//Adds a new Trench object to the vector repository
	//Param newTrench: Trench to be added
	//Returns true if the addition was succeesful, false otherwise
	int newQuantity;
	auto identicalTrench=std::find_if(repo.begin(), repo.end(), [&](const Trench& current) { return current.getPhoto() == newTrench.getPhoto() && current.getSize()==current.getSize(); });
		if (identicalTrench == repo.end()){
			
			repo.push_back(newTrench); 
			return true;}
		else
		{
			newQuantity = repo[identicalTrench - repo.begin()].getQuantity() + 1;
			repo[identicalTrench - repo.begin()].setQuantity(newQuantity);
			return false;}}

bool Repo::removeTrench(Trench deletedTrench)
{
	//Removes a Trench object from the vector repository
	//Param deletedTrench: Trench to be removes
	//Returns true if the addition was succeesful, false otherwise
	int newQuantity;
	auto identicalTrench = std::find_if(repo.begin(), repo.end(), [&](const Trench current) {return current.getPhoto() == deletedTrench.getPhoto() && current.getSize()==deletedTrench.getSize(); });
	if (identicalTrench == repo.end()) {
		throw AppException{ "Inexistend item!\n" };}
	else
	{
		if (repo[identicalTrench - repo.begin()].getQuantity() > 1) {
			newQuantity = repo[identicalTrench - repo.begin()].getQuantity() - 1;
			repo[identicalTrench - repo.begin()].setQuantity(newQuantity);
			return false;}
		else if (repo[identicalTrench - repo.begin()].getQuantity() == 1)
			repo.erase(identicalTrench);
		return true;}}

bool Repo::updateTrench(Trench updatedTrench)
{
	auto identicalTrench = std::find_if(repo.begin(), repo.end(), [&](const Trench current) {return current.getPhoto() == updatedTrench.getPhoto() && current.getSize() == updatedTrench.getSize(); });
	if (identicalTrench == repo.end()) 
		throw AppException{ "Inexistent item!\n" };
	
	else
	{
		repo[identicalTrench - repo.begin()] = updatedTrench;
		return true;}}

vector<Trench> Repo::showAll()
{
	
	return this->repo;

}


void Repo::populate()
{
	Trench t1("S", "RED", 99.9, 20, "https://mygeisha.vtexassets.com/arquivos/ids/155792-800-auto?v=637986290297170000&width=800&height=auto&aspect=true");
	Trench t2("M", "ORANGE", 523.5, 1, "https://static.massimodutti.net/3/photos/2023/V/0/1/p/6723/612/710/6723612710_1_1_3.jpg?t=1675264391384");
	Trench t3("L", "YELLOW", 211.7, 30, "https://cdn-img.prettylittlething.com/d/1/f/b/d1fb4e552760f659d6e361c799672a8e2c321030_cmn4938_1.jpg");
	Trench t4("XL", "GREEN", 398.1, 2, "https://hips.hearstapps.com/hmg-prod/images/besttrenchcoatwomen-6401d7cd4de17.jpg");
	Trench t5("XXL", "BLUE", 400.6, 10, "https://cdn.shopify.com/s/files/1/0459/6118/3387/products/221215_Aligne_Ecom_GILDA_STONE_316.jpg?v=1682436159");
	Trench t6("S", "RED", 99.99, 2, "https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.prettylittlething.com%2Fkhaki-woven-hooded-oversized-trench-coat.html&psig=AOvVaw2bAxwhHQO35T2ZFw9qd6Vs&ust=1683177985560000&source=images&cd=vfe&ved=0CBEQjRxqFwoTCIjrw-G02P4CFQAAAAAdAAAAABAs");
	Trench t7("M", "ORANGE", 523.5, 1, "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTX_eP3WfwZMh7IyQu8PLxfdpI3MznrS_lv2A&usqp=CAU");
	Trench t8("L", "YELLOW", 211.7, 30, "https://www.moja.ro/storage/2022/05/40373/c/5-large.jpg");
	Trench t9("XL", "GREEN", 398.1, 2, "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcT7X9-29eDhjWf9tGVn6fzrpXOh0Y7jne5brw&usqp=CAU");
	Trench t10("XXL", "BLUE", 400.6, 10, "https://m.media-amazon.com/images/I/71hD32fhPJL._AC_UY1000_.jpg");
	addTrench(t1);
	addTrench(t2);
	addTrench(t3);
	addTrench(t4);
	addTrench(t5);
	addTrench(t6);
	addTrench(t7);
	addTrench(t8);
	addTrench(t9);
	addTrench(t10);
}

