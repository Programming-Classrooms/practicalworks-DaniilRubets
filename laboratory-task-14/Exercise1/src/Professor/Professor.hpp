#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "../Person/Person.hpp"

class Professor : Person
{
private:
	char* department;
public:
	Professor();
	Professor(const char*, const char*);
	Professor(const Professor&);
	~Professor() override;

	const char* getDepartment();
	void setDepartment(const char*);

	void print() override;
};

#endif //PROFESSOR_H