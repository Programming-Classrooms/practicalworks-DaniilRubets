#include "../StudentAfterSecondSession/StudentAfterSecondSession.hpp"

StudentAfterSecondSession::StudentAfterSecondSession(std::string& name, int16_t cou,
	int16_t gr, int16_t rec, int32_t* arr, int32_t* mark) :StudentAfterFirstSession(name, cou, gr, rec, arr)
{
	for (size_t i = 0; i < 5; ++i)
	{
		this->marksSecond[i] = arr[i];
	}
}


StudentAfterSecondSession::StudentAfterSecondSession(const StudentAfterSecondSession& rhs) :
	StudentAfterFirstSession(rhs)
{
	for (size_t i = 0; i < 5; ++i)
	{
		this->marksSecond[i] = rhs.marksSecond[i];
	}
}


int32_t* StudentAfterSecondSession::getMarks()
{
	return this->marksSecond;
}


void StudentAfterSecondSession::setMarks(int32_t* arr)
{
	for (size_t i = 0; i < 5; ++i)
	{
		this->marksSecond[i] = arr[i];
	}
}


std::ostream& operator << (std::ostream& os, const StudentAfterSecondSession& rhs)
{
	os << StudentAfterFirstSession(rhs);
	os << "Marks from second session: ";
	for (size_t i = 0; i < 5; ++i)
	{
		os << rhs.marksSecond[i] << " ";
	}
	return os;
}