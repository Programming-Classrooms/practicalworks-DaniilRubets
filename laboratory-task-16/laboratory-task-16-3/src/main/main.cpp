/*Создать vector<string>, прочитать в него список слов из текстового
файла. Выполнить:
o сортировку списка;
o печать отсортированного списка;
o печать элементов списка, начинающихся на заданную букву
o удаление элементов списка на заданную букву;
o печать списка после удаления элементов.*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>


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


void print(std::vector<std::string> words)
{
	for (auto& c : words)
	{
		std::cout << c << " ";
	}
	std::cout << '\n';
}


void sortVector(std::vector<std::string>& words)
{
		std::sort(words.begin(), words.end());
		std::cout << "\nWords vektor sort: ";
		print(words);
}


void printByLetter(std::vector<std::string>& words)
{
		char letter;
		std::cout << "\nInput letter for print: ";
		std::cin >> letter;
		std::cout << "\nYour vector: ";
		for (auto& c : words)
		{
			if (c[0] == letter)
			{
				std::cout << c << " ";
			}
		}
}


void eraseByLetter(std::vector<std::string>& words)
{
		char letter;
		std::cout << "\nInput letter for erase: ";
		std::cin >> letter;
		std::string str;
		for (size_t i = 0; i < words.size(); ++i)
		{
			str = words[i];
			if (str[0] == letter)
			{
				words.erase(words.begin() + i);
				--i;
			}
		}
		std::cout << "\nErase vector: ";
		print(words);
}


int main()
{
	try
	{
		std::vector<std::string> words;
		std::fstream file("src/resourse/texts.txt");
		std::string temp;
		checkFile(file);
		while (file >> temp)
		{
			words.push_back(temp);
		}
		file.close();
		std::cout << "It is your vector: ";
		print(words);
		std::cout << "\n\n#######################";
		sortVector(words);
		std::cout << "\n\n#######################";
		printByLetter(words);
		std::cout << "\n\n#######################";
		eraseByLetter(words);
	}

	catch(std::ios_base::failure e)
	{
		std::cerr << e.what();
	}

	catch(std::logic_error l)
	{
		std::cerr << l.what();
	}

	catch(std::runtime_error r)
	{
		std::cerr << r.what();
	}

	catch(std::invalid_argument i)
	{
		std::cerr << i.what();
	}

	return 0;
}