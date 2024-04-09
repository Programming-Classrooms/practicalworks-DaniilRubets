#define _CRT_SECURE_NO_WARNINGS
#include "mySTRING.hpp"


string::string(): str(nullptr),size(0)
{}


string::string(const char* ptr) {
	size = strlen(ptr);
	str = new char[size + 1];
	strcpy(str, ptr);
}


string::string(const string& rhs) {
	size = rhs.size;
	str = new char[size + 1];
	strcpy(str, rhs.str);
}


string::string(string&& rhs) noexcept {
	str = rhs.str;
	size = rhs.size;
	rhs.str = nullptr;
	rhs.size = 0;
}

string::~string() {
	size = 0;
	delete[]str;
}


std::istream& operator>>(std::istream& is, string& s) {
	char temp[1000];
	is >> temp;
	delete[] s.str;
	s.size = strlen(temp);
	s.str = new char[s.size + 1];
	strcpy(s.str, temp);
	return is;
}


std::ostream& operator << (std::ostream& os, const string& st) {
	os << st.str;
	return os;
}


bool string::isEmpty() {
	return str == nullptr || str[0] == '\0';
}


uint32_t string::getSize() const
{
	return this->size;
}


char* string::getStr() const {
	return this->str;
}


void string::setSize(uint32_t x)
{
	this->size = x;
}


void string::setStr(const char* line)
{
	delete[]this->str;
	this->str = new char[strlen(line)];
	strcpy(this->str,line);
}


void string::append(const string& other) {
	char* newStr = new char[size + other.size + 1];
	strcpy(newStr, str);
	strcat(newStr, other.str);
	delete[] str;
	str = newStr;
	size += other.size;
}


string& string::operator=(const string& rhs)
{
	if (this != &rhs) {
		delete[] str;
		size = rhs.size;
		str = new char[size + 1];
		strcpy(str, rhs.str);
	
	return *this;
}


}
string& string::operator += (const string& t)
{
	size_t newSize = size + t.size;
	char* newStr = new char[newSize + 1];
	strcpy(newStr, str);
	strcat(newStr, t.str);
	delete[] str;
	str = newStr;
	size = newSize;
	return *this;
}


bool string::operator == (const string& t) {
	return !strcmp(str, t.str);
}


bool string::operator != (const string& t) {
	return !(operator == (t));
}


bool string::operator<(const string& rhs) {
	return strcmp(str, rhs.str) < 0;
}


bool string::operator >(const string& rhs) {
	return strcmp(str, rhs.str) > 0;
}


size_t string::length() {
	return size;
}


int64_t string::findIndex(const char ch)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (str[i] == ch)
		{
			return i;
		}
	}
	return -1;
}