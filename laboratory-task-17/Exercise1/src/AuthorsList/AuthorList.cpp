#include "AuthorList.hpp"

AuthorList::AuthorList() = default;

AuthorList::AuthorList(const std::set<Author>& authors) : authorsList(authors) 
{}

AuthorList::AuthorList(const AuthorList& other) : authorsList(other.authorsList) {}

void AuthorList::insert(const Author& author) {
    authorsList.insert(author);
}

void AuthorList::emplace(const std::string& firstName, const std::string& lastName, const std::string& middleName) {
    authorsList.emplace(firstName, lastName, middleName);
}

AuthorList& AuthorList::operator=(const AuthorList& rhs) {
    if (this != &rhs) {
        authorsList = rhs.authorsList;
    }
    return *this;
}

bool AuthorList::operator==(const AuthorList& rhs) const {
    return authorsList == rhs.authorsList;
}

void AuthorList::erase(const std::string& firstName, const std::string& lastName, const std::string& middleName) {
    Author temp(firstName, lastName, middleName);
    authorsList.erase(temp);
}

bool AuthorList::find(const Author& author) {
    return authorsList.find(author) != authorsList.end();
}

std::ostream& operator<<(std::ostream& os, const AuthorList& authorList) {
    for (const auto& author : authorList.authorsList) {
        os << author << '\n';
    }
    return os;
}
