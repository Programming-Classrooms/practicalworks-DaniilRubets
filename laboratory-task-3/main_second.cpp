/*
    В массиве, состоящем из п целых элементов, вычислить:
    сумму модулей элементов массива, расположенных после первого элемента, равного
    нулю.
*/


#include <iostream>
#include <ctime>
#include <cstdlib>


void inputFromKeyboard(int32_t& n, int* arr) 
{
    std::cout << "Input elements of array: ";

    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
}


void fillingFromRandom(int32_t& n, int* arr) 
{
    int32_t leftBoader { 0 };
    int32_t rightBoader { 0 };

    while (leftBoader == rightBoader) {
        std::cout << "Input left boarder: ";
        std::cin >> leftBoader;
        std::cout << "Input right boader: ";
        std::cin >> rightBoader;
    }

    if (leftBoader > rightBoader) {
        std::swap(leftBoader, rightBoader);
    }

    for (size_t i = 0; i < n; ++i) {
        arr[i] = rand() % (rightBoader - leftBoader) + leftBoader + 1;
    }
}


void printingArray(int32_t& n, int* arr)
{
    std::cout << "It is your array: " << "[ ";

    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]";
}


void sumOfModules(int& n, int* arr)
{
    int sum = 0;
    size_t index = 0;
    bool isExistSum = false;

    for (size_t i = 0; i < n; ++i) {

        if (arr[i] == 0) {

            for (size_t j = i; j < n; ++j) {
                sum += abs(arr[j]);
                isExistSum = true;
                index = i;
            }
        }
    }

    if (index == n - 1) {
        std::cout << "It is impossible to calculate the sum because '0' is in the last position";
    }

    if (isExistSum == false) {
        std::cout << "Sum doesn`t exsist!" << '\n';
    }

    else {
        std::cout << "Sum of secon null elements = " << sum << '\n';
    }
}


void switchFillingArray(int32_t& n, int* arr, int32_t& mode)
{
    std::cout << "Input size of your array: ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "The number must be natural, go redo it!!!" << '\n';
        std::cin >> n;
    }

    else {
        std::cout << "Enter 1(keyboard) or 2(random) ";
    }
    std::cin >> mode;

    switch (mode) {
    case 1:
        inputFromKeyboard(n, arr);
        break;

    case 2:
        fillingFromRandom(n, arr);
        break;

    default:
        std::cout << "Incorrect input!";
        std::cin >> mode;
    }
}


int main()
{
    try {
        srand(time(0));
        int32_t n = 1;
        int32_t mode = 0;
        int* arr = new int[n];
        switchFillingArray(n, arr, mode);
        printingArray(n, arr);
        sumOfModules(n, arr);
        delete[]arr;
    }
    catch (std::exception e) {
        std::cout << e.what();
    }
}

