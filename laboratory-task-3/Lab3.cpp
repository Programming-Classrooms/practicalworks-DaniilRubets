/*Вариант 34:
В массиве, состоящем из п целых элементов, вычислить:
1.длину самой длинной цепочки подряд стоящих различных элементов;
2.сумму модулей элементов массива, расположенных после первого элемента, равного нулю.
3.Преобразовать массив таким образом, чтобы в первой его половине располагались элементы,
стоявшие в четных позициях, а во второй половине — элементы, стоявшие в нечетных позициях с сохранением их взаимного порядка.
*/
#include <iostream>
#include <cstdlib>
#include<ctime>


void fillingWithZeros(int& size, int* arr)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}


void inputFromKeyboard(int &n, int *arr) {
    std::cout << "Input elements of array: ";

    for (int i = 0; i < n; ++i)
    {
        
        std::cin >> arr[i];
    }
}


void fillingFromRandom(int &n, int *arr) {
    
    int left_boarder{ 0 }, right_boader { 0 };

    while (left_boarder == right_boader) {
        std::cout << "Input left boarder: ";
        std::cin >> left_boarder;
        std::cout << "Input right boader: ";
        std::cin >> right_boader;
    }

    if(left_boarder>right_boader)
    {
        std::swap(left_boarder, right_boader);
    }

    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % (right_boader - left_boarder) + left_boarder + 1;
    }
}


void printingArray(int &n, int *arr)
{
    std::cout << "It is your array: " << "[ ";

    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "]";
}


void firstExersise(int &n, int *arr) {
    int max_length = 1;
    int current_length = 1;

    for (int i = 1; i < n+1; ++i)
    {
        if (i == n)
        {
            if (current_length > max_length) 
            {
                max_length = current_length;
                break;
            }

            else 
            {
                max_length = max_length;
                break;
            }
        }

        if (arr[i] != arr[i - 1])
        {
            current_length++;
            continue;
        }

        if (arr[i] == arr[i - 1])
        {
            if (current_length > max_length)
            {
                max_length = current_length;
            }

            else 
            {
                max_length = max_length;
            }
            current_length = 1;
        }
    }
    std::cout<<'\n' << "The Biggest length = " << max_length << '\n';
}


void secondExersise(int &n, int *arr)
{
    int sum = 0;
    size_t index = 0;
    bool is_exist_sum = false;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == 0)
        {
            for (int j = i; j < n; ++j) 
            {
                sum += abs(arr[j]);
                is_exist_sum = true;
                index = i;
            }        
        }      
    }

    if (index == n - 1)
    {
        std::cout << "It is impossible to calculate the sum because '0' is in the last position";
    }

    if (is_exist_sum == false)
    {
        std::cout << "Sum doesn`t exsist!"<<'\n';
    }

    else
    {
        std::cout << "Sum of secon null elements = " << sum << '\n';
    }
}


void sort(int &n, int *arr, int &size)
{
    int counter = n;

    for (size_t i = 0; i < n; i+=2)
    {
        arr[counter] = arr[i];
        arr[i] = 0;
        counter++;
    }
}


void left_null(int* arr, int& size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++) 
        {
            if (arr[j] == 0)
            {
                arr[j] = arr[j + 1];   arr[j + 1] = 0;
            }
        }
    }
}


void printingSortArray(int& size, int* arr)
{
    std::cout << "It is your sort array: " << "[ ";

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "]";
}


void switchFillingArray(int& n, int& size, int* arr, int &mode)
{
    std::cout << "Input size of your array: ";
    std::cin >> n;

    if (size < 1)
    {
        std::cout << "The number must be natural, go redo it!!!" << '\n';
        std::cin >> size;
    }

    else
    {
        std::cout << "Enter 1(keyboard) or 2(random) ";
    }
    std::cin >> mode;

    switch (mode)
    {
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
    srand(time(0));
    int n = 1,size = 2 * n, mode; 
    int* arr = new int[size];
    fillingWithZeros(size, arr);
    switchFillingArray(n, size, arr, mode);
    printingArray(n, arr);
    firstExersise(n, arr);
    secondExersise(n, arr);
    sort(size, arr,n);
    left_null(arr, size);
    printingSortArray(size, arr);
    delete[]arr;
    }
