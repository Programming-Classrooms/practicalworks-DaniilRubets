#include "../Student/Student.hpp"
size_t Student::nextId(1);


Student::Student(std::string& name, int16_t cou, int16_t gr, int16_t rec):fullName(name), course(cou), group(gr), recordNumber(rec), id(nextId++)
{}


Student::Student(const Student& rhs) : fullName(rhs.fullName), course(rhs.course), group(rhs.group), recordNumber(rhs.recordNumber), id(nextId++)
{}


std::string Student::getName()
{
	return this->fullName;
}


int16_t Student::getCourse()
{
	return this->course;
}


int16_t Student::getGroup()
{
	return this->group;
}


int16_t Student::getRecordNumber()
{
	return this->recordNumber;
}


void Student::setName(std::string& str)
{
	this->fullName = str;
}


void Student::setCourse(int16_t cou)
{
	this->course = cou;
}


void Student::setGroup(int16_t gr)
{
	this->group = gr;
}


std::ostream& operator<<(std::ostream& os, const Student& rhs)
{
	os << rhs.id << ". " << rhs.fullName << '\n' << '\t' << "Course: " << rhs.course << '\n' << '\t' << "Group: " << rhs.group << '\n' << '\t' << "RecordNumber: " << rhs.recordNumber << '\n';
	return os;
}