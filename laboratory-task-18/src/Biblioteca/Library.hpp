/*
Описать класс Library, содержащий коллекцию объектов класса Book.
Реализовать следующий функционал:
o Добавить книгу.
o Найти книгу (по идентификационному номеру).
o Удалить книгу (по идентификационному номеру).
o Просмотреть список книг.
o Добавить автора (по идентификационному номеру).
o Удалить автора (по идентификационному номеру).
o Сортировать список книг по идентификационному номеру.
o Сортировать список книг по алфавиту названий.
*/


#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include "../Book/Book.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Library
{
private:
	std::vector<Book> books;
public:
    /*######## Конструкторы ########*/
    Library();
    Library(std::vector<Book>&);
    Library(const Library&);

    /*######## Деструктор ########*/
    ~Library();

    /*######## Геттеры ########*/
    std::vector<Book> getBooks();

    /*######## Сеттеры ########*/
    void setBooks(std::vector<Book>&);

    Library operator=(const Library&);

    /*######## Методы ########*/
    void addBook(const Book&);
    Book findBook(std::string&);
    void deleteBook(std::string&);
    void viewAllBooks();
    void addAuthor(std::string&, std::string&);
    void deleteAuthor(std::string&);
    void sortByIBSN();
    void sortByAlphapet();

};
#endif //LIBRARY_HPP
