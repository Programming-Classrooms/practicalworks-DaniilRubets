#include "../FruitTree/FruitTree.hpp"


FruitTree::FruitTree():Tree(),harvestWeight(0.0), storageDuration(0)
{}


FruitTree::FruitTree(std::string str, int age, TreeType& type, double weight, int duration):
	Tree(str,age,type),harvestWeight(weight), storageDuration(duration)
{}


FruitTree::FruitTree(const FruitTree& rhs): Tree(rhs), harvestWeight(rhs.harvestWeight), storageDuration(rhs.storageDuration)
{}


FruitTree::~FruitTree()
{
	Tree::~Tree();
	harvestWeight = 0;
	storageDuration = 0;
}


double FruitTree::getHarvestWeight()
{
	return this->harvestWeight;
}


int FruitTree::getStorageDuration()
{
	return this->storageDuration;
}


void FruitTree::setHarvestWeight(double weight)
{
	this->harvestWeight = weight;
}


void FruitTree::setStorageDuration(int duration)
{
	this->storageDuration = duration;
}


void FruitTree::printInfo()
{
	std::cout << "FruitTree: " << '\n' << "Name: " << name << '\n' << "Age: " << age << '\n'
		<< "Harvest Weight: " << harvestWeight << "Storage Duration: " << storageDuration;
}
