#include <iostream>
/*
2.Написать программу, которая для заданного натурального числа удаляет из записи числа все цифры, кратные минимальной цифре.
5.Написать программу, которая для заданного натурального числа вычисляет сумму первых чисел Фибоначчи, не превосходящую заданного числа N.
8.Написать программу, которая для заданного натурального числа N находит, не превышающие это число простые числа. 
*/
using std::cout;
using std::cin;
void secondExersise(int32_t &number, int32_t &minimumNumber, int32_t &newNumber)
{
    std::cout << "Enter natural number: " << '\n';
    std::cin >> number;
    while (number <= 0)
    {
        std::cout << "Invalid number! Enter right: ";
        std::cin >> number;
    }
    int32_t a = number;
    while (a != 0)
    {
        int lastDigit = 0;
        lastDigit = a % 10;
        a /= 10;
        if (lastDigit < minimumNumber)
        {
            minimumNumber = lastDigit;
        }
    }
    while (number != 0)
    {
        int last_digit = 0;
        last_digit = number % 10;
        number /= 10;
        if (last_digit % minimumNumber != 0)
        {
            newNumber = newNumber * 10 + last_digit;
        }
    }
    std::cout << "It is your number: " << newNumber;
}
void fifthExersise(int32_t &sum, int32_t &fib1, int32_t &fib2, int32_t &number)
{
    cout << "Please, enter natural number.\n";
    cin >> number;
    while (number <= 0)
    {
        cout << "ERROR! Please, enter natural number!!! \n ";
        cin >> number;
    }
    cout << fib1 << '\t' << fib2 << '\t';
    while (fib1 <= number) {
        sum += fib2;
        int32_t temp = fib2;
        fib2 += fib1;
        fib1 = temp;
        cout << fib2 << '\t';
    }
    cout << '\n' << "Sum = " << sum << std::endl;
}
void eightsExersise(int32_t &number)
{
    std::cout << "Input natural number: " << " ";
    std::cin >> number;
    if (number < 0)
    {
        std::cout << "Incorrect input: " << '\n';
        std::cin >> number;
    }
    if (number == 1)
    {
        std::cout << "There are no simple numbers in this range: " << '\n';
        std::cin >> number;
    }
    std::cout << 2 << '\n';
    for (int j = 3; j < number; j += 2)
    {
        bool is_simple = true;
        for (int a = 3; a * a <= j; a += 2)
        {
            if (j % a == 0)
            {
                is_simple = false;
                break;
            }
        }
        if (is_simple)
        {
            std::cout << j << '\n';
        }
    }
}
void chooseExersise(int32_t& mode, int32_t& number, int32_t& minimumNumber, int32_t& newNumber, int32_t& sum, int32_t& fib1, int32_t& fib2)
{
    cout << "Choose the exersise:" << '\n' << "1.Second exersie" << '\n' << "2.Fifth exersise" << '\n' << "3.Eights exersise";
    cout << '\n';
    cin >> mode;
    switch (mode)
    {
    case 1:
        secondExersise(number, minimumNumber, newNumber);
        break;
    case 2:
        fifthExersise(sum, fib1, fib2, number);
        break;
    case 3:
        eightsExersise(number);
        break;
    }
}
int main()
{
    int32_t sum = 0, fib1 = 0, fib2 = 1, number;
    int32_t minimumNumber = 10, newNumber = 0;
    int32_t mode;
    chooseExersise(mode, number, minimumNumber, newNumber, sum, fib1, fib2);
    return 0;
}
