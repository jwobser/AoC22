//
// Created by James Wobser on 12/16/2022.
//

#include <gtest/gtest.h>
#include "../helpers.h"
#include "../combine.h"

class SensorTest : public ::testing::Test{
protected:
    Sensor s{8,9,{10,11}};
};

TEST_F(SensorTest, Manhattan_Distance){
    EXPECT_EQ(s.manhattan_dist(), 4);
}

TEST_F(SensorTest, Span_width){
    EXPECT_EQ(s.width_at_target_row(9), 9);
    EXPECT_EQ(s.width_at_target_row(10), 7);
    EXPECT_EQ(s.width_at_target_row(13), 1);
    EXPECT_EQ(s.width_at_target_row(5), 1);
    EXPECT_EQ(s.width_at_target_row(4), 0);
    EXPECT_EQ(s.width_at_target_row(3), 0);
    EXPECT_EQ(s.width_at_target_row(14), 0);
}

TEST_F(SensorTest, GetSpan) {
    auto span = s.get_span_at_target(9);
    EXPECT_EQ(span.start, 3);
    EXPECT_EQ(span.end, 13);

    span = s.get_span_at_target(8);
    EXPECT_EQ(span.start, 4);
    EXPECT_EQ(span.end, 12);

    span = s.get_span_at_target(1);
    EXPECT_EQ(span.start, 0);
    EXPECT_EQ(span.end, 0);

    span = s.get_span_at_target(50);
    EXPECT_EQ(span.start, 0);
    EXPECT_EQ(span.end, 0);
}

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
