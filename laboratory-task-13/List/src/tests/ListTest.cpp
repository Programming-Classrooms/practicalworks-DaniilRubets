#include "../List/List.hpp" 
#include <gtest/gtest.h>

TEST(LinkedListTest, ConstructorTest) {
    LinkedList<int> list;
    EXPECT_EQ(list.search(0), -1);
}

TEST(LinkedListTest, InsertAtBeginningTest) {
    LinkedList<int> list;
    list.insertAtBeginning(5);
    EXPECT_EQ(list.search(5), 0);
}

TEST(LinkedListTest, InsertAtEndTest) {
    LinkedList<int> list;
    list.insertAtEnd(5);
    EXPECT_EQ(list.search(5), 0);
}

TEST(LinkedListTest, DeleteFirstTest) {
    LinkedList<int> list;
    list.insertAtBeginning(5);
    list.deleteFirst();
    EXPECT_EQ(list.search(5), -1);
}

TEST(LinkedListTest, DeleteLastTest) {
    LinkedList<int> list;
    list.insertAtEnd(5);
    list.deleteLast();
    EXPECT_EQ(list.search(5), -1);
}

TEST(LinkedListTest, DeleteByValueTest) {
    LinkedList<int> list;
    list.insertAtEnd(5);
    list.deleteByValue(5);
    EXPECT_EQ(list.search(5), -1);
}
