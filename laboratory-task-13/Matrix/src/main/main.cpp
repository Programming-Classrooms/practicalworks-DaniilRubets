#include "../Matrix/Matrix.hpp"


int main()
{
    try
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
    }

    catch(std::invalid_argument e)
    {
        std::cerr << e.what();
    }

    catch(std::runtime_error r)
    {
        std::cerr << r.what();
    }

    catch(std::logic_error l)
    {
        std::cerr << l.what();
    }
    
    return 0;
}