#include "../Bus/Bus.hpp"

Bus::Bus():busRouteNumber(0), driverName(""), busNumber(0), busName("")
{}

Bus::Bus(int rnum, std::string drName, int busnum, std::string busname):
busRouteNumber(rnum), driverName(drName), busNumber(busnum), busName(busname)
{}

Bus::Bus(const Bus& rhs):busRouteNumber(rhs.busRouteNumber), driverName(rhs.driverName), busNumber(rhs.busNumber),
 busName(rhs.busName)
 {}


 int Bus::getBusRouteNumber()
 {
    return this->busRouteNumber;
 }


 std::string Bus::getDriverName()
 {
    return this->driverName;
 }


   Bus Bus::operator=(const Bus& rhs)
   {
     Bus(rhs);
   }


 std::ostream& operator << (std::ostream& os, Bus& rhs)
 {
    std::cout << "№ маршрута: " << rhs.busRouteNumber << '\n';
    std::cout << "Водитель: " << rhs.driverName << '\n';
    std::cout << "№ автобуса: " << rhs.busNumber << '\n';
    std::cout << "Марка автобуса: " << rhs.busName << '\n';
    return os;
 }