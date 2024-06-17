#include "../StudentAfterFirstSession/StudentAfterFirstSession.hpp"

StudentAfterFirstSession::StudentAfterFirstSession(std::string& name, int16_t cou, int16_t gr,
	int16_t rec, int32_t* arr): Student(name,cou,gr,rec)
{
	for (size_t i = 0; i < 4; ++i)
	{
		this->marksFirst[i] = arr[i];
	}
}


StudentAfterFirstSession::StudentAfterFirstSession(const StudentAfterFirstSession& rhs) :
	Student(rhs)
{
	for (size_t i = 0; i < 4; ++i)
	{
		this->marksFirst[i] = rhs.marksFirst[i];
	}
}


int32_t* StudentAfterFirstSession::getMarks()
{
	return marksFirst;
}


void StudentAfterFirstSession::setMarks(int32_t* arr)
{
	for (size_t i = 0; i < 4; ++i)
	{
		this->marksFirst[i] = arr[i];
	}
}


std::ostream& operator <<(std::ostream& os, const StudentAfterFirstSession& rhs)
{
	os << Student(rhs);
	os << "Marks from first session: ";
	for (size_t i = 0; i < 4; ++i)
	{
		os << rhs.marksFirst[i] << " ";
	}
	os << '\n';
	return os;
}