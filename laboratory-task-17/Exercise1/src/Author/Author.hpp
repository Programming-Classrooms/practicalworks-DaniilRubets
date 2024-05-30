#ifndef AUTHOR_HPP
#define AUTHOR_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>


class Author {
private:
    std::string sureName;
    std::string name;
    std::string fatherName;
public:
    Author() = default;
    Author(std::string, std::string, std::string);
    Author(const Author&);
    virtual ~Author() {}

    std::string getSureName() const;
    std::string getName() const;
    std::string getFatherName() const;

    void setSureName(const std::string&);
    void setName(const std::string&);
    void setFatherName(const std::string&);

    bool operator==(const Author&) const;
    bool operator<(const Author&) const;
    bool operator>(const Author&) const;

    Author& operator=(const Author&);

    friend std::ostream& operator<<(std::ostream&, const Author&);
    friend std::istream& operator>>(std::istream&, Author&);
};
#endif