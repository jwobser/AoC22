//
// Created by James Wobser on 12/16/2022.
//

#ifndef AOC22_HELPERS_H
#define AOC22_HELPERS_H
#include <fstream>
#include <string>
#include <vector>


struct Beacon{
    int x;
    int y;
};

struct ExclusionSpan{
    int start;
    int end;
    bool overlap(ExclusionSpan) const;
    int width(void) const{ return end-start;}
    friend std::ostream& operator<<(std::ostream& os, const ExclusionSpan& s);
};

struct Sensor{
    int x, y;
    Beacon nearest_beacon;

    Sensor(int x, int y, const Beacon &nearestBeacon);

    int manhattan_dist(void) const;
    int width_at_target_row(int target_row) const;
    ExclusionSpan get_span_at_target(int target_row) const;

    friend std::ostream& operator<<(std::ostream& os, const Sensor& s);

private:
    int mandist;
};

bool read_input(std::string, std::vector<Sensor>&);

#endif //AOC22_HELPERS_H
