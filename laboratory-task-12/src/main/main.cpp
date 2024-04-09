#include "../myString/mySTRING.hpp"
#include <iostream>
int main() 
{
	string line = "Hello user!";
	string str = "Input your name: ";
	string str1;
	std::cout << line << '\n' << str;
	std::cin >> str1;
	string str2 = "Hello ";
	str2.append(str1);
	std::cout << str2 << std::endl;
	std::cout << "Input string: ";
	string str3;
	std::cin >> str3;
	char x;
	std::cout << "Input elemnt from your string: ";
	std::cin >> x;
	std::cout << "Index your element: " << str3.findIndex(x);
	str3+=str;
	std::cout << str3 << std::endl;
	str3 = str1;
	std::cout << str3 << std::endl;
	if(str2 > str1)
	{
		std::cout << "True" << std::endl;
	}
	if(str1!= str3)
	{
		std::cout << "True" << std::endl;
	}
	else
	{
		std::cout << "False" << std::endl;
	}
	str2 = str;
	if(str2 == str)
	{
		std::cout << "True" << std::endl;
	}
	return 0;
}