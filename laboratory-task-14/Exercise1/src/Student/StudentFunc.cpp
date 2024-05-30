#include "../Student/Student.hpp"

Student::Student() : Person(nullptr), course(0), group(0)
{}


Student::Student(const char* name, int32_t x, int32_t y)
{
	this->fullName = new char[strlen(name) + 1];
	strcpy(this->fullName, name);
	course = x;
	group = y;
}


Student::Student(const char* name, const Student& rhs) 
{
	this->fullName = new char[strlen(name) + 1];
	strcpy(this->fullName, name);
	course = rhs.course;
	group = rhs.group;
}


Student::~Student()
{
	course = 0;
	group = 0;
}


int32_t Student::getCourse()
{
	return course;
}


int32_t Student::getGroup()
{
	return group;
}



int32_t Student::setCourse(int32_t x)
{
	return course = x;
}



int32_t Student::setGroup(int32_t x)
{
	return group = x;
}


void Student::print()
{
	std::cout << "Student name: ";
	Person::print();
	std::cout << "Course: " << course << '\n' << "Group: " << group << '\n';
}
