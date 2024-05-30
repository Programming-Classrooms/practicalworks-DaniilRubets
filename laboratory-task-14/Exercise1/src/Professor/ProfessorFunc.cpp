#include "../Professor/Professor.hpp"

Professor::Professor(): Person(nullptr)
{
	department = new char[1];
	department[0] = '\0';
}


Professor::Professor(const char* name, const char* dep)
{
	this->fullName = new char[strlen(name) + 1];
	strcpy(this->fullName, name);
	department = new char[strlen(dep) + 1];
	strcpy(department, dep);
}


Professor::Professor(const Professor& rhs)
{
	this->fullName = new char[strlen(rhs.fullName) + 1];
	strcpy(this->fullName, rhs.fullName);
	department = new char[strlen(rhs.department) + 1];
	strcpy(department, rhs.department);
}


Professor::~Professor()
{
	delete[]department;
}


const char* Professor::getDepartment()
{
	return department;
}


void Professor::setDepartment(const char* dep)
{
	delete[]department;
	department = new char[strlen(dep) + 1];
	strcpy(department, dep);
}


void Professor::print()
{
	std::cout << "Professor name: ";
	Person::print();
	std::cout << "Department: " << department;
}