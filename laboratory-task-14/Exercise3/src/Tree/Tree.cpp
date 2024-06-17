#include "../Tree/Tree.hpp"

Tree::Tree():name(nullptr), age(0),type(TreeType::coniferous)
{}


Tree::Tree(std::string& nam, int ag, TreeType& typ):name(nam), age(ag), type(typ)
{}

Tree::Tree(const Tree& rhs):name(rhs.name), age(rhs.age), type(rhs.type)
{}


Tree::~Tree()
{
	name = nullptr;
	age = 0;
	type = TreeType::coniferous;
}


std::string Tree::getName()
{
	return this->name;
}


int Tree::getAge()
{
	return this->age;
}


TreeType Tree::getType()
{
	return this->type;
}


void Tree::setName(std::string& str)
{
	this->name = str;
}


void Tree::setAge(int ag)
{
	this->age = ag;
}

void Tree::setType(TreeType& typ)
{
	this->type = typ;
}
