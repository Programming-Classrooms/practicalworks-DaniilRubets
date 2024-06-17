#include "../Person/Person.hpp"
#include "../Student/Student.hpp"
#include "../Professor/Professor.hpp"


int main() 
{
	Student vit("Daniil", 4, 19);
	vit.print();

	std::cout << '\n';

	Professor get("Vitalya", "Math");
	get.print();

	return 0;
}