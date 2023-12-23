/*
Словом в строке считается последовательность букв латинского алфавита, остальные символы являются разделителями между словами. 
За один просмотр символов строки найти все слова с максимальной долей гласных букв 
(т.е. прописных и строчных символов ’a’, ’e’, ’i’, ’o’, ’u’, ’y’) и занести их в новую строку. 
Слова в новой строке должны разделяться ровно одним пробелом.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


bool isVowel(char c)  
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}


void findWordsWithMaxVowels(char* str, char* result)
{
    char delimiters[] = " .,/!?-''+*=()[]<>~`@#$%^&_";
    char* word = strtok(str, delimiters);
    double maxRatio = 0.0;

    while (word != NULL) {
        int32_t vowels = 0;
        size_t length = strlen(word);

        for (size_t i = 0; i < length; i++) {
            if (isVowel(word[i])) {
                 vowels++;
            }
        }
        double ratio = (double)vowels / length;

        if (ratio > maxRatio) {
           maxRatio = ratio;
           strcpy(result,word);
        }

        else if (ratio == maxRatio) {
           strcat(result," ");
           strcat(result, word);
        }
        word = strtok(NULL, delimiters);
    }
    std::cout << "This is your word: " << result << std::endl;
}


int main() 
{
    try {
        char str[255] = "\0";
        char result[255] = "\0";
        std::cout << "Input your string: ";
        std::cin.getline(str, 255);
        int32_t size = strlen(str);

        if ((str[0] == '\0') || (str == NULL)) {
            std::cout << "String is empty! Try again!";
            std::cin.getline(str, 255);
        }
        findWordsWithMaxVowels(str, result);
    }
    catch (std::exception e) {
        std::cout << e.what();
    }
    return 0;
}

