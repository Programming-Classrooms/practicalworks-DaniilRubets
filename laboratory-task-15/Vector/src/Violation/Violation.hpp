#include <string>
#include <iostream>

class Violation 
{
private:
    std::string type;
    std::string description;
    int fine;
    bool wasPaid;

public:
    Violation(std::string&, std::string&, int);

    std::string getType() const;
    std::string getDescription() const;
    int getFine() const;

    void setFine(int);
    void payFine();
    bool checkPayment() const;

    friend std::ostream& operator<<(std::ostream& os, const Violation&);
};