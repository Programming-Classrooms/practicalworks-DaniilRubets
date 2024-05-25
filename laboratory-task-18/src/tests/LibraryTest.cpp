#include "../Biblioteca/Library.hpp"
#include "../Book/Book.hpp"
#include "gtest/gtest.h"

TEST(LibraryTest, ConstructorTest) {
    Library library;
    EXPECT_EQ(library.getBooks().size(), 0);
}

TEST(LibraryTest, AddBookTest) {
    Library library;
    std::vector<std::string> testAuthors;
    testAuthors.push_back("Test Author");
    Book book("Test Book", testAuthors , 23.45, 10);
    library.addBook(book);
    EXPECT_EQ(library.getBooks().size(), 1);
}

TEST(LibraryTest, FindBookTest) {
    Library library;
    std::vector<std::string> testAuthors;
    testAuthors.push_back("Test Author");
    Book book("Test Book", testAuthors , 23.45, 10);
    library.addBook(book);
    std::string title = "Test Book";
    EXPECT_EQ(library.findBook(title).getTitle(), "Test Book");
}

TEST(LibraryTest, DeleteBookTest) {
    Library library;
    std::vector<std::string> testAuthors;
    testAuthors.push_back("Test Author");
    Book book("Test Book", testAuthors , 23.45, 10);
    library.addBook(book);
    std::string title = "Test Book";
    library.deleteBook(title);
    EXPECT_EQ(library.getBooks().size(), 0);
}

TEST(LibraryTest, SortByIBSNTest) {
    Library library;

    std::vector<std::string> testAuthors;
    testAuthors.push_back("Test Author");
    Book book("Test Book", testAuthors , 23.45, 10);
    
    std::vector<std::string> testAuthors1;
    testAuthors1.push_back("Test Author1");
    Book book1("Test Book1", testAuthors1 , 23.45, 10);

    library.addBook(book);
    library.addBook(book1);
    library.sortByIBSN();
    EXPECT_EQ(library.getBooks()[0].getIBSN(), "0000000000001");
    EXPECT_EQ(library.getBooks()[1].getIBSN(), "0000000000002");
}

TEST(LibraryTest, SortByAlphabetTest) {
    Library library;

    std::vector<std::string> testAuthors;
    testAuthors.push_back("Test Author");
    Book book("B Test Book", testAuthors , 23.45, 10);

    std::vector<std::string> testAuthors1;
    testAuthors.push_back("Test Author");
    Book book1("A Test Book", testAuthors1 , 23.45, 10);


    library.addBook(book);
    library.addBook(book1);
    library.sortByAlphapet();
    EXPECT_EQ(library.getBooks()[0].getTitle(), "A Test Book");
    EXPECT_EQ(library.getBooks()[1].getTitle(), "B Test Book");
}
