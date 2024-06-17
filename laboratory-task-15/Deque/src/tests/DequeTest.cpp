#include <gtest/gtest.h>
#include "../Deque/Deque.hpp"

TEST(TDequeTest, DefaultConstructor) 
{
    TDeque<int> deque;
    EXPECT_EQ(deque.size, 0);
}

TEST(TDequeTest, InsFront) 
{
    TDeque<int> deque;
    deque.InsFront(1);
    EXPECT_EQ(deque.GetByIndex(0), 1);
}

TEST(TDequeTest, InsRear) 
{
    TDeque<int> deque;
    deque.InsRear(1);
    EXPECT_EQ(deque.GetByIndex(0), 1);
}

TEST(TDequeTest, DelFront) 
{
    TDeque<int> deque;
    deque.InsFront(1);
    int info;
    deque.DelFront(info);
    EXPECT_EQ(info, 1);
    EXPECT_EQ(deque.size, 0);
}

TEST(TDequeTest, DelRear) 
{
    TDeque<int> deque;
    deque.InsRear(1);
    int info;
    deque.DelRear(info);
    EXPECT_EQ(info, 1);
    EXPECT_EQ(deque.size, 0);
}