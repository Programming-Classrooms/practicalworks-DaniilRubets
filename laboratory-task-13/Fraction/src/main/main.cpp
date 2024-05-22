#include "../Fraction/Fraction.hpp"
int main() 
{
	try
	{
		Fraction x(5, 10);
		Fraction y(2, 7);

		std::cout << "Fraction x: " << x;
		std::cout << "Fraction y: " << y;
		std::cout << "Sum of fractions: " << x + y;
		std::cout << "Difference of fractions: " << x - y;
		std::cout << "Product of fractions: " << x * y;
		std::cout << "Quotient of fractions: " << x / y;

		Fraction z(1,2);
		std::cin >> z;
		std::cout <<"Your Fraction: " << z;

		if (x == y) {
			std::cout << "True" << '\n';
		}
		else {
			std::cout << "False" << '\n';
		}

		if(x < y) {
			std::cout << "True" << '\n';
		}
		else {
			std::cout << "False" << '\n';
		}

		if (x > y) {
			std::cout << "True" << '\n';
		}
		else {
			std::cout << "False" << '\n';
		}

		x += y;
		std::cout << "+=: " << x;
		y -= z;
		std::cout << "-=: " << y;

		std::cout<<'\n';
	}

	catch(std::logic_error e)
	{
		std::cerr << e.what();
	}
	catch(std::invalid_argument in)
	{
		std::cerr << in.what();
	}
	catch(std::runtime_error r)
	{
		std::cerr << r.what();
	}
	
	return 0;
}