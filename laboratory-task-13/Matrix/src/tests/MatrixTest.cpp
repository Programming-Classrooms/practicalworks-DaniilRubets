#include "../Matrix/Matrix.hpp" 
#include <gtest/gtest.h>


TEST(MatrixTest, ConstructorTest) {
    Matrix m1;
    EXPECT_EQ(m1.getValue(0, 0), 0);

    Matrix m2(2, 2);
    EXPECT_EQ(m2.getValue(0, 0), 0);
    EXPECT_EQ(m2.getValue(1, 1), 0);
}

TEST(MatrixTest, SetValueTest) {
    Matrix m(2, 2);
    m.setValue(0, 0, 5.0);
    EXPECT_EQ(m.getValue(0, 0), 5.0);
}

TEST(MatrixTest, OperatorTest) {
    Matrix m1(2, 2);
    Matrix m2(2, 2);
    m1.setValue(0, 0, 1.0);
    m2.setValue(0, 0, 2.0);

    Matrix m3 = m1 + m2;
    EXPECT_EQ(m3.getValue(0, 0), 3.0);

    m3 = m1 - m2;
    EXPECT_EQ(m3.getValue(0, 0), -1.0);

    m3 = m1 * m2;
    EXPECT_EQ(m3.getValue(0, 0), 2.0);

    m3 = m1 / 2.0;
    EXPECT_EQ(m3.getValue(0, 0), 0.5);
}
