//
// Created by James Wobser on 12/16/2022.
//

#ifndef AOC22_HELPERS_H
#define AOC22_HELPERS_H
#include <fstream>

struct Beacon{
    int x;
    int y;
};

struct ExclusionSpan{
    int start;
    int end;
    bool overlap(ExclusionSpan) const;
    friend std::ostream& operator<<(std::ostream& os, const ExclusionSpan& s);
};

struct Sensor{
    int x, y;
    Beacon nearest_beacon;
    int manhattan_dist(void) const;
    int width_at_target_row(int target_row) const;
    ExclusionSpan get_span_at_target(int target_row) const;

    friend std::ostream& operator<<(std::ostream& os, const Sensor& s);
};

#endif //AOC22_HELPERS_H
