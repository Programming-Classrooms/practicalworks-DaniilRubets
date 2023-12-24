/*
    Преобразовать массив таким образом, чтобы в первой его половине располагались элементы,
    стоявшие в четных позициях, а во второй половине — элементы, стоявшие в нечетных
    позициях с сохранением их взаимного порядка.
*/


#include <iostream>
#include <ctime>
#include <cstdlib>


void fillingWithZeros(int32_t& size, int* arr)
{
    for (size_t i = 0; i < size; i++) {
        arr[i] = 0;
    }
}


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


void sort(int32_t& n, int* arr, int32_t& size)
{
    int32_t counter = n;

    for (size_t i = 0; i < n; i += 2) {
        arr[counter] = arr[i];
        arr[i] = 0;
        counter++;
    }
}


void left_null(int* arr, int32_t& size)
{
    for (size_t i = 0; i < size; i++) {

        for (size_t j = 0; j < size - 1 - i; j++) {

            if (arr[j] == 0) {
                arr[j] = arr[j + 1];  
                arr[j + 1] = 0;
            }
        }
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
        int32_t size = 2 * n;
        int32_t mode = 0;
        int* arr = new int[size];
        fillingWithZeros(size, arr);
        switchFillingArray(n, arr, mode);
        printingArray(n, arr);
        sort(size, arr, n);
        left_null(arr, size);
        printingArray(size, arr);
        delete[]arr;
    }
    catch(std::exception e) {
        std::cout << e.what();
    }
}