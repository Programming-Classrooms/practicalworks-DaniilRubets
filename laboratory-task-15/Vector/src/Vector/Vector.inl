#include "../Vector/Vector.hpp"

template<typename T>
Vector<T>::Vector():data()
{}


template<typename T>
Vector<T>::Vector(const Vector& rhs):data(rhs.data)
{}


template<typename T>
Vector<T>::~Vector()
{
  data.clear();
}

template<typename T>
Vector<T> Vector<T>::operator=(const Vector& rhs)
{
  if (this != & rhs) {
    data = rhs.data;
  }
  return *this;
}


template<typename T>
bool Vector<T>::operator==(const Vector& rhs) const
{
  return this->data == rhs.data;
}


template<typename T>
T& Vector<T>::operator[](size_t index)
{
  return data[index];
}


template<typename T>
void Vector<T>::pushBack(const T& value)
{
  this->data.push_back(value);
}


template<typename T>
void Vector<T>::popBack(const T& value)
{
  this->data.pop_back(value);
}


template<typename T>
typename std::vector<T>::iterator Vector<T>::find(const T& value)
{
  return std::find(data.begin(), data.end(), value);
}


template<typename T>
void Vector<T>::sort()
{
  std::sort(data.begin(), data.end());
}

template<typename T>
std::ostream& operator << (std::ostream& os, const Vector<T>& rhs)
{
  for (auto& c : rhs.data)
  {
    os << c << std::setw(2);
  }
}