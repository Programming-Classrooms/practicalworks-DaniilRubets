/*Каждая строка текстового файла "Students.txt" содержит информацию
об одном студенте в формате: ФИО курс группа. Файл большой, и заранее
неизвестно количество информации, содержащейся в нем.
Необходимо получить два новых текстовых файла:
o первый “Fio.txt” должен содержать все данные о студентах,
упорядоченные по фамилиям по алфавиту.
o второй “Groups.txt” - данные, упорядоченные по курсам,
для одинакового курса по группам, для одинаковой группы
по алфавиту.
В файле “Students.txt” данные не должны быть упорядочены, они
должны быть перемешаны. Файл “Students.txt” должен содержать сведения
о трёх курсах, на каждом курсе по две группы и в каждой группе по четыре
студента.*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

struct Student {
    std::string secondName;
    std::string name;
    std::string thirdName;
    int course;
    std::string group;
};


void checkFile(std::ifstream& file)
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


bool compareByName(const Student& a, const Student& b) {
    return a.name < b.name;
}

bool compareByCourseAndGroup(const Student& a, const Student& b) {
    if (a.course != b.course)
        return a.course < b.course;
    if (a.group != b.group)
        return a.group < b.group;
    return a.name < b.name;
}

int main() 
{
    try
    {
        std::ifstream fileIn("src/resourse/Students.txt");
        checkFile(fileIn);
        std::ofstream fileOutFio("src/resourse/Fio.txt");
        std::ofstream fileOutputGroup("src/resourse/Groups.txt");

        std::vector<Student> students;
        Student temp;

        while (fileIn >> temp.secondName >> temp.name >> temp.thirdName >> temp.course >> temp.group) {
            students.push_back(temp);
        }

        std::sort(students.begin(), students.end(), compareByName);
        for (const auto& student : students) {
            fileOutFio << student.secondName << " " << student.name << " " << student.thirdName << " " <<
            student.course << " " << student.group << std::endl;
        }

        std::sort(students.begin(), students.end(), compareByCourseAndGroup);
        for (const auto& student : students) {
            fileOutputGroup << student.secondName << " " << student.name << " " << student.thirdName << " " 
            << student.course << " " << student.group << std::endl;
        }
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
