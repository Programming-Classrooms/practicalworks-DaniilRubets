#include "Book.hpp"

Book::Book() : UDC(0), yearOfPublish(0) {}

Book::Book(const size_t& udc, const AuthorList& authors, const std::string& title, const size_t& year)
    : UDC(udc), bookAuthors(authors), bookTitle(title), yearOfPublish(year) {}

Book::Book(const Book& other)
    : UDC(other.UDC), bookAuthors(other.bookAuthors), bookTitle(other.bookTitle), yearOfPublish(other.yearOfPublish) {}

size_t Book::getUDC() const {
    return UDC;
}

AuthorList Book::getAuthors() const {
    return bookAuthors;
}

std::string Book::getBookTitle() const {
    return bookTitle;
}

size_t Book::getYearOfPublish() const {
    return yearOfPublish;
}

void Book::setUDC(const size_t& udc) {
    UDC = udc;
}

void Book::setBookAuthors(const AuthorList& authors) {
    bookAuthors = authors;
}

void Book::setBookTitle(const std::string& title) {
    bookTitle = title;
}

void Book::setYearOfPublish(const size_t& year) {
    yearOfPublish = year;
}

bool Book::operator==(const Book& other) const {
    return UDC == other.UDC && bookAuthors == other.bookAuthors && bookTitle == other.bookTitle && yearOfPublish == other.yearOfPublish;
}

bool Book::operator<(const Book& other) const {
    return yearOfPublish < other.yearOfPublish;
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        UDC = other.UDC;
        bookAuthors = other.bookAuthors;
        bookTitle = other.bookTitle;
        yearOfPublish = other.yearOfPublish;
    }
    return *this;
}

void Book::clear() {
    UDC = 0;
    bookAuthors = AuthorList();
    bookTitle.clear();
    yearOfPublish = 0;
}

void Book::addAuthor(const Author& author) {
    bookAuthors.insert(author);
}

void Book::addAuthor(const std::string& firstName, const std::string& lastName, const std::string& middleName) {
    bookAuthors.emplace(firstName, lastName, middleName);
}

void Book::eraseAuthor(const std::string& firstName, const std::string& lastName, const std::string& middleName) {
    bookAuthors.erase(firstName, lastName, middleName);
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "UDC: " << book.UDC << "\n";
    os << "Title: " << book.bookTitle << "\n";
    os << "Year of Publish: " << book.yearOfPublish << "\n";
    os << "Authors: " << book.bookAuthors << "\n";
    return os;
}


std::istream& operator>>(std::istream& is, Book& book) {
    is >> book.UDC;
    is.ignore(10000, '\n'); 
    std::getline(is, book.bookTitle);
    is >> book.yearOfPublish;
    return is;
}
