#include <iostream>
#include <cmath>


double sum(double x, double eps) 
{
    double result = 1.0;
    double term = -x*x/2;
    int32_t n = 2;

    while (fabs(term) >= eps)
    {
        result += term;
        term *= -x * x / ((2 * n - 1) * (2 * n));
        n++;
    }

    return result;
}


int main() 
{
    double x;
    int32_t k;
    setlocale(LC_ALL, "Rus");
    std::cout << "Введите значение x и k: ";
    std::cin >> x >> k;

    if (x > 1 && x < -1)
    {
        std::cout << "Введите, пожалуйста, значение из промежутка [-1;1]";
        std::cin >> x >> k;
    }

    if (k <= 1)
    {
        std::cout << "Значение k должно быть больше 1." << std::endl;
        return 1;
    }
    double eps = std::pow(10, -k);
    double result = sum(x, eps);
    double mathResult = std::cos(x);

    std::cout << "Сумма ряда: " << result << std::endl;
    std::cout << "cos(x) = " << mathResult << std::endl;

    return 0;
}