#include "Library.hpp"
#include <iostream>

Library::Library(const Library& other) : library(other.library) {}

void Library::insertBook(const Book& book) {
    library.insert(std::make_pair(book.getBookTitle(), book));
}

void Library::eraseBook(const Book& book) {
    auto range = library.equal_range(book.getBookTitle());
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == book) {
            library.erase(it);
            break;
        }
    }
}

void Library::insertAuthor(Book& book, const Author& author) {
    book.addAuthor(author);
    auto range = library.equal_range(book.getBookTitle());
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == book) {
            it->second = book;
            break;
        }
    }
}

void Library::eraseAuthor(Book& book, const Author& author) {
    book.eraseAuthor(author.getSureName(), author.getName(), author.getFatherName());
    auto range = library.equal_range(book.getBookTitle());
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == book) {
            it->second = book;
            break;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Library& lib) {
    for (const auto& pair : lib.library) {
        os << pair.second << '\n';
    }
    return os;
}
