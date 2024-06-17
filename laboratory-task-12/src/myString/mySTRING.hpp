#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <cstring>
class string
{
private:
	uint32_t size;
	char* str;
public:
	/*======== Конструкторы ========*/
	string();//Конструктор по умолчанию
	string(const char*);// конструктор с параметром
	string(const string&);//конструктор копирования
	string(string&&) noexcept;//конструктор перемещения


	/*======== Деструткор ========*/
	~string();


	/*======== Геттеры ========*/
	uint32_t getSize() const;
	char* getStr() const;


	/*======== Сеттеры ========*/
	void setSize(uint32_t);
	void setStr(const char*);


	/*======== Методы ========*/
	bool isEmpty();//проверка на пустоту
	void append(const string&);//конкатенация
	size_t length();//размер строки
	int64_t findIndex(const char);//поиск элемента по индексу


	/*======== Операторы присваивания ========*/
	string& operator += (const string&);
	string& operator = (const string&);


	/*============== Операторы сравнения ==============*/
	bool operator == (const string&);
	bool operator != (const string&);
	bool operator <(const string&);
	bool operator >(const string&);


	/*======== Перегрузка операторов ввода и вывода ========*/ 
	friend std::istream& operator >>(std::istream&, string&);
	friend std::ostream& operator << (std::ostream&, const string&);
};
#endif //MYSTRING_H
