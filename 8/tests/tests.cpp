//
// Created by jwobser on 12/22/22.
//

#include <gtest/gtest.h>
#include "../matrix.hpp"

TEST(MATRIX, GetRowEnd){
    Matrix<short> m{(short*) 1000, 99, 99};
    EXPECT_EQ(reinterpret_cast<size_t>(m.rowend(0)), 1000 + (99 - 1) * sizeof(short));
}

TEST(MATRIX, GetStart){
    Matrix<short> m{(short*) 0x1000, 99, 99};
    EXPECT_EQ(reinterpret_cast<size_t>(m.ptr), 0x1000);
}
