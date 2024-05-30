#include "../Person/Person.hpp"
Person::Person()
{
	this->fullName = new char[1];
	this->fullName[0] = '\0';
}


Person::Person(const char* name)
{
	this->fullName = new char[strlen(name) + 1];
	strcpy(this->fullName, name);
}


Person::Person(const Person& rhs) 
{
	fullName = new char[strlen(rhs.fullName) + 1];
	strcpy(fullName, rhs.fullName);
}


Person::~Person()
{
	delete[]fullName;
}


Person Person::getPerson() {
	return fullName;
}


void Person::setPerson(const char* name) 
{
	delete[]fullName;
	fullName = new char[strlen(name) + 1];
	strcpy(fullName, name);
}


void Person::print() 
{
	std::cout << fullName << '\n';
}