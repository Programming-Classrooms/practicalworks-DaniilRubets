/*
Разработать пользовательский тип (класс) "обыкновенная дробь".
Исходный код класса оформить в виде двух файлов:
o заголовочный файл с объявлением класса
o файл реализации методов.
Дробь хранить в "канонической форме": если n – числитель, а d – знаменатель,
то знак хранится в числителе (знаменатель всегда больше 0), а n и d – взаимно
простые. Реализовать:
o все возможные конструкторы, деструктор,
o все возможные арифметические операторы над дробями,
o операторы сравнения,
o инкремент и декремент,
o унарный минус,
o оператор отрицания перегрузить, как оператор получения
обратной дроби,
o ввод из потока,
o вывод в поток,
o приведение к вещественному типу,
o оператор присваивания,
o составные операторы присваивания.
Для обработки исключительных ситуаций использовать собственный класс
(можно простейший вариант). Для демонстрации возможностей класса
написать головную программу, в которой продемонстрировать работу с этим
классом. Меню делать не надо.
*/


#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>


class Fraction 
{
private:
  int32_t numerator;
  int32_t denominator;
public:
  /*======== Конструкторы ========*/
  Fraction();
  Fraction(int32_t);
  Fraction(int32_t, int32_t);
  Fraction(const Fraction&);
  ~Fraction();

  /*======== Геттеры ========*/
  int32_t getN();
  int32_t getD();

  /*======== Сеттеры ========*/
  int32_t setN(int32_t);
  int32_t setD(int32_t);


  /*======== Операторы присваивания ========*/
  Fraction operator=(const Fraction&);
  Fraction& operator+=(const Fraction&);
  Fraction& operator+=(int32_t);
  Fraction& operator-=(const Fraction&);
  Fraction& operator*=(const Fraction&);
  Fraction& operator*=(int32_t);
  Fraction& operator/=(const Fraction&);
  Fraction& operator/=(int32_t);

  /*======== Функция сокращения дроби ========*/
  void reduce();

  /*======== Бинарные операторы ========*/
  Fraction operator+(const Fraction&);
  Fraction operator+(int32_t);
  friend Fraction operator+(int32_t, const Fraction&);

  Fraction operator-(const Fraction&);
  Fraction operator-(int32_t);
  friend Fraction operator-(int32_t, Fraction&);

  Fraction operator*(const Fraction&);
  Fraction operator*(int32_t);

  Fraction operator/(const Fraction&);
  Fraction operator/(int32_t);

  /*======== Операторы сравнения ========*/
  bool operator==(const Fraction&);
  bool operator<(const Fraction&);
  //bool operator>(const Fraction&);
  bool operator>(Fraction&);

  /*======== Унарные операторы ========*/
  Fraction& operator++();
  Fraction& operator--();
  Fraction operator-();
  Fraction operator!() const;

  /*======== Перегрузка операторов ввода и вывода ========*/
  friend std::istream& operator>>(std::istream& , Fraction&);
  friend std::ostream& operator<<(std::ostream&, const Fraction&);

};

#endif //FRACTION_HPP