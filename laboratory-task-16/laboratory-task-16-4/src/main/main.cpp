/*Объявить целочисленную матрицу типа vector<vector<int>>, размер
матрицы и границы интервалов для элементов, содержащихся в матрице,
ввести с клавиатуры. Выполнить следующие действия с матрицей:
- заполнить случайными значениями;
- удалить строку и столбец, на пересечении которых стоит максимальный
элемент матрицы (первый из найденных);
- упорядочить строки матрицы по возрастанию сумм элементов строк (без
использования алгоритма sort).
Написать все необходимые тесты и выполнить обработку исключений.*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <numeric>


void fillMatrix(std::vector<std::vector<int>>& mtrx, int min, int max)
{
	for (auto& row : mtrx)
	{
		for (auto& element : row)
		{
			element = rand() % (max - min + 1) + min;
		}
	}
}


void eraseMax(std::vector<std::vector<int>>& mtrx)
{
	int maxVal = mtrx[0][0];
	int maxI = 0, maxJ = 0;
	for (size_t i = 0; i < mtrx.size(); ++i) 
	{
		for (int j = 0; j < mtrx[i].size(); ++j) 
		{
			if (mtrx[i][j] > maxVal) {
				maxVal = mtrx[i][j];
				maxI = i;
				maxJ = j;
			}
		}
	}
	mtrx.erase(mtrx.begin() + maxI);
	for (auto& row : mtrx) 
	{
		row.erase(row.begin() + maxJ);
	}
}


void sortRows(std::vector<std::vector<int>>& mtrx) 
{
	for (size_t i = 0; i < mtrx.size() - 1; ++i) 
	{
		for (size_t j = 0; j < mtrx.size() - i - 1; ++j) 
		{
			if (std::accumulate(mtrx[j].begin(), mtrx[j].end(), 0) > std::accumulate(mtrx[j + 1].begin(), mtrx[j + 1].end(), 0)) 
			{
				std::swap(mtrx[j], mtrx[j + 1]);
			}
		}
	}
}


void printMatrix(std::vector<std::vector<int>>& mtrx) 
{
	for (const auto& row : mtrx) 
	{
		for (const auto& elem : row) 
		{
			std::cout << elem << " ";
		}
		std::cout << '\n';
	}
}


int main()
{
	try 
	{
		srand(time(0));
		int rows(0), columns(0), min(0), max(0);

		std::cout << "Input number of rows: ";
		std::cin >> rows;
		std::cout << "Input number of columns: ";
		std::cin >> columns;
		std::cout << "Input the lower limit of the interval: ";
		std::cin >> min;
		std::cout << "Input the upper limit of the interval: ";
		std::cin >> max;

		if (max < min)
		{
			std::swap(max, min);
		}

		std::vector<std::vector<int>> mtrx(rows, std::vector<int>(columns));
		fillMatrix(mtrx, min, max);
		printMatrix(mtrx);
		std::cout << "=====================================================================" << '\n';
		eraseMax(mtrx);
		printMatrix(mtrx);
		std::cout << "=====================================================================" << '\n';
		sortRows(mtrx);
		printMatrix(mtrx);
	}


	catch(std::invalid_argument e)
	{
		std::cerr << e.what();
	}

	catch(std::logic_error l)
	{
		std::cerr << l.what();
	}

	catch(std::runtime_error r)
	{
		std::cerr << r.what();
	}

	return 0;
}
