#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <cmath>
#include <vector>
#include "helpers.h"
#include "combine.h"
#include <numeric>

std::ifstream input;
std::string buf;

extern const int TARGET_ROW{2'000'000};

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
    std::vector<Sensor> sensors;
    read_input("input", sensors);

    std::vector<ExclusionSpan> spans;
    for(const auto& sensor : sensors) {
        std::cout << sensor.get_span_at_target(TARGET_ROW) << '\n';
        if (sensor.width_at_target_row(TARGET_ROW) > 0) {
            spans.push_back(sensor.get_span_at_target(TARGET_ROW));
        }
    }
    std::cout << " ---------- SORT ----------\n";
    std::sort(spans.begin(), spans.end(), std::less<ExclusionSpan>());

    for (const auto& span : spans){
        std::cout << span << '\n';
    }

    auto combined_spans = combine_exclusions(spans);
     std::cout << " ------------ Combined Spans ------------\n";
    for (const auto& span : combined_spans){
        std::cout << span << '\n';
    }
    // std::cout << std::reduce(combined_spans.begin(), combined_spans.end(), 0, [](int lhs, ExclusionSpan& rhs){return rhs.width() + lhs;}) << "\n";
}