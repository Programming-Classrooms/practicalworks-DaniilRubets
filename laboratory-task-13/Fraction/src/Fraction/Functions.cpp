#include "../Fraction/Fraction.hpp"
Fraction::Fraction() { //конструктор по умолчанию
  numerator = 0;
  denominator = 1;
  reduce();
}


Fraction::Fraction(int32_t i) { //конструктор с параметром
  numerator = i;
  denominator = 1;
  reduce();
}


Fraction::Fraction(int32_t i, int32_t j) { //конструктор с параметрами
  numerator = i;
  denominator = j;
  reduce();
}


Fraction::Fraction(const Fraction& rhs) { //конструктор копирования 
  numerator = rhs.numerator;
  denominator = rhs.denominator;
  reduce();
}


Fraction::~Fraction() { //деструктор
  numerator = 1;
  denominator = 1;
}


int32_t Fraction::getN() { //геттер
  return numerator;
}


int32_t Fraction::getD() { //геттер
  return denominator;
}


int32_t Fraction::setN(int32_t i) { //сеттер
  return numerator = i;
}


int32_t Fraction::setD(int32_t j) { //сеттер
  return denominator = j;
}


int32_t NOD(int32_t a, int32_t b) {
  while (b != 0) {
    int32_t temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}


void Fraction::reduce() {
  int32_t gcd_value = NOD(numerator, denominator);
  numerator /= gcd_value;
  denominator /= gcd_value;
}


Fraction Fraction::operator+(int32_t number)
{
  int32_t num = ((number * this->denominator) + this->numerator);
  Fraction a(num, this->denominator);
  a.reduce();
  return a;
}


Fraction operator+ (int32_t number, Fraction& rhs)
{
  Fraction temp = rhs + number;
  temp.reduce();
  return temp;
}


Fraction Fraction::operator+(const Fraction& rhs) { //перегрузка оператора сложения
  int32_t num = (numerator * rhs.denominator) + (rhs.numerator * denominator);
  int32_t den = denominator * rhs.denominator;
  Fraction a(num, den);
  a.reduce();
  return a;
}


Fraction Fraction::operator-(const Fraction& rhs) { //перегрузка оператора вычитания 
  int32_t num = (numerator * rhs.denominator) - (rhs.numerator * denominator);
  int32_t den = (denominator * rhs.denominator);
  Fraction a(num, den);
  a.reduce();
  return a;
}


Fraction Fraction::operator-(int32_t number)
{
  int32_t temp = this->denominator * number;
  int32_t newNum = this->numerator - temp;
  Fraction a(newNum, this->denominator);
  a.reduce();
  return a;
}


Fraction operator-(int32_t number, Fraction& rhs)
{
  Fraction temp = rhs - number;
  temp.reduce();
  return temp;
}


Fraction Fraction::operator*(const Fraction& rhs) { //перегрузка оператора деления 
  int32_t num = numerator * rhs.numerator;
  int32_t den = denominator * rhs.denominator;
  Fraction a(num, den);
  a.reduce();
  return a;
}


Fraction Fraction::operator*(int32_t number)
{
  int32_t temp = this->numerator * number;
  Fraction a(temp, this->denominator);
  a.reduce();
  return a;
}


Fraction Fraction::operator/(const Fraction& rhs) { //перегрузка оператора деления 
  if (rhs.numerator == 0) {
    throw std::invalid_argument("Division by zero");
  }
  int num = numerator * rhs.denominator;
  int den = denominator * rhs.numerator;
  Fraction a(num, den);
  a.reduce();
  return a;
}


Fraction Fraction::operator/(int32_t number)
{
  if (number == 0)
  {
    throw std::invalid_argument("Devision by zero!");
  }
  Fraction a(this->numerator, this->denominator * number);
  a.reduce();
  return a;
}


bool Fraction::operator==(const Fraction& rhs) { //перегрузка оператора равно
  return (numerator * rhs.denominator) == (denominator * rhs.numerator);
}


bool Fraction::operator<(const Fraction& rhs) { //перегрузка оператора меньше
  return (numerator * rhs.denominator) < (denominator * rhs.numerator);
}


//bool Fraction::operator>(const Fraction& rhs) { //перегрузка оператора больше
//  return (numerator * rhs.denominator) > (denominator * rhs.numerator);
//}


bool Fraction::operator>(Fraction& rhs)
{
  return !((rhs < (*this)) && (rhs == (*this)));
}


Fraction& Fraction::operator++() { //перегрузка инкремента 
  numerator += denominator;
  reduce();
  return *this;
}


Fraction& Fraction::operator--() { //перегрузка декремента 
  numerator -= denominator;
  reduce();
  return *this;
}


Fraction Fraction::operator-() { //перегрузка унарного минуса 
  return Fraction(-numerator, denominator);
}


Fraction Fraction::operator!() const{
  if (numerator == 0) 
  {
    throw std::invalid_argument("The reciprocal fraction is undefined!");
  }
  return Fraction(denominator, numerator);
}


std::istream& operator>>(std::istream& in, Fraction& rhs) {
  std::cout << "Input numerator: ";
  in >> rhs.numerator;
  std::cout << "Input denominator: ";
  in >> rhs.denominator;
  rhs.reduce();
  if (rhs.denominator == 0) {
    std::cout << "Devision by zero" << std::endl;
  }
  return in;
}


std::ostream& operator<<(std::ostream& out, const Fraction& rhs) {
  out << rhs.numerator << '/' << rhs.denominator << '\n';
  return out;
}


Fraction Fraction::operator=(const Fraction& rhs) {
  if (this != &rhs) {
    numerator = rhs.numerator;
    denominator = rhs.denominator;
  }
  return *this;
}


Fraction& Fraction::operator+=(const Fraction& rhs) {
  numerator = (numerator * rhs.denominator) + (rhs.numerator * denominator);
  denominator *= rhs.denominator;
  reduce();
  return *this;
}


Fraction& Fraction::operator+=(int32_t number)
{
  Fraction temp(this->numerator, this->denominator);
  temp + number;
  return temp;
}


Fraction& Fraction::operator-=(const Fraction& rhs) {
  numerator = (numerator * rhs.denominator) - (rhs.numerator * denominator);
  denominator *= rhs.denominator;
  reduce();
  return *this;
}


Fraction& Fraction::operator*=(const Fraction& rhs) {
  numerator *= rhs.numerator;
  denominator *= rhs.denominator;
  reduce();
  return *this;
}


Fraction& Fraction::operator*=(int32_t number)
{
  numerator *= number;
  reduce();
  return *this;
}



Fraction& Fraction::operator/=(const Fraction& rhs) {
  if (rhs.numerator == 0) {
    throw std::invalid_argument("Devision by zero!");
  }
  numerator *= rhs.denominator;
  denominator *= rhs.numerator;
  reduce();
  return *this;
}


Fraction& Fraction::operator/=(int32_t number)
{
  Fraction temp(this->numerator, this->denominator);
  temp / number;
  temp.reduce();
  return temp;
}