#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <string>
enum class TreeType
{
	coniferous,
	deciduous
};
class Tree
{
protected:
	std::string name;
	int age;
	TreeType type;
public:
	/*======== Конструкторы ========*/
	Tree();
	Tree(std::string&, int, TreeType&);
	Tree(const Tree&);

	/*======== Деструктор ========*/
	~Tree();

	/*======== Геттеры ========*/
	std::string getName();
	int getAge();
	TreeType getType();

	/*======== Сеттеры ========*/
	void setName(std::string&);
	void setAge(int);
	void setType(TreeType&);

	/*======== Вывод ========*/
	virtual void printInfo() = 0;
};
#endif
