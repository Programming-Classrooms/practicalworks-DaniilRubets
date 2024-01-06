/*
	Задан текстовый файл input.txt. 
	Требуется определить строки этого  файла, содержащие максимальную по длине подстроку, состоящую из  одинаковых символов русского алфавита. 
	Заглавные и строчные буквы не различаются. 
	Если таких строк несколько, найти первые 10. Результат  вывести на консоль в форме, удобной для чтения.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>


void checkFile(std::fstream& file)
{
	if (!file.good()) {
		throw std::exception("File does not exist!");
	}

	if (!file) {
		throw std::exception("File is not opened!");
	}

	if (file.peek() == EOF) {
		throw std::exception("File is empty!");
	}
}


bool checkRussianSymbols(char c)
{
	return (c >= 'А' && c <= 'я' || c == 'Ё' || c == 'ё');
}


std::string searchMaxSubstring(std::fstream& file, std::string& line)
{
	int32_t currLength = 0;
	size_t counter = 0;
	int32_t maxLength = 0;
	std::string maxSubstring;

	while (std::getline(file, line)) {
		int32_t currLength = 0;
		char currChar = '\0';
		int32_t size = line.size();

		for (size_t i = 0; i < size; i++) {
			line[i] = tolower(line[i]);

			if (checkRussianSymbols(line[i])) {
				if (line[i] == currChar) {
					currLength++;
				}

				else {
					currChar = line[i];
					currLength = 1;
				}

				if (currLength > maxLength) {
					maxLength = currLength;
					maxSubstring = line;
					counter = 0;
				}

				else if (currLength == maxLength && counter < 10) {
					maxSubstring += line + "\n";
					counter++;
				}
			}

			else {
				currChar = '\0';
				currLength = 0;
			}
		}
	}

	return maxSubstring;
}


int main()
{
	try {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		std::fstream file("input.txt");
		std::string line;
		std::string words;
		checkFile(file);
		std::cout << searchMaxSubstring(file, line);
		file.close();
	}
	catch (std::exception e) {
		std::cout << e.what() << '\n';
	}
	return 0;
}

