#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <cmath>
#include <vector>
#include "helpers.h"
#include "combine.h"
// #include <format>
#include <numeric>

std::ifstream input;
std::string buf;

const int TARGET_ROW{2'000'000};


namespace std {
    template<>
    struct less<ExclusionSpan> {
        bool operator()(const ExclusionSpan &lhs, const ExclusionSpan &rhs) const {
            if(lhs.start < rhs.start){return true;}
            if(lhs.start == rhs.start){return lhs.end < rhs.end;}
            return false;
        }
    };
}

int main(int argc, char** argv){
    std::regex pattern("Sensor at x=(-?[0-9]+), y=(-?[0-9]+).*beacon.*x=(-?[0-9]+), y=(-?[0-9]+)", std::regex::optimize);
//    std::cout << "Compiled regex\n";
    (void)argc; // Unused
    (void)argv; // Unused
    input.open("input");
    if(!input){
        throw std::runtime_error("Failed to open input");
    }
//    std::cout << "Opened input\n";
    // static_assert(input, "Input failed to open");
    std::getline(input, buf);
    std::vector<Sensor> sensors;
//    std::cout << "Constructed vector of sensors\n";
    while(!input.eof()){
        std::smatch values;
//        std::cout << buf;
        std::regex_match(buf, values, pattern);
//        std::cout << "Found " << values.size() - 1 << " matches\n";
        const int sx = stoi(values[1]);
        const int sy = stoi(values[2]);
        const int bx = stoi(values[3]);
        const int by = stoi(values[4]);
        sensors.emplace_back(Sensor{sx, sy, Beacon{bx, by}});
        std::cout << sensors.back();
        std::cout << "man dist: " << sensors.back().manhattan_dist() << '\n';
        std::cout << "min y reach: " << sensors.back().y - sensors.back().manhattan_dist() << "\n";
        std::cout << "max y reach: " << sensors.back().y + sensors.back().manhattan_dist() << "\n";
        std::cout << sensors.back().get_span_at_target(TARGET_ROW) << "\n\n";


        std::getline(input, buf);
    }


    std::vector<ExclusionSpan> spans;
    for(const auto& sensor : sensors) {
        std::cout << sensor.get_span_at_target(TARGET_ROW) << '\n';
        if (sensor.width_at_target_row(TARGET_ROW) > 0) {
            spans.push_back(sensor.get_span_at_target(TARGET_ROW));
        }
    }
    std::cout << " ---------- SORT ----------\n";
    std::sort(spans.begin(), spans.end(), std::less<ExclusionSpan>());
    /*
    auto spansort = [](ExclusionSpan lhs, ExclusionSpan rhs)->bool{return lhs.start < rhs.start;};
    std::sort(spans.begin(), spans.end(), spansort);

     */
    for (const auto& span : spans){
        std::cout << span << '\n';
    }

    auto combined_spans = combine_exclusions(spans);
     std::cout << " ------------ Combined Spans ------------\n";
    for (const auto& span : combined_spans){
        std::cout << span << '\n';
    }
    std::cout << std::reduce(combined_spans.begin(), combined_spans.end(), 0, [](int lhs, ExclusionSpan& rhs){return rhs.width() + lhs;}) << "\n";
}