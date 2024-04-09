#include "../myString/mySTRING.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(testConstructors, testDefaultConstructor)
{
    string testStr;
    EXPECT_EQ(testStr.getSize(), 0);
}

TEST(testConstructors, testParameterConstructor)
{
    EXPECT_THROW(string wrongStr(""), std::invalid_argument);
    MyString testStr("test");
    EXPECT_EQ(testStr.getSize(), 4);
}
