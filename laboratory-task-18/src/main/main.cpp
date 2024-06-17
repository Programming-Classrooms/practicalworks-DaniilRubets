#include "../Biblioteca/Library.hpp"


int main()
{
    try
    {
        std::string title = "Bob and Jhon";
        std::vector<std::string> authors;
        std::string firstAuthor = "Bogaschev";
        std::string secondAuthor = "Shevtsov";
        authors.push_back(firstAuthor);
        authors.push_back(secondAuthor);
        double price = 23.45;
        int count = 112;

        Book a(title, authors, price, count); 


        std::string titleSecond = "Tractors";
        std::vector<std::string> authorsSecond;
        std::string firstAuthorSecond = "Rubets";
        std::string secondAuthorSecond = "Kobzov";
        authorsSecond.push_back(firstAuthorSecond);
        authorsSecond.push_back(secondAuthorSecond);
        double priceSecond = 114.45;
        int countSecond = 1000;

        Book b(titleSecond, authorsSecond, priceSecond, countSecond);

        std::vector<Book> Books;
        Library biblioteca;
        biblioteca.addBook(b);
        biblioteca.addBook(a);
        biblioteca.viewAllBooks();
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