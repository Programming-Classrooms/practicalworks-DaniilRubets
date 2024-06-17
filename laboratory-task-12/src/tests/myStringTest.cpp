#include "../myString/mySTRING.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(StringTest, DefaultConstructor) {
    string s;
    EXPECT_EQ(s.getSize(), 0);
    EXPECT_TRUE(s.isEmpty());
}

TEST(StringTest, ParametrizedConstructor) {
    string s("Hello");
    EXPECT_EQ(s.getSize(), 5);
    EXPECT_STREQ(s.getStr(), "Hello");
}

TEST(StringTest, CopyConstructor) {
    string s1("Hello");
    string s2(s1);
    EXPECT_EQ(s2.getSize(), 5);
    EXPECT_STREQ(s2.getStr(), "Hello");
}

TEST(StringTest, MoveConstructor) {
    string s1("Hello");
    string s2(std::move(s1));
    EXPECT_EQ(s2.getSize(), 5);
    EXPECT_STREQ(s2.getStr(), "Hello");
    EXPECT_EQ(s1.getSize(), 0);
    EXPECT_TRUE(s1.isEmpty());
}

TEST(StringTest, Append) {
    string s1("Hello");
    string s2(" World");
    s1.append(s2);
    EXPECT_EQ(s1.getSize(), 11);
    EXPECT_STREQ(s1.getStr(), "Hello World");
}

TEST(StringTest, PlusEqualsOperator) {
    string s1("Hello");
    string s2(" World");
    s1 += s2;
    EXPECT_EQ(s1.getSize(), 11);
    EXPECT_STREQ(s1.getStr(), "Hello World");
}

TEST(StringTest, EqualityOperator) {
    string s1("Hello");
    string s2("Hello");
    string s3("World");
    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 == s3);
}

TEST(StringTest, InequalityOperator) {
    string s1("Hello");
    string s2("Hello");
    string s3("World");
    EXPECT_FALSE(s1 != s2);
    EXPECT_TRUE(s1 != s3);
}

TEST(StringTest, LessThanOperator) {
    string s1("Apple");
    string s2("Banana");
    EXPECT_TRUE(s1 < s2);
    EXPECT_FALSE(s2 < s1);
}

TEST(StringTest, GreaterThanOperator) {
    string s1("Banana");
    string s2("Apple");
    EXPECT_TRUE(s1 > s2);
    EXPECT_FALSE(s2 > s1);
}

TEST(StringTest, Length) {
    string s("Hello");
    EXPECT_EQ(s.length(), 5);
}

TEST(StringTest, FindIndex) {
    string s("Hello");
    EXPECT_EQ(s.findIndex('e'), 1);
    EXPECT_EQ(s.findIndex('z'), -1);
}
