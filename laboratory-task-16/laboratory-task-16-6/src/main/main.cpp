#include "../Train/Train.hpp"


void checkFile(std::fstream& file)
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


bool compareByDepartureTime(const Train& a, const Train& b)
{
	return a.departureTime < b.departureTime;
}


void displayInformationFromTimeRange(std::vector<Train>& train)
{
	std::string lowerInputTime;
	std::string higherInputTime;
	std::cout << "Введите нижнюю границу диапазона: ";
	std::cin >> lowerInputTime;
	std::cout << "Введите верхнюю границу диапазона: ";
	std::cin >> higherInputTime;

	for(auto& c: train)
	{
		if(c.departureTime > lowerInputTime && c.departureTime < higherInputTime)
		{
			c.print();
		}
	}
}


void displayInformationByDesName(std::vector<Train>& train)
{
	std::string newDestinitionName;
	std::cout << "Введите пункт назначения: ";
	std::cin >> newDestinitionName;

	for(auto& c : train)
	{
		if(c.destinationName == newDestinitionName)
		{
			c.print();
		}
	}
}


void displayFastTrains(std::vector<Train>& train)
{
	std::string newDestinitionName;
	std::cout << "Введите пункт назначения: ";
	std::cin >> newDestinitionName;

	for(auto& c : train)
	{
		if(c.destinationName == newDestinitionName)
		{
			if(c.trainType == "Fast")
			{
				c.print();
			}
		}
	}
}


void foundFastestTrain(std::vector<Train>& train)
{
	std::string newDestinitionName;
	std::cout << "Введите пункт назначения: ";
	std::cin >> newDestinitionName;

	Train *fastestTrain = nullptr;
	for(auto& c:train)
	{
    	for (auto &c : train) 
		{
			if (c.destinationName == newDestinitionName) 
			{
				if (fastestTrain == nullptr || c.travelTime < fastestTrain->travelTime) 
				{
					fastestTrain = &c;
				}
			}
    	}

		if (fastestTrain != nullptr) 
		{
			std::cout << "The fastest train to " << newDestinitionName << " is " << fastestTrain->trainNumber 
			<< " with a travel time of " << fastestTrain->travelTime << std::endl;
		}
	}
}


int main()
{
	try
	{
		std::fstream file("src/resourse/train.txt");
	checkFile(file);
	std::vector<Train> trains;
	int number, ttime;
	std::string desName, trType, depTime;

	//загрузка данных из текствого файла в вектор
	while (file >> number >> desName >> trType >> depTime >> ttime)
	{
		trains.push_back(Train(number, desName, trType, depTime, ttime));
	}

	for (auto& c : trains)
	{
		c.print();
	}
	//Сортировка по времени отправления
	std::sort(trains.begin(), trains.end(), compareByDepartureTime);

	//Вывод на экран информации о поездах из заданного диапазона времени
	displayInformationFromTimeRange(trains);

	//Вывод на экран информации о поездах направляющихся в заданный пункт назначения
	displayInformationByDesName(trains);

	//Вывод на экран скорых поездов направляющихся в заданный пункт назначения
	displayFastTrains(trains);

	//нахождение самого быстрого поезда
	foundFastestTrain(trains);
	}

	catch(std::invalid_argument e)
	{
		std::cerr << e.what() << '\n';
	}
	
	catch(std::runtime_error r)
	{
		std::cerr << r.what();
	}

	catch(std::logic_error l)
	{
		std::cerr << l.what();
	}
	return 0;
}