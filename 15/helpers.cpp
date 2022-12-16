//
// Created by James Wobser on 12/16/2022.
//
#include "helpers.h"
#include <format>
#include <cmath>

int Sensor::manhattan_dist(void) const {
    return abs((x - nearest_beacon.x)) + abs((y - nearest_beacon.y));
}

int Sensor::width_at_target_row(int target_row) const {
    const int dist = abs(target_row - y);
    const int mandist = this->manhattan_dist();
    if (dist > mandist){
        return 0;
    }
    return 1 + 2*(mandist - dist);
}

ExclusionSpan Sensor::get_span_at_target(int target_row) const {
    const int width = this->width_at_target_row(target_row);
    if(width == 0){
        return {0,0};
    }
    const int start = x - (width / 2) - 1;
    const int end = x + (width / 2) + 1;
    return ExclusionSpan {start, end};
}

std::ostream& operator<<(std::ostream &os, const Sensor &s) {
    os << std::format("{}, {} :: {}, {}", s.x, s.y, s.nearest_beacon.x, s.nearest_beacon.y);
    return os;
}

bool ExclusionSpan::overlap(ExclusionSpan other) const {
    if( ((start >= other.start) && (start <= other.end)) ||
        ((end >= other.start) && (end <= other.end)) ||
        ((other.start >= start) && (other.start <= end)) ||
        ((other.end >= start) && (other.end <= end))
      ){
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const ExclusionSpan &s) {
    os << std::format("[{} - {}]", s.start, s.end);
    return os;
}
