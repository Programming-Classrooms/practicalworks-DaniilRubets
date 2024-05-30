#include "../Violation/Violation.hpp"

Violation::Violation(std::string& typ, std::string& descript, int fin ): 
type(typ), description(descript), fine(fin), wasPaid(false) 
{}

std::string Violation::getType() const 
{
    return type;
}


std::string Violation::getDescription() const 
{
    return description;
}


int Violation::getFine() const 
{
    return fine;
}


void Violation::setFine(int newFine) 
{
    fine = newFine;
}


void Violation::payFine() 
{
    wasPaid = true;
}


bool Violation::checkPayment() const 
{
    return wasPaid;
}


std::ostream& operator<<(std::ostream& os, const Violation& violation) 
{
    os << "Type of violation: " << violation.getType() << '\n'
       << "Description: " << violation.getDescription() << '\n'
       << "Fine: " << violation.getFine() << " Byn\n"
       << "Paid: " << (violation.checkPayment() ? "Yes" : "No") << '\n';
    return os;
}