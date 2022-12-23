//
// Created by jwobser on 12/22/22.
//

#include <gtest/gtest.h>
#include "../ingest.hpp"
#include "../checkvisible.hpp"

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

TEST(VISBILITY, CheckVisibleTree){
    unsigned short arr[hght][wdth];
    ingest("example", arr[0], hght, wdth);
    ASSERT_TRUE(checktree({0,0}, arr[0], 5,5));
}

TEST(VISBILITY, CheckNonVisibleTree){
    unsigned short arr[hght][wdth];
    ingest("example", arr[0], hght, wdth);
    ASSERT_FALSE(checktree({2,2}, arr[0], 5,5));
}


TEST(VISBILITY, CountVisible){
    unsigned short arr[hght][wdth];
    ingest("example", arr[0], hght, wdth);
    int count{0};
    for(int i{0}; i < hght; i++){
        for(int j{0}; j < hght; j++){
            if(checktree({i,j}, arr[0], hght, wdth)){
                count++;
            }
        }
    }
    ASSERT_EQ(count, 21);
}
