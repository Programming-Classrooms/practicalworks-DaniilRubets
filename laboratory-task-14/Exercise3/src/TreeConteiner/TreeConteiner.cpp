#include "../TreeConteiner/TreeConteiner.hpp"


bool compare(Tree* a, Tree* b)
{
    if (a->getName() == b->getName()) 
    {
        return a->getAge() > b->getAge();
    }
        return a->getName() < b->getName();
}


TreeConteiner::TreeConteiner(): trees()
{}


TreeConteiner::TreeConteiner(std::vector<Tree*>& tree):trees(tree)
{}


TreeConteiner::TreeConteiner(const TreeConteiner& rhs):trees(rhs.trees)
{}


TreeConteiner::~TreeConteiner()
{
    trees.clear();
}


void TreeConteiner::addTree(Tree* tree)
{
	trees.push_back(tree);
}


void TreeConteiner::printTreesInfo()
{
    for (auto& tree : trees) 
    {
        tree->printInfo();
    }
    
}


int TreeConteiner::countTreeType(TreeType& type)
{
    int count = 0;
    for (auto& tree : trees)
    {
        if (tree->getType() == type)
        {
            count++;
        }
    }
    return count;
}


void TreeConteiner::sortTrees(Tree* a, Tree* b)
{
    std::sort(trees.begin(), trees.end(), compare);
}
