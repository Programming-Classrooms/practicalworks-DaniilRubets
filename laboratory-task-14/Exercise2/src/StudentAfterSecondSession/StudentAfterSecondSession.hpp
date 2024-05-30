#ifndef STUDENTAFTERSECONDSESSION_HPP
#define STUDENTAFTERSECONDSESSION_HPP
#include "../StudentAfterFirstSession/StudentAfterFirstSession.hpp"
class StudentAfterSecondSession : StudentAfterFirstSession
{
private:
	int32_t marksSecond[5];
public:
	/*##### ������������ #####*/
	StudentAfterSecondSession() = delete;
	StudentAfterSecondSession(std::string&, int16_t, int16_t, int16_t, int32_t*, int32_t*);
	StudentAfterSecondSession(const StudentAfterSecondSession&);

	/*##### ���������� #####*/
	~StudentAfterSecondSession() {};

	/*##### ������ #####*/
	int32_t* getMarks();

	/*##### ������� #####*/
	void setMarks(int32_t*);

	/*##### �������� ������ #####*/
	friend std::ostream& operator << (std::ostream&, const StudentAfterSecondSession&);
};
#endif //STUDENTAFTERSECONDSESSION_HPP
