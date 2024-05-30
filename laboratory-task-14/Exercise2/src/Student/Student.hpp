#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <iostream>
#include <string>
class Student
{
protected:
	size_t id;
	static size_t nextId;
	std::string fullName;
	int16_t course;
	int16_t group;
	const int16_t recordNumber;
public:
	/*##### ������������ #####*/
	Student() = delete;
	Student(std::string&, int16_t, int16_t, int16_t);
	Student(const Student&);

	/*##### ���������� #####*/
	~Student() {}

	/*##### ������� #####*/
	std::string getName();
	int16_t getCourse();
	int16_t getGroup();
	int16_t getRecordNumber();

	/*##### ������� #####*/
	void setName(std::string&);
	void setCourse(int16_t);
	void setGroup(int16_t);

	/*##### �������� ������ #####*/
	friend std::ostream& operator<< (std::ostream&, const Student&);
};

#endif //STUDENT_HPP
