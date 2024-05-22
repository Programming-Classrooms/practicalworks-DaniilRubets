#include "../Matrix/Matrix.hpp"


int main()
{
    Matrix a(3,3);
    std::cout << "Input elements of your Matrix: ";
    std::cin >> a;
    Matrix b(3,3);
    std::cout << "Input elements of your Matrix: ";
    std::cin >> b;

    std::cout << "Sum of Matrixs: " << '\n' << a + b;

    double integer = 2.0;
    std::cout << "Matrix product: " << '\n' << a*integer;
    return 0;
}