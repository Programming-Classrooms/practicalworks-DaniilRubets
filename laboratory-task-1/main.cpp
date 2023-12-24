/*
    Разработать консольное приложение для вычисления приближённого значения функции, используя представление ее в виде ряда Тейлора.
    Вычисления заканчивать, когда очередное слагаемое окажется по модулю меньше заданного числа , где n – натуральное число. 
    Сравнить полученный результат со значением, вычисленным с помощью стандартных функций. Значение ввести по запросу.
    Функция №3.
*/


#include <iostream>
#include <cmath>


double sumOfTaylorSeries(double &x, double &eps) 
{
    double result = 1.0;
    double term = -x*x/2;
    int32_t n = 2;

    while (fabs(term) >= eps) {
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
    std::cout << "Input 'x' and 'k': ";
    std::cin >> x >> k;

    if (x > 1 && x < -1) {
        std::cout << "Please, input value from {-1} to {1}";
        std::cin >> x >> k;
    }

    if (k <= 1) {
        std::cout << "Value 'k' must be > 1!" << std::endl;
        return 1;
    }
    double eps = std::pow(10, -k);
    double result = sumOfTaylorSeries(x, eps);
    double mathResult = std::cos(x);

    std::cout << "Taylor series sum: " << result << std::endl;
    std::cout << "cos(x) = " << mathResult << std::endl;
    return 0;
}

