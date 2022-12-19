//
// Created by James Wobser on 12/16/2022.
//
#include "helpers.h"
// #include <format>
#include <cmath>
#include <iostream>
#include <regex>
#include <string>

extern const int TARGET_ROW;

int Sensor::manhattan_dist(void) const {
    return mandist;
}

int Sensor::width_at_target_row(int target_row) const {
    const int dist = abs(target_row - y);
    if (dist > mandist){
        return 0;
    }
    return 1 + 2*(mandist - dist);
}

ExclusionSpan Sensor::get_span_at_target(int target_row) const {
    const int width = width_at_target_row(target_row);
    if(width == 0){
        return {0,0};
    }
    const int start = x - (width - 1) / 2 ;
    const int end = x + (width - 1)  / 2 ;
    return ExclusionSpan {start, end};
}

std::ostream& operator<<(std::ostream &os, const Sensor &s) {
    os << s.x << ", " << s.y << " :: " << s.nearest_beacon.x << ", " << s.nearest_beacon.y << '\n';
    // os << std::format("{}, {} :: {}, {}", s.x, s.y, s.nearest_beacon.x, s.nearest_beacon.y);
    return os;
}

Sensor::Sensor(int x, int y, const Beacon &nearestBeacon)
    : x(x), y(y), nearest_beacon(nearestBeacon) {
    mandist = abs(nearestBeacon.x - x) + abs(nearestBeacon.y - y);
    const int dx = abs(nearestBeacon.x - x);
    const int dy = abs(nearestBeacon.y - y);
//    std::cout << "mandist: " << mandist << "\t\tdx: " << dx << "\tdy: " << dy << '\n';
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
    // os << std::format("[{} - {}]", s.start, s.end);
    os << "[" << s.start << ", " << s.end << "]";
    return os;
}



bool read_input(std::string f, std::vector<Sensor>& v){
    std::string buf;
    std::ifstream input;
    std::regex pattern("Sensor at x=(-?[0-9]+), y=(-?[0-9]+).*beacon.*x=(-?[0-9]+), y=(-?[0-9]+)", std::regex::optimize);

    input.open(f);

    std::getline(input, buf);
    while(!input.eof()){
        std::smatch values;
        std::regex_match(buf, values, pattern);
        const int sx = stoi(values[1]);
        const int sy = stoi(values[2]);
        const int bx = stoi(values[3]);
        const int by = stoi(values[4]);
        v.emplace_back(Sensor{sx, sy, Beacon{bx, by}});
        std::cout << v.back();
        std::cout << "man dist: " << v.back().manhattan_dist() << '\n';
        std::cout << "min y reach: " << v.back().y - v.back().manhattan_dist() << "\n";
        std::cout << "max y reach: " << v.back().y + v.back().manhattan_dist() << "\n";
        std::cout << v.back().get_span_at_target(TARGET_ROW) << "\n\n";


        std::getline(input, buf);
    }
    return true;
}