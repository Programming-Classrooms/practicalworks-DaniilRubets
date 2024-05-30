#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include "../Bus/Bus.hpp"


void checkFile(std::ifstream& file)
{
	if (!file.good())
	{
		throw std::ios_base::failure("File does not exist.\n");
	}

	if (!file)
	{
		throw std::ios_base::failure("File is not opened.\n");
	}

	if (file.peek() == EOF)
	{
		throw std::ios_base::failure("File is empty.\n");
	}
}

bool compareByBusNumber(const Bus& a, const Bus& b)
{
    return a.busNumber > b.busNumber;
}

bool compareByBusRouteNumber(const Bus& a, const Bus& b)
{
    return a.busRouteNumber > b.busRouteNumber;
}

void print (std::list<Bus>& buses)
{
    for(auto& bus: buses)
    {
        std::cout << bus << '\n';
    }
}


void printByRoute(std::map<std::string,Bus>& Buses, int routeNumber)
{
    for(auto& c:Buses)
    {
        if(routeNumber == c.second.busRouteNumber)
        {
            std::cout << c.first << c.second;
        }

    }
}


void printByBusName(std::map<std::string, Bus>& Buses, std::string name)
{
    for(auto& c: Buses)
    {
        if(name == c.second.busName)
        {
            std::cout << c.first << c.second;
        }
    }
}


int main()
{
    try
    {
        std::ifstream fileIn("src/resourse/Bus.txt");
        checkFile(fileIn);

        Bus temp;
        std::list<Bus>buses;
        while(fileIn >> temp.busRouteNumber >> temp.driverName >> temp.busNumber >> temp.busName)
        {
            buses.push_back(temp);
        } 

        print(buses);
        std::cout << "#########################" << std::endl;

        /*######## Сортировка по номеру автобуса #########*/
        for(auto& bus : buses)
        {
            std::sort(buses.begin(), buses.end(), compareByBusNumber);
        }

        print(buses);
        std::cout << "#########################" << std::endl;
        

        /*######## Сортировка по номеру маршрута #########*/
        for(auto& bus: buses)
        {
            std::sort(buses.begin(), buses.end(), compareByBusRouteNumber);
        }

        print(buses);
        std::cout << "#########################" << std::endl;

        std::map<std::string, Bus> Buses;

        /*######## Перенос данных из list в map #########*/
        for(auto& bus: buses)
        {
            Buses.emplace(bus.driverName, bus);
        }


        std::cout << "#########################";
        for(auto& c : Buses)
        {
            std::cout << c.first << c.second;
        }

        /*######## Вывод автобусов указанного маршрута #########*/
        std::cout << "#########################";
        int routeNumber;
        std::cout << "Input number of bus route: ";
        std::cin >> routeNumber;
        printByRoute(Buses, routeNumber);


        /*######## Вывод автобусов указанной марки #########*/
        std::cout << "#########################";
        std::string BusName;
        std::cout << "Input bus name: ";
        std::cin >> BusName;
        printByBusName(Buses, BusName);

        
        /*######## Удаление из контейнера указанной информации #######*/
        std::string driver;
        std::cout << "Input name of driver: ";
        std::cin >> driver;
        for(auto& c: Buses)
        {
            if(driver == c.first)
            {
                Buses.erase(c.first);
            }
        }

    }

    catch(std::logic_error l)
    {
        std::cerr << l.what();
    }

    catch(std::runtime_error r)
    {
        std::cerr << r.what();
    }

    catch(std::invalid_argument in)
    {
        std::cerr << in.what();
    }

    catch(std::ios_base::failure f)
    {
        std::cerr << f.what();
    }

    return 0;
}