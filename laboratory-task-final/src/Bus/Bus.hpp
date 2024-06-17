#include <string>
#include <iostream>
#ifndef BUS_HPP
#define BUS_HPP

class Bus
{
    public:
    int busRouteNumber;
    std::string driverName;
    int busNumber;
    std::string busName;

    /*######## Конструкторы ########*/
    Bus();
    Bus(int, std::string, int, std::string);
    Bus(const Bus&);

    /*######## Геттеры ########*/
    int getBusRouteNumber();
    std::string getDriverName();
    int getBusNumber();
    std::string getBusName();

    /*####### Оператор присваивания #######*/
    Bus operator=(const Bus&);

    /*######## Перегрузка оператора вывода ########*/
    friend std::ostream& operator << (std::ostream&, Bus&);

};

#endif //BUS_HPP
