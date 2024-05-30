#ifndef STUDENT_H
#define STUDENT_H
#include "../Person/Person.hpp"
#include <iostream>
class Student : Person
{
private:
	int32_t course;
	int32_t group;
public:

	Student();
	Student(const char*, int32_t, int32_t);
	Student(const char* name, const Student&);

	~Student() override;

	int32_t getCourse();
	int32_t getGroup();
	int32_t setCourse(int32_t);
	int32_t setGroup(int32_t);
	
	void print() override;
};
#endif //STUDENT_H