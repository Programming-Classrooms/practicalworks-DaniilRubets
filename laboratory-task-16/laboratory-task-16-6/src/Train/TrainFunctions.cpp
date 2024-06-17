#include "../Train/Train.hpp"

Train::Train():trainNumber(0), destinationName(nullptr), trainType(nullptr), departureTime(nullptr),
travelTime(0)
{}

Train::Train(int num, std::string& name, std::string& type, std::string& time, int ttime): 
	trainNumber(num), destinationName(name), trainType(type), departureTime(time), travelTime(ttime)
{}


Train::Train(const Train& rhs): trainNumber(rhs.trainNumber), destinationName(rhs.destinationName),
trainType(rhs.trainType), departureTime(rhs.departureTime),travelTime(rhs.travelTime)
{}


int Train::getTrainNimber()
{
	return this->trainNumber;
}


std::string Train::getDestinitionName()
{
	return this->destinationName;
}


std::string Train::getTrainType()
{
	return this->trainType;
}


std::string Train::getDepartureTime()
{
	return this->departureTime;
}


int Train::getTravelTime()
{
	return this->travelTime;
}


void Train::setTrainNumber(int num)
{
	this->trainNumber = num;
}


void Train::setDestinitionName(std::string& name)
{
	this->destinationName = name;
}


void Train::setTrainType(std::string& type)
{
	this->trainType = type;
}


void Train::setDepartureTime(std::string& time)
{
	this->departureTime = time;
}


void Train::setTravelTime(int time)
{
	this->travelTime = time;
}


void Train::print()
{
	std::cout << trainNumber << " " << destinationName << " " << trainType;
	std::cout << departureTime << '\n' << travelTime << '\n';
}
