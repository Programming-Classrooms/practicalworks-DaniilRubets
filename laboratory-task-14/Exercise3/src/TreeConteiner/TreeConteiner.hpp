#ifndef TREECONTEINER_HPP
#define TREECONTEINER_HPP
#include <vector>
#include <algorithm>
#include "../Tree/Tree.hpp"
#include "../FruitTree/FruitTree.hpp"
#include "../ForestTree/ForestTree.hpp"
class TreeConteiner
{
private:
	std::vector<Tree*> trees;
public:
	/*======== Конструкторы ========*/
	TreeConteiner();
	TreeConteiner(std::vector<Tree*>&);
	TreeConteiner(const TreeConteiner&);

	/*======== Деструктор ========*/
	~TreeConteiner();

	/*======== Методы ========*/
    void addTree(Tree*);
    void printTreesInfo();
    int countTreeType(TreeType&);
	void sortTrees(Tree*, Tree*);
};

#endif
