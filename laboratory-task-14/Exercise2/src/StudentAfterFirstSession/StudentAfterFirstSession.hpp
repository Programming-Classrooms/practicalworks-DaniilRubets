#ifndef STUDENTAFTERFIRSTSESSION_HPP
#define STUDENTAFTERFIRSTSESSION_HPP
#include "../Student/Student.hpp"
#include <iostream>
class StudentAfterFirstSession : Student
{
protected:
	int32_t marksFirst[4];
public:
	/*##### ������������ #####*/
	StudentAfterFirstSession() = delete;
	StudentAfterFirstSession(std::string&, int16_t, int16_t, int16_t, int32_t*);
	StudentAfterFirstSession(const StudentAfterFirstSession&);

	/*##### ���������� #####*/
	~StudentAfterFirstSession() {};

	/*##### ������ #####*/
	int32_t* getMarks();

	/*##### ������� #####*/
	void setMarks(int32_t*);

	/*##### �������� ������ #####*/
	friend std::ostream& operator << (std::ostream&, const StudentAfterFirstSession&);
};
#endif //STUDENTAFTERFIRSTSESSION_HPP
