/*
В текстовом файле input.txt в первой строке записано одно слово, в остальных строках - текст, слова в котором разделены одним или несколькими пробелами. 
Перед первым, а также после последнего слова строки, пробелы могут отсутствовать. Подсчитать, сколько раз это слово встречается в тексте.
*/


#include <iostream>
#include <fstream>
#include <string>
//#include <ctype.h>


void checkFile(std::fstream &file)
{
	if (!file.good())
	{
		throw std::exception("File does not exist.\n");
	}

	if (!file)
	{
		throw std::exception("File is not opened.\n");
	}

	if (file.peek() == EOF)
	{
		throw std::exception("File is empty.\n");
	}
}


void numberOfPurposeWord(std::string& purposeWord, std::fstream& file, std::string& word)
{
	std::getline(file, purposeWord);
	int32_t counter = 0;
	int32_t size = purposeWord.length();
	int32_t length = word.length();
	
	for (size_t i = 0; i < size; i++) {
		purposeWord[i] = tolower(purposeWord[i]);
	}

	for (size_t i = 0; i < length; i++) {
		word[i] = tolower(word[i]);
	}

	while (file >> word) {
		if ((word == purposeWord)) {
			counter++;
		}
	}

	if (counter != 0) {
		std::cout << "Your word - " << purposeWord << " - occurs " << counter << " times ";
	}

	else {
		std::cout << "Your word doesn`t occur in this file!";
	}
}


int main()
{
	try {
		std::string purposeWord;
		std::string word;
		std::fstream file("input.txt");
		checkFile(file);
		numberOfPurposeWord(purposeWord, file, word);
		file.close();
	}

	catch (std::exception e) {
		std::cout << e.what() << '\n';
	}
	return 0;
}

