/*
    Строка состоит из слов, разделённых знаками препинания. 
    За один просмотр символов строки найти все слова, содержащие наибольшее количество различных символов, и занести их в новую строку. 
    Слова в новой строке должны разделяться ровно одним пробелом. 
    Решение задачи получить за один просмотр символов строки.
*/


#include <iostream>
#include <string>


void checkString(std::string& str)
{
    if (str.empty() == true) {
        std::cout << "Your string is empty!";
        std::getline(std::cin, str);
    }
}


std::string findMaxUnigueChars(std::string& str, std::string& word, std::string& maxWord, size_t& maxUnigueChars, size_t& start, size_t& end)
{
    while (end != std::string::npos) {
        word = str.substr(start, end - start);
        std::string uniqueChars;
        size_t length = word.length();

        for (size_t j = 0; j < length; j++) {
            
            if (uniqueChars.find(word[j]) == std::string::npos) {
                uniqueChars += word[j];
            }
        }
        if (uniqueChars.size() > maxUnigueChars) {
            maxUnigueChars = uniqueChars.size();
            maxWord = word;
        }
        start = end + 1;
        end = str.find(' ', start);
    }

    return maxWord;
}


int main() 
{
    try {
        std::string str = std::string("");
        std::string delimiters = std::string(" .,-:)(!?;");
        std::string word = std::string("");
        std::string maxWord = std::string("");
        std::cout << "Input your string: ";
        std::getline(std::cin, str);
        checkString(str);
        size_t maxUnigueChars = 0;
        size_t start = 0;
        size_t end = str.find_first_of(delimiters);
        std::cout << findMaxUnigueChars(str, word, maxWord, maxUnigueChars, start, end);
    }
   catch(std::exception e) {
        std::cout << e.what();
    }
    return 0;
}

