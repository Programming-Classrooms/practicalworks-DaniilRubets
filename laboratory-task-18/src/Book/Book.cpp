#include "../Book/Book.hpp"

std::string Book::IDnum = "0000000000000";

std::string& Book::IDnumIncr()
{
	size_t size = 13;
	for (int32_t i = size; i > -1; --i)
	{
		if (IDnum[i-1] != '9')
		{
			IDnum[i-1]++;
			return IDnum;
		}
	}

	throw std::out_of_range("Too many books.");	
}


Book::Book()
{
	this->IBSN = IDnumIncr();                                   
	this->title = "";
	this->authors = std::vector<std::string>();
	this->price = 0.0;
	this->count = 0;
}


Book::Book(
	const std::string& newTitle, 
	const std::vector<std::string>& newAuthors, 
	const double newPrice, 
	const int newCount
)
{
	this->IBSN = IDnumIncr();
	this->title = newTitle;
	this->authors = newAuthors;
	this->price = newPrice;
	this->count = newCount;
}


Book::Book(const Book& rhs)
{
	this->IBSN = rhs.IBSN;
	this->title = rhs.title;
	this->authors = rhs.authors;
	this->price = rhs.price;
	this->count = rhs.count;
}


Book::~Book()
{
	this->title = "";
	this->authors.clear();
	this->price = 0.0;
	this->count = 0;
}


std::string Book::getIBSN()
{
	return this->IBSN;
}


std::string Book::getTitle()
{
	return this->title;
}


std::vector<std::string> Book::getAuthors()
{
	return this->authors;
}


double Book::getPrice()
{
	return this->price;
}


int Book::getCount()
{
	return this->count;
}


void Book::setIBSN(std::string& str)
{
	this->IBSN = IDnumIncr();
}


void Book::setTitle(std::string& str)
{
	this->title = str;
}


void Book::setAuthors(std::vector<std::string>& author)
{
	this->authors = author;
}


void Book::setPrice(double newPrice)
{
	this->price = newPrice;
}


void Book::setCount(int newCount)
{
	this->count = newCount;
}


Book Book::operator=(const Book& rhs)
{
	if (this != &rhs)
	{
		Book a(rhs);
	}
	return rhs;
}


std::ostream& operator<<(std::ostream& os, const Book& book)
{
	os << book.IBSN << '\n' << book.title << std::endl;
	for(auto& c : book.authors)
	{
		os << c << std::endl;
	} 
	os << book.price << std::setw(2) << book.count << std::endl;
	return os;
}
