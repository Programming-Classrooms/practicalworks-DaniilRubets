#include <gtest/gtest.h>
#include "../Fraction/Fraction.hpp"
#include <stdexcept>

TEST(FractionTest, DefaultConstructor) {
    Fraction f;
    EXPECT_EQ(0, f.getN());
    EXPECT_EQ(1, f.getD());
}

TEST(FractionTest, ParameterizedConstructor1) {
    Fraction f(5);
    EXPECT_EQ(5, f.getN());
    EXPECT_EQ(1, f.getD());
}

TEST(FractionTest, ParameterizedConstructor2) {
    Fraction f(5, 2);
    EXPECT_EQ(5, f.getN());
    EXPECT_EQ(2, f.getD());
}

TEST(FractionTest, CopyConstructor) {
    Fraction f1(3, 4);
    Fraction f2(f1);
    EXPECT_EQ(3, f2.getN());
    EXPECT_EQ(4, f2.getD());
}

TEST(FractionTest, GettersAndSetters) {
    Fraction f;
    f.setN(7);
    f.setD(8);
    EXPECT_EQ(7, f.getN());
    EXPECT_EQ(8, f.getD());
}

TEST(FractionTest, Reduce) {
    Fraction f(6, 8);
    f.reduce();
    EXPECT_EQ(3, f.getN());
    EXPECT_EQ(4, f.getD());
}

TEST(FractionTest, AdditionOperator) {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction result = f1 + f2;
    EXPECT_EQ(5, result.getN());
    EXPECT_EQ(6, result.getD());
}

TEST(FractionTest, SubtractionOperator) {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction result = f1 - f2;
    EXPECT_EQ(1, result.getN());
    EXPECT_EQ(6, result.getD());
}

TEST(FractionTest, MultiplicationOperator) {
    Fraction f1(1, 2);
    Fraction f2(2, 3);
    Fraction result = f1 * f2;
    EXPECT_EQ(1, result.getN());
    EXPECT_EQ(3, result.getD());
}

TEST(FractionTest, DivisionOperator) {
    Fraction f1(1, 2);
    Fraction f2(2, 3);
    Fraction result = f1 / f2;
    EXPECT_EQ(3, result.getN());
    EXPECT_EQ(4, result.getD());
}

TEST(FractionTest, DivisionByZero) {
    Fraction f1(1, 2);
    Fraction f2(0, 1);
    EXPECT_THROW(f1 / f2, std::invalid_argument);
}


TEST(FractionTest, EqualityOperator) {
    Fraction f1(2, 3);
    Fraction f2(4, 6);
    EXPECT_TRUE(f1 == f2);
}

TEST(FractionTest, LessThanOperator) {
    Fraction f1(1, 2);
    Fraction f2(2, 3);
    EXPECT_TRUE(f1 < f2);
}

TEST(FractionTest, GreaterThanOperator) {
    Fraction f1(2, 3);
    Fraction f2(1, 2);
    EXPECT_TRUE(f1 > f2);
}

TEST(FractionTest, IncrementOperator) {
    Fraction f(1, 2);
    ++f;
    EXPECT_EQ(3, f.getN());
    EXPECT_EQ(2, f.getD());
}

TEST(FractionTest, DecrementOperator) {
    Fraction f(3, 2);
    --f;
    EXPECT_EQ(1, f.getN());
    EXPECT_EQ(2, f.getD());
}

TEST(FractionTest, UnaryMinusOperator) {
    Fraction f(1, 2);
    f = -f;
    EXPECT_EQ(-1, f.getN());
    EXPECT_EQ(2, f.getD());
}

TEST(FractionTest, NotOperator) {
    Fraction f(2, 3);
    Fraction result = !f;
    EXPECT_EQ(3, result.getN());
    EXPECT_EQ(2, result.getD());
}

TEST(FractionTest, AssignmentOperator) {
    Fraction f1(1, 2);
    Fraction f2 = f1;
    EXPECT_EQ(1, f2.getN());
    EXPECT_EQ(2, f2.getD());
}

TEST(FractionTest, PlusEqualsOperator) {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    f1 += f2;
    EXPECT_EQ(5, f1.getN());
    EXPECT_EQ(6, f1.getD());
}

TEST(FractionTest, MinusEqualsOperator) {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    f1 -= f2;
    EXPECT_EQ(1, f1.getN());
    EXPECT_EQ(6, f1.getD());
}

TEST(FractionTest, TimesEqualsOperator) {
    Fraction f1(1, 2);
    Fraction f2(2, 3);
    f1 *= f2;
    EXPECT_EQ(1, f1.getN());
    EXPECT_EQ(3, f1.getD());
}

TEST(FractionTest, DivideEqualsOperator) {
    Fraction f1(1, 2);
    Fraction f2(2, 3);
    f1 /= f2;
    EXPECT_EQ(3, f1.getN());
    EXPECT_EQ(4, f1.getD());
}

TEST(FractionTest, DivideByZero) {
    Fraction f1(1, 2);
    Fraction f2(0, 1);
    EXPECT_THROW(f1 /= f2, std::exception);
}