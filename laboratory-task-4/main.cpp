/*
    Заполнить квадратную матрицу последовательными натуральными числами,
    расположенными по спирали, начиная с левого верхнего угла и продвигаясь по часовой стрелке.
    Найти сумму элементов побочной диагонали.
*/


#include <iostream>
#include <iomanip>


void fillingWithZeroes(int32_t** matrix, int32_t& rows,int32_t &columns)
{
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			matrix[i][j] = 0;
		}
	}
}


void inputStartValueFromKeyboard(int32_t value)
{
    std::cout << "Input start natural number:";
    std::cin >> value;

    if (value <= 0) {
        std::cout << "Please, input natural number!";
        std::cin >> value;
    }
}


void inputBoadersForRandom(int32_t rightBoader, int32_t leftBoader)
{
    std::cout << "Input right boader:";
    std::cin >> rightBoader;

    if (rightBoader < 1) {
        std::cout << "Please, input natural number!";
        std::cin >> rightBoader;
    }
    std::cout << "Input left boader:";
    std::cin >> leftBoader;

    if (leftBoader < 1) {
        std::cout << "Please, input natural number!";
        std::cin >> leftBoader;
    }
}


void inputStartValueFromRandom(int32_t value, int32_t rightBoader, int32_t leftBoader)
{
    inputBoadersForRandom(rightBoader, leftBoader);
    value = rand() % (leftBoader - rightBoader) + rightBoader + 1;
}


void spiralFilling(int32_t** matrix, int32_t& rows, int32_t& columns, int32_t &value)
{
    int32_t columnPos = 0, rowPos = 0, direction = 0;

    while (1) {
        matrix[rowPos][columnPos] = value;
        ++value;

        if (rowPos == rows / 2 && columnPos == columns / 2) {
            matrix[rowPos][columnPos] = value;
            break;
        }

        if (direction == 0) {
            ++columnPos;

            if (columnPos == columns || matrix[rowPos][columnPos] != 0) {
                --columnPos;
                ++rowPos;
                direction = 1;
            }
        }

        else {
            if (direction == 1) {
                ++rowPos;

                if (rowPos == rows || matrix[rowPos][columnPos] != 0) {
                    --rowPos;
                    --columnPos;
                    direction = 2;
                }
            }

            else {
                if (direction == 2) {
                    --columnPos;

                    if (columnPos == -1 || matrix[rowPos][columnPos] != 0) {
                        ++columnPos;
                        --rowPos;
                        direction = 3;
                    }
                }

                else {
                    if (direction == 3) {
                        --rowPos;

                        if (rowPos == -1 || matrix[rowPos][columnPos] != 0) {
                            ++rowPos;
                            ++columnPos;
                            direction = 0;
                        }
                    }
                }
            }
        }
    }
}


int sumOfSecondaryDiagonal(int32_t** matrix, int32_t& value, int32_t& rows, int32_t& columns)
{
    int32_t sum = 0;
    for (size_t i = 0; i < rows; ++i) {

        for (size_t j = 0; j < columns; ++j) {

            if ((i + j) == (rows - 1)) {

                sum += matrix[i][j];
            }
        }
    }
    return sum;
}


void printingMatrix(int32_t** matrix, int32_t &rows, int32_t &columns)
{
	for (size_t i = 0; i < rows; ++i) {

		for (size_t j = 0; j < columns; ++j) {

            std::cout << std::setw(5) << matrix[i][j] << " ";
		}
		std::cout << '\n';
	}
}


void switchMode(int32_t& value, int32_t& mode, int32_t &rightBoader, int32_t &leftBoader)
{
    std::cout << "Chooze mode of input start value"<<'\n'<<"1.Input from keyboard"<<'\n'<<"2.Input from random"<<'\n';
    std::cin >> mode;

    switch (mode) {

    case 1:
        inputStartValueFromKeyboard(value);
        break;

    case 2:
        inputStartValueFromRandom(value, rightBoader, leftBoader);
        break;

    default:
        std::cout << "Please, input good number";
        std::cin >> mode;
    }
}


int main()
{
    try{
        srand(time(0));
        int32_t value = 1;
        int32_t rows = 0;
        int32_t mode = 0;
        int32_t rightBoader = 0;
        int32_t leftBoader = 0;
        std::cout << "Input size of your matrix:";
        std::cin >> rows;

        if (rows <= 0) {
            std::cout << "Please, input natural number!";
            std::cin >> rows;
        }
        int32_t columns = rows;
        int32_t** matrix = new int*[rows];

        for (size_t i = 0; i < rows; i++) {
            matrix[i] = new int[columns];
        }
        fillingWithZeroes(matrix, rows, columns);
        switchMode(value, mode, rightBoader, leftBoader);
        spiralFilling(matrix, rows, columns,value);
        printingMatrix(matrix ,rows,columns);
        std::cout << "It is sum of secondary diagonal:" << sumOfSecondaryDiagonal(matrix, value, rows, columns);
        for (size_t i = 0; i < rows; i++) {
		    delete[]matrix[i];
	    }
	        delete[]matrix;
    }

    catch(std::exception e) {
        std::cout << e.what();
    }
    return 0;
}

