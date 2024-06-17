/*Создать контейнер vector <int>, ввести с клавиатуры и записать в него
числа, не задавая количество элементов при вводе. Используя
соответствующие алгоритмы и методы, подсчитать:
o сумму чисел;
o общее количество чисел;
o количество чисел, равных заданному;
o количество чисел, удовлетворяющих условию, например,
«больше, чем n»;
o заменить все нули средним арифметическим (взять целую
часть);
o добавить к каждому элементу вектора сумму всех чисел из
заданного интервала этого же вектора (не числовой оси, а
вектора);
o заменить все числа, модуль которых есть четное число, на
разность максимального и минимального элемента этого
вектора;
o удалить из последовательности все равные по модулю числа,
кроме первого из них.
Меню делать не нужно. Выдать на экран все результаты с пояснениями
на русском языке.*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>


void enterNumbersFromKeyboard(std::vector<int>& vec, int element)
{
    std::cout << "Введите элементы массива(чтобы закончить ввод нажмите любой другой символ, кроме цифр): ";
    while (std::cin >> element)
    {
        vec.push_back(element);
    }
}


int sum(std::vector<int>& vec)
{
    int sum;
    sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "\nСумма чисел: " << sum << '\n';
    return sum;
}


void counterNumbers(std::vector<int>& vec)
{
    size_t count;
    count = vec.size();
    std::cout << "\nКоличество чисел: " << count << '\n';
}


void equalNumbers(std::vector<int>& vec)
{
    int number;
    int counter = 0;
    std::cout << "\nВведите число для поиска: ";
    std::cin.clear();
    std::cin.ignore();
    std::cin >> number;
    for (auto& num : vec)
    {
    if (num == number)
    {
        ++counter;
    }
    }
    std::cout << "Количество чисел равных заданному: " << counter << '\n';
}


void sutisfyNumbers(std::vector<int> & vec)
{
        int num;
        int counter = 0;
        std::cout << "\nВведите число для поиска: ";
        std::cin.clear();
        std::cin.ignore();
        std::cin >> num;
        for (auto& numZ : vec)
        {
            if (numZ > num)
            {
                ++counter;
            }
        }
        std::cout << "Количество чисел, удовлетворяющих условию: " << counter << '\n';
}


void replaceZeroes(std::vector<int>& vec)
{
        double mean = sum(vec) / vec.size();
        int integerPart = std::floor(mean);
        std::cout << "\nЗаменить все нули средним арифметическим: ";


        for (auto& c : vec)
        {
        if (c == 0)
        {
        c = mean;
        }
        }

        for (auto& c: vec)
        {
        std::cout << c << " ";
        }
}


void addSumFromInterval(std::vector<int>& vec)
{
        int first;
        int last;

        std::cout << "\nВведите нижнюю границу интервала: ";
        std::cin.clear();
        std::cin.ignore();
        std::cin >> first;
        if (first < 0)
        {
        std::invalid_argument err("Ошибка! Граница интервала не может быть меньше 0!");
        }
        
        std::cout << "Введите верхнюю границу интервала: ";
        std::cin.clear();
        std::cin.ignore();
        std::cin >> last;
        if (last < 0)
        {
        std::invalid_argument err("Ошибка! Граница интервала не может быть меньше 0!");
        }

        int intervalSum = std::accumulate(vec.begin() + first, vec.begin() + last, 0);

        for (size_t i = 0; i < vec.size(); ++i)
        {
        vec[i] += intervalSum;
        }

        std::cout << "Новый вектор: ";
        for (auto& c : vec)
        {
        std::cout << c << " ";
        }
}


void replaceOnDifference(std::vector<int>& vec)
{
    int minElement = *std::min_element(vec.begin(), vec.end());
        std::cout << "\nМинимальный элемент вектора: " << minElement;
        int maxElement = *std::max_element(vec.begin(), vec.end());
        std::cout << "\nМаксимальный элемент вектора: " << maxElement;
        int diff = maxElement - minElement;
        std::cout << "\nРазность максимального и минимального элементов: " << diff;
        for (auto& c : vec)
        {
        if (std::abs(c) % 2 == 0)
        {
        c = diff;
        }
        }
        std::cout << "\nНовый вектор: ";
        for (auto& c : vec)
        {
        std::cout << c << " ";
        }

}

bool isInVec(const std::vector<int>&conteiner, const int c)
{
    for (auto x : conteiner)
    {
        if (x == c)
        {
            return true;
        }
    }
    
    return false;
}

void deleteOther(std::vector<int>& vec)
{
        std::vector <int> conteiner;
        for (auto& c : vec)
        {
        if (!isInVec(conteiner, c))
        {
        conteiner.push_back(c);
        }
        }
        std::cout << "\nНовый вектор: ";
        for (auto& x : conteiner)
        {
        std::cout << x << " ";
        }
}




int main()
{
    try
    {
        std::vector<int> vec;
        int element;
        /*======= Ввод числа с клавиатуры =======*/
        enterNumbersFromKeyboard(vec,element);
        std::cout << "\n\n=================================";
        /*======= Сумма чисел =======*/
        sum(vec);
        std::cout << "\n\n=================================";
        /*======= Общее количество чисел =======*/
        counterNumbers(vec);
        std::cout << "\n\n=================================";
        /*======= Количество чисел равных заданному =======*/
        equalNumbers(vec);
        std::cout << "\n\n=================================";
        /*======= Количество чисел, удовлетворяющих условию =======*/
        sutisfyNumbers(vec);
        std::cout << "\n\n=================================";
        /*======= Заменить все нули средним арифметическим =======*/
        replaceZeroes(vec);
        std::cout << "\n\n=================================";
        /*======= Добавить к каждому элементу вектора сумму всех чисел из заданного интервала этого же вектора =======*/
        addSumFromInterval(vec);
        std::cout << "\n\n=================================";
        /*Заменить все числа, модуль которых есть четное число, на
        разность максимального и минимального элемента этого вектора;*/
        replaceOnDifference(vec);
        std::cout << "\n\n=================================";
        /*Удалить из последовательности все равные по модулю числа, кроме первого из них*/
        deleteOther(vec);
    }


    catch(std::invalid_argument e)
    {
        std::cerr << e.what();
    }


    return 0;
}
