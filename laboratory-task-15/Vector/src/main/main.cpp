#include "../Vector/Vector.hpp"
#include "../Violation/Violation.hpp"


int main()
{
    try
    {
        std::string parking = "Неправильная парковка";
        std::string park = "Парковка в неположенном месте";
        Violation x(parking, park, 200);

        std::string parkovka = "Нарушение ПДД";
        std::string pdd = "Проезд на красный свет светофора";
        Violation y(parkovka, pdd, 150);
        Vector<Violation> violat;
        violat.pushBack(x);
        violat.pushBack(y);
        std::cout << violat[1];
        std::cout << std::endl;
        std::cout << violat[0];
    }

    catch(std::runtime_error r)
    {
        std::cerr << r.what();
    }

    catch(std::invalid_argument in)
    {
        std::cerr << in.what();
    }

    catch(std::logic_error l)
    {
        std::cerr << l.what();
    }

    return 0;
}