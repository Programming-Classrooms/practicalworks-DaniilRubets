#ifndef FRUITTREE_HPP
#define FRUITTREE_HPP
#include "../Tree/Tree.hpp"
class FruitTree :Tree 
{
private:
	double harvestWeight;
	int storageDuration;
public:
	/*======== Конструкторы ========*/
	FruitTree();
	FruitTree(std::string, int, TreeType&, double, int);
	FruitTree(const FruitTree&);

	/*======== Деструктор ========*/
	~FruitTree();

	/*======== Геттеры ========*/
	double getHarvestWeight();
	int getStorageDuration();

	/*======== Сеттеры ========*/
	void setHarvestWeight(double);
	void setStorageDuration(int);

	/*======== Вывод ========*/
	void printInfo() override;
};

#endif
