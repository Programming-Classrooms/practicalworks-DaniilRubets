/*
    Заполнить квадратную матрицу последовательными натуральными числами,
    расположенными по спирали, начиная с левого верхнего угла и продвигаясь по часовой стрелке.
    Найти сумму элементов побочной диагонали.
*/


#include <iostream>
#include <iomanip>


using std::cin;
using std::cout;


void fillingWithZeroes(int32_t** matrix, int32_t& rows,int32_t &columns)
{
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < columns; j++) {
			matrix[i][j] = 0;
		}
	}
}


void inputStartValueFromKeyboard(int32_t& value)
{
    cout << "Input start value:";
    cin >> value;

    if (value <= 0) {
        cout << "Please, input natural number!";
        cin >> value;
    }
}


void inputStartValueFromRandom(int32_t &value)
{
    int32_t rightBoader;
    int32_t leftBoader;
    cout << "Input right boader:";
    cin >> rightBoader;

    if (rightBoader < 1) {
        cout << "Please, input natural number!";
        cin >> rightBoader;
    }
    cout << "Input left boader:";
    cin >> leftBoader;

    if (leftBoader < 1) {
        cout << "Please, input natural number!";
        cin >> leftBoader;
    }
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


void sumOfSecondaryDiagonal(int32_t** matrix, int32_t& value, int32_t& rows, int32_t& columns)
{
    int32_t sum = 0;
    for (size_t i = 0; i < rows; i++) {

        for (size_t j = 0; j < columns; j++) {

            if ((i + j) == (rows - 1)) {

                sum += matrix[i][j];
            }
        }
    }
    cout << "It is sum of secondary diagonal:" << sum;
}


void printingMatrix(int32_t** matrix, int32_t &rows, int32_t &columns)
{
	for (size_t i = 0; i < rows; i++) {

		for (size_t j = 0; j < columns; j++) {

            cout << std::setw(5) << matrix[i][j] << " ";
		}
		cout << '\n';
	}
}


void switchMode(int32_t& value, int32_t& mode)
{
    cout << "Chooze mode of input start value"<<'\n'<<"1.Input from keyboard"<<'\n'<<"2.Input from random"<<'\n';
    cin >> mode;

    switch (mode) {

    case 1:
        inputStartValueFromKeyboard(value);
        break;

    case 2:
        inputStartValueFromRandom(value);
        break;

    default:
        cout << "Please, input good number";
        cin >> mode;
    }
}



int main()
{
    try{
        srand(time(0));
        int32_t value = 1;
        int32_t rows = 0;
        int32_t mode = 0;
        cout << "Input size of your matrix:";
        cin >> rows;

        if (rows <= 0) {
            cout << "Please, input natural number!";
            cin >> rows;
        }
        int32_t columns = rows;
        int32_t** matrix = new int*[rows];

        for (size_t i = 0; i < rows; i++) {
            matrix[i] = new int[columns];
        }
        fillingWithZeroes(matrix, rows, columns);
        switchMode(value, mode);
        spiralFilling(matrix, rows, columns,value);
        printingMatrix(matrix ,rows,columns);
        sumOfSecondaryDiagonal(matrix, value, rows, columns);
        for (size_t i = 0; i < rows; i++) {
		    delete[]matrix[i];
	    }
	        delete[]matrix;
    }

    catch(std::exception e) {
        cout << e.what();
    }
}

