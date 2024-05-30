#include "../Library/Library.hpp"


void checkFile(std::ifstream& file)
{
    if (!file.good()) {
        throw std::runtime_error("File does not exist!");
    }
    if (!file) {
        throw std::runtime_error("File is not opened!");
    }
    if (file.peek() == EOF) {
        throw std::runtime_error("File is empty!");
    }
}

int main()
{
    try {
        std::ifstream file("src/resourse/books.txt");
        checkFile(file);

        Library myLibrary;
        Book insertBook;
        while (file >> insertBook) {
            myLibrary.insertBook(insertBook);
            insertBook.clear();
            if (file.peek() == EOF) {
                break;
            }
        }
        std::cout << myLibrary;
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