/*
Разработать пользовательский тип (класс) "Матрица". Исходный код
класса оформить в виде двух файлов:
o заголовочный файл с объявлением класса
o файл реализации методов.
Перегрузить:
o все возможные конструкторы, деструктор
o оператор присваивания;
o составные операторы присваивания;
o умножение на константу слева;
o умножение на константу справа;
o деление на константу;
o сложение матриц;
o вычитание матриц;
o умножение матриц;
o сравнение матриц на равенство и неравенство;
o ввод и вывод матрицы в удобном для пользователя виде.
При обработке исключительных ситуаций идентифицировать каждый вид
ошибок. Для демонстрации возможностей класса написать головную
программу, в которой продемонстрировать работу с этим классом. Меню
делать не надо. В комментариях указать, что тестируете
*/

#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <cmath>
#include <cstdlib>

class Matrix {
    
private:
    int32_t rows, cols;
    double** data;

public:
    Matrix(); 
    Matrix(int32_t, int32_t);
    Matrix(const Matrix&); 

    ~Matrix();

    double getValue(int32_t, int32_t) const;
    
    void setValue(int32_t, int32_t, double);

    void fillMatrix(const Matrix&);

    Matrix& operator=(const Matrix&); 
    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const double&);
    Matrix& operator/=(const double&);

    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix operator*(const double&); 
    //Matrix operator*(const double&);
    Matrix operator/(const double&);
    bool operator==(const Matrix&);
    bool operator!=(const Matrix&);


   
    friend std::istream& operator>>(std::istream&, Matrix&);
    friend std::ostream& operator<<(std::ostream&, const Matrix&);
};

#endif //MATRIX_HPP
