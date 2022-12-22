//
// Created by jwobser on 12/22/22.
//

#include <gtest/gtest.h>
#include "../ingest.hpp"

const int hght{5};
const int wdth{5};

TEST(INGEST, ReadSampleArray){
    unsigned short arr[hght][wdth];
    ingest("example", arr[0], hght, wdth);
    ASSERT_EQ(arr[0][0], 3);
    ASSERT_EQ(arr[4][4], 0);
    ASSERT_EQ(arr[0][4], 3);
    ASSERT_EQ(arr[4][0], 3);
    ASSERT_EQ(arr[2][2], 3);
    ASSERT_EQ(arr[1][1], 5);
}
