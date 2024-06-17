#include "Library.hpp"


bool compareByIBSN(const Book& rhs, const Book& lhs)
{
    return rhs.IBSN < lhs.IBSN;
}


bool compareByAlphapet(const Book& rhs, const Book& lhs)
{
    return rhs.title > lhs.title;
}


Library::Library()
{
    std::vector<Book>();
}


Library::Library(std::vector<Book>& book)
{
    this->books = book;
}


Library::Library(const Library& rhs)
{
    this->books = rhs.books;
}


Library::~Library()
{
    this->books.clear();
}


std::vector<Book> Library::getBooks()
{
    return this->books;
}


void Library::setBooks(std::vector<Book>& book)
{
    this->books = book;
}


Library Library::operator=(const Library& rhs)
{
    if(this != &rhs)
    {
        Library a(rhs);
        return a;
    }
}


void Library::addBook(const Book& book)
{
    this->books.push_back(book);
}


Book Library::findBook(std::string& ibsn)
{
    for(auto& c : books)
    {
        if(c.IBSN == ibsn)
        {
            return c;
        }
    }
}


void Library::deleteBook(std::string& ibsn)
{
    this->books.erase(std::find_if(this->books.begin(), this->books.end(), [ibsn](const Book& source){ return source.IBSN == ibsn;}));
}


void Library::viewAllBooks()
{
    for(auto& c : books)
    {
        std::cout << c << '\n';
    }
}


void Library::addAuthor(std::string& ibsn, std::string& newAuthor)
{
    for(auto& c : books)
    {
        if(c.IBSN == ibsn)
        {
            c.authors.push_back(newAuthor);
            break;
        }
    }
}


void Library::deleteAuthor(std::string& ibsn)
{
    for(auto& c : books)
    {
        if(c.IBSN == ibsn)
        {
            c.authors.clear();
        }
    }
}


void Library::sortByIBSN()
{
    for(auto& c: books)
    {
        std::sort(books.begin(), books.end(), compareByIBSN);
    }
}


void Library::sortByAlphapet()
{
    for(auto& c: books)
    {
        std::sort(books.begin(), books.end(), compareByAlphapet);
    }
}