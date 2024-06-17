/*Описать класс, с именем Train, содержащий информацию о поездах,
отправляющихся с одной и той же станции, и содержащий следующие поля:
o номер поезда;
o название пункта назначения;
o тип поезда (пассажирский, скорый);
o время отправления (часы, минуты в формате ЧЧ:ММ);
o время в пути.
Написать программу, выполняющую следующие действия:
o ввод данных в vector из текстового файла;
o упорядочение данных по времени отправления поездов;
o вывод на экран информации обо всех поездах из заданного
диапазона времени;
o вывод на экран информации о всех поездах, направляющихся
в заданный пункт назначения;
o вывод на экран всех скорых поездов, направляющихся в
заданный пункт назначения;
o нахождение самого быстрого поезда, следующего в заданный
пункт назначения.
Меню делать не нужно. Выдать на экран все результаты с пояснениями
на русском языке.*/
#ifndef TRAIN_HPP
#define TRAIN_HPP
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>


class Train
{
public:
	int trainNumber;
	std::string destinationName;
	std::string trainType;
	std::string departureTime;
	int travelTime;
	
	Train();
	Train(int, std::string&, std::string&, std::string&, int);
	Train(const Train&);

	
	int getTrainNimber();
	std::string getDestinitionName();
	std::string getTrainType();
	std::string getDepartureTime();
	int getTravelTime();

	
	void setTrainNumber(int);
	void setDestinitionName(std::string&);
	void setTrainType(std::string&);
	void setDepartureTime(std::string&);
	void setTravelTime(int);

	void print();
};
#endif //TRAIN_HPP