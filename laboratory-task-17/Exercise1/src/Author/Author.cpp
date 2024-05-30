#include "Author.hpp"

Author::Author(std::string initSurename, std::string initName, std::string initFathername):
sureName(initSurename), name(initName), fatherName(initFathername)
{}

Author::Author(const Author& src) : sureName(src.sureName), name(src.name), fatherName(src.fatherName) 
{}

std::string Author::getSureName() const
{
    return sureName;
}

std::string Author::getName() const
{
    return name;
}

std::string Author::getFatherName() const
{
    return fatherName;
}

void Author::setSureName(const std::string& str)
{
    sureName = str;
}

void Author::setName(const std::string& str)
{
    this->name = str;
}

void Author::setFatherName(const std::string& str)
{
    this->fatherName = str;
}

bool Author::operator==(const Author& rhs) const
{
    return this->sureName == rhs.sureName && this->name == rhs.name && this->fatherName == rhs.fatherName;
}

bool Author::operator<(const Author& rhs) const
{
    if (this->sureName == rhs.sureName) {
        if (this->name == rhs.name) {
            return this->fatherName < rhs.fatherName;
        }
        return this->name < rhs.name;
    }
    return this->sureName < rhs.sureName;
}

bool Author::operator>(const Author& rhs) const
{
    return !(*this < rhs) && !(*this == rhs);
}

Author& Author::operator=(const Author& src)
{
    if (this != &src) {
        sureName = src.sureName;
        name = src.name;
        fatherName = src.fatherName;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Author& src)
{
    out << src.sureName << src.name << src.fatherName << '\n';
    return out;
}

std::istream &operator>>(std::istream& in, Author& dest)
{
    std::string line;
    std::getline(in, line, ',');

    dest.sureName = line;
    std::getline(in, line, ',');

    dest.name = line;
    std::getline(in, line, ';');

    dest.fatherName = line;
    return in;
}