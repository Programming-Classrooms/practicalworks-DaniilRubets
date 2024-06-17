#include "../Student/Student.hpp"
#include "../StudentAfterFirstSession/StudentAfterFirstSession.hpp"
#include "../StudentAfterSecondSession/StudentAfterSecondSession.hpp"
int main() 
{
	try
	{
		std::string name = "Vitalya";
	std::string im = "Vasya";
	int16_t c = 3, g = 19, f = 2, qwerty = 231;
	int16_t rec = 4251, recition = 3434;
	int16_t o = 1, p = 7121, rac = 5431;
	Student x(name, c, g, rec);
	std::cout << x << '\n';
	Student y(im, o, p, rac);
	std::cout << y;
	int32_t A[4]{ 5,6,5,8 };
	int32_t B[5]{ 3,8,9,7,8 };
	StudentAfterFirstSession q(im, o, p, rac, A);
	std::cout << q;
	StudentAfterSecondSession w(im, f, qwerty, recition, A, B);
	std::cout << w;
	}
	
	catch(std::runtime_error r)
	{
		std::cerr << r.what();
	}

	catch(std::logic_error l)
	{
		std::cerr << l.what();
	}

	catch(std::invalid_argument in)
	{
		std::cerr << in.what();
	}

	return 0;
}
