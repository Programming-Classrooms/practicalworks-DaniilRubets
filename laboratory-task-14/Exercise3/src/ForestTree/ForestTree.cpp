#include "../ForestTree/ForestTree.hpp"

ForestTree::ForestTree(): Tree(), woodAmount(0)
{}


ForestTree::ForestTree(std::string& str, int age, TreeType& type, int amount): Tree(str, age, type), 
woodAmount(amount)
{}


ForestTree::ForestTree(const ForestTree& rhs): Tree(rhs), woodAmount(rhs.woodAmount)
{}

ForestTree::~ForestTree()
{
	Tree::~Tree();
	woodAmount = 0;
}


int ForestTree::getWoodAmount()
{
	return this->woodAmount;
}


void ForestTree::setWoodAmount(int am)
{
	this->woodAmount = am;
}


void ForestTree::printInfo()
{
	std::cout << "FruitTree: " << '\n' << "Name: " << name << '\n' << "Age: " << age << '\n'
		<< "Type: ";
	if (type == TreeType::coniferous)
	{
		std::cout << "Coniferous";
	}
	else
	{
		std::cout << "Deciduous";
	}
	std::cout << '\n' << "Wood Amount: " << woodAmount;
}
