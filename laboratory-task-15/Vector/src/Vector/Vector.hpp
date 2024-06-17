#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

template<typename T>
class Vector
{
private:
  std::vector<T> data;

public:
  /*####### Конструкторы #######*/
  Vector();
  Vector(const Vector&);

  /*####### Деструктор #######*/
  ~Vector();

  /*####### Оператор присваивания #######*/
  Vector<T> operator=(const Vector&);

  /*####### Оператор сравнения #######*/
  bool operator==(const Vector&) const;

  /*####### Методы #######*/
  T& operator[] (size_t);
  void pushBack(const T&);
  void popBack(const T&);
  typename std::vector<T>::iterator find(const T&);
  void sort();

  /*####### Вывод #######*/
  friend std::ostream& operator << (std::ostream&, const Vector&);
};

#include "../Vector/Vector.inl"
#endif //VECTOR_HPP