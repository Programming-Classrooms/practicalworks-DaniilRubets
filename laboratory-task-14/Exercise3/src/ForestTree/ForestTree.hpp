#ifndef FORESTTREE_HPP
#define FORESTTREE_HPP
#include "../Tree/Tree.hpp"
class ForestTree :Tree
{
private:
	int woodAmount;
public:
	/*======== Конструкторы ========*/
	ForestTree();
	ForestTree(std::string&, int, TreeType&, int);
	ForestTree(const ForestTree&);

	/*======== Деструктор ========*/
	~ForestTree();

	/*======== Геттер ========*/
	int getWoodAmount();

	/*======== Сеттер ========*/
	void setWoodAmount(int);

	/*======== Вывод ========*/
	void printInfo() override;
};

#endif
