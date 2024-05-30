#ifndef PERSON_H
#define PERSON_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
class Person 
{
protected:
	char* fullName;
public:
	Person();
	Person(const char*);
	Person(const Person&);
	virtual ~Person();
	Person getPerson();
	void setPerson(const char*);
	virtual void print();
};
#endif //PERSON_H