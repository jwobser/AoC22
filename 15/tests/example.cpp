//
// Created by James Wobser on 12/16/2022.
//

#include <gtest/gtest.h>
#include "../helpers.h"
#include "../combine.h"
#include <algorithm>


extern const int TARGET_ROW{10};

auto sensort = [](const ExclusionSpan &lhs, const ExclusionSpan &rhs) -> bool {
            if(lhs.start < rhs.start){return true;}
            if(lhs.start == rhs.start){return lhs.end < rhs.end;}
            return false;
        };


class ExampleTest : public ::testing::Test{
    protected:
    std::vector<Sensor> sensors;
    void SetUp() override{
        read_input("input", sensors);
    }
};

class SensorTest : public ::testing::Test{
protected:
    Sensor s{8,9,{10,11}};
    Sensor s2{20,30,{20,40}};
};

TEST_F(ExampleTest, ReadInputs){
    EXPECT_EQ(sensors.size(), 14);
}


TEST_F(ExampleTest, GenerateExclusions){
    ASSERT_EQ(sensors.size(), 14);
    std::vector<ExclusionSpan> spans;
    for(const auto& sens: sensors){
        spans.push_back(sens.get_span_at_target(TARGET_ROW));
    }

    std::sort(spans.begin(), spans.end(), sensort);
    /*
    for(const auto& span : spans){
        std::cout << span;
    }
    */

    auto combined = combine_exclusions(spans);
    for(const auto& span : combined){
        std::cout << span;
    }
    EXPECT_EQ(combined[0].width(), 26);

}


/*
TEST_F(SensorTest, Manhattan_Distance){
    EXPECT_EQ(s.manhattan_dist(), 4);
    EXPECT_EQ(s2.manhattan_dist(), 10);
}
*/

/*
TEST_F(SensorTest, Span_width){
    EXPECT_EQ(s.width_at_target_row(9), 9);
    EXPECT_EQ(s.width_at_target_row(10), 7);
    EXPECT_EQ(s.width_at_target_row(13), 1);
    EXPECT_EQ(s.width_at_target_row(5), 1);
    EXPECT_EQ(s.width_at_target_row(13), 1);
    EXPECT_EQ(s.width_at_target_row(4), 0);
    EXPECT_EQ(s.width_at_target_row(3), 0);
    EXPECT_EQ(s.width_at_target_row(14), 0);
    // -- s2 -- 
    EXPECT_EQ(s2.width_at_target_row(30), 21);
}
*/

/*
TEST_F(SensorTest, GetSpan) {
    auto span = s.get_span_at_target(9);
    EXPECT_EQ(span.start, 4);
    EXPECT_EQ(span.end, 12);

    span = s.get_span_at_target(8);
    EXPECT_EQ(span.start, 5);
    EXPECT_EQ(span.end, 11);


    span = s.get_span_at_target(7);
    EXPECT_EQ(span.start, 6);
    EXPECT_EQ(span.end, 10);

    span = s.get_span_at_target(5);
    EXPECT_EQ(span.start, 8);
    EXPECT_EQ(span.end, 8);

    span = s.get_span_at_target(3);
    EXPECT_EQ(span.start, 0);
    EXPECT_EQ(span.end, 0);

    span = s.get_span_at_target(1);
    EXPECT_EQ(span.start, 0);
    EXPECT_EQ(span.end, 0);

    span = s.get_span_at_target(50);
    EXPECT_EQ(span.start, 0);
    EXPECT_EQ(span.end, 0);

    span = s2.get_span_at_target(50);
    EXPECT_EQ(span.start, 0);
    EXPECT_EQ(span.end, 0);

    /*
    span = s2.get_span_at_target(30);
    EXPECT_EQ(span.start, 9);
    EXPECT_EQ(span.end, 31);
}

*/

/*
TEST(SpanCombination, AddOne){
    std::vector<ExclusionSpan> input = {{0,1}};
    auto combined = combine_exclusions(input);
    EXPECT_EQ(combined.size(), 1);
}

TEST(SpanCombination, AddTwo){
    std::vector<ExclusionSpan> input = {{0,1}, {2,3}};
    auto combined = combine_exclusions(input);
    EXPECT_EQ(combined.size(), 2);
}

TEST(SpanCombination, AddN){
    std::vector<ExclusionSpan> input = {{0,1}, {2,3}, {5,6}};
    auto combined = combine_exclusions(input);
    EXPECT_EQ(combined.size(), 3);
    input.push_back({7,8});
    combined = combine_exclusions(input);
    EXPECT_EQ(combined.size(), 4);
}

TEST(SpanCombination, ExpandLeft){
    std::vector<ExclusionSpan> input = {{2,3}, {1,3}};
    auto combined = combine_exclusions(input);
    ASSERT_EQ(combined.size(), 1);
    EXPECT_EQ(combined[0].start, 1);
    EXPECT_EQ(combined[0].end, 3);
}

TEST(SpanCombination, ExpandRight){
    std::vector<ExclusionSpan> input = {{2,3}, {2,5}};
    auto combined = combine_exclusions(input);
    ASSERT_EQ(combined.size(), 1);
    EXPECT_EQ(combined[0].start, 2);
    EXPECT_EQ(combined[0].end, 5);
}

TEST(SpanCombination, ReserveSpace){
    std::vector<ExclusionSpan> input = {{0,1}, {1,3}};
    auto combined = combine_exclusions(input);
    EXPECT_EQ(combined.capacity(), 2);
}

TEST(SpanCombination, Combo){
    std::vector<ExclusionSpan> input = {{1,1}, {1,2}, {3,3}, {4,7},{5,6}};
    // Expected output [1,2] [3,3] [4,7]
    auto combined = combine_exclusions(input);
    for(const auto& span : combined){
        std::cout << span << ' ';
    }
    std::cout << '\n';
    EXPECT_EQ(combined.size(), 3);
    EXPECT_EQ(combined[0].start, 1);
    EXPECT_EQ(combined[0].end, 2);
    EXPECT_EQ(combined[1].start, 3);
    EXPECT_EQ(combined[1].end, 3);
    EXPECT_EQ(combined[2].start, 4);
    EXPECT_EQ(combined[2].end, 7);
}

*/