#include "../functions/functions.hpp"

int main()
{
    try {
        std::ifstream fin("src/resourse/data.txt");
        checkFile(fin);
        std::map<std::string, size_t> allWords;
        readWords(fin, allWords);
        printInformation(allWords);
    }
    
    catch(std::logic_error l)
    {
        std::cerr << l.what();
    }

    catch(std::runtime_error r)
    {
        std::cerr << r.what();
    }

    catch(std::invalid_argument in)
    {
        std::cerr << in.what();
    }
    
    return 0;
}