//
// Created by jwobser on 12/22/22.
//

#include <gtest/gtest.h>
#include "../ingest.hpp"
#include "../checkvisible.hpp"

const int hght{5};
const int wdth{5};

class ExampleTest : public ::testing::Test{
public:
    static unsigned short arr[hght][wdth];
    static void SetUpTestSuite(){
        ingest("example", arr[0], hght, wdth);
    }
};

unsigned short ExampleTest::arr[hght][wdth];

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

/*
TEST_F(ExampleTest, CheckTreeAllDirections){
    ASSERT_EQ(ExampleTest::arr[0][0], 3);
    ASSERT_TRUE(checktree({0,0}, ExampleTest::arr[0], 5,5));
}
 */

TEST_F(ExampleTest, CheckTreeAllDirections){
    EXPECT_EQ(checktree({3,2}, ExampleTest::arr[0], 5,5), 8);
}


TEST_F(ExampleTest, CheckTreeNorth){
    Tree t1{1, 2};
    Tree t2{3, 2};
    EXPECT_EQ(checkdir(t1, 'N', ExampleTest::arr[0], 5, 5), 1);
    EXPECT_EQ(checkdir(t2, 'N', ExampleTest::arr[0], 5, 5), 2);
}

TEST_F(ExampleTest, CheckTreeEast){
    Tree t1{1, 2};
    Tree t2{3, 2};
    EXPECT_EQ(checkdir(t1, 'E', ExampleTest::arr[0], 5, 5), 2);
    EXPECT_EQ(checkdir(t2, 'E', ExampleTest::arr[0], 5, 5), 2);
}

TEST_F(ExampleTest, CheckTreeSouth){
    Tree t1{1, 2};
    Tree t2{3, 2};
    EXPECT_EQ(checkdir(t1, 'S', ExampleTest::arr[0], 5, 5), 2);
    EXPECT_EQ(checkdir(t2, 'S', ExampleTest::arr[0], 5, 5), 1);
}

TEST_F(ExampleTest, CheckTreeWest){
    Tree t1{1, 2};
    Tree t2{3, 2};
    EXPECT_EQ(checkdir(t1, 'W', ExampleTest::arr[0], 5, 5), 1);
    EXPECT_EQ(checkdir(t2, 'W', ExampleTest::arr[0], 5, 5), 2);
}
