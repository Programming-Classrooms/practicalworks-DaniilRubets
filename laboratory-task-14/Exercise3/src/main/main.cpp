#include "../Tree/Tree.hpp"
#include "../ForestTree/ForestTree.hpp"
#include "../FruitTree/FruitTree.hpp"
#include "../TreeConteiner/TreeConteiner.hpp"


int main() 
{
	try
	{
		ForestTree a();
		FruitTree b();
	}
	
	catch(std::runtime_error r)
	{
		std::cerr << r.what();
	}

	catch(std::logic_error l)
	{
		std::cerr << l.what();
	}

	catch(std::invalid_argument in)
	{
		std::cerr << in.what();
	}

	return 0;
}
