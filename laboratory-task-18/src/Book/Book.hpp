/*
Описать класс Book, имеющий следующие поля:
o ISBN (идентификационный номер) – уникальное текстовое
поле
o title (название книги) – текстовое поле
o authors (коллекция авторов) – каждый автор - текстовое поле
o price (цена) – вещественное значение
o count (количество экземпляров) – целое значение
*/
#ifndef BOOK_HPP
#define BOOK_HPP
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


class Book
{
private:
	static std::string IDnum;
	
	Book();

	std::string& IDnumIncr();
public:
	std::string IBSN;
	std::string title;
	std::vector<std::string> authors;
	double price;
	int count;

	Book(const std::string&, const std::vector<std::string>&, const double, const int);
	Book(const Book&);
	~Book();

	std::string getIBSN();
	std::string getTitle();
	std::vector<std::string> getAuthors();
	double getPrice();
	int getCount();


	void setIBSN(std::string&);
	void setTitle(std::string&);
	void setAuthors(std::vector<std::string>&);
	void setPrice(double);
	void setCount(int);


	Book operator=(const Book&);

	friend std::ostream& operator << (std::ostream&, const Book&);
};

#endif //BOOK_HPP