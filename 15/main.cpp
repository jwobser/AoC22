#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <cmath>
#include "helpers.h"
#include <vector>
#include <format>

std::ifstream input;
std::string buf;

const int TARGET_ROW{2'000'000};


std::vector<ExclusionSpan> combine_exclusions(std::vector<ExclusionSpan>);

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
        // std::cout << sensors.back() << "\n";


        std::getline(input, buf);
    }

    std::vector<ExclusionSpan> spans;
    for(const auto& sensor : sensors){
        spans.push_back(sensor.get_span_at_target(TARGET_ROW));
    }

    for (const auto& span : spans){
        // std::cout << span << '\n';
    }

    auto combined_spans = combine_exclusions(spans);
    for (const auto& span : combined_spans){
        std::cout << span << '\n';
    }
}


std::vector<ExclusionSpan> combine_exclusions(std::vector<ExclusionSpan> input){
    std::vector<ExclusionSpan> combined;
    combined.push_back(input[0]);
    for(auto span : input){
        // Check if there are any overlaps.
        // FIXME Never executes because combined is empty
        for(auto& cspan : combined){
            // no overlap
            if((span.end < cspan.start) || (span.start > cspan.end)){
                combined.push_back(span);
                continue;
            }
            // complete overlap
            if((cspan.start <= span.start) && (cspan.end >= span.end)){
                continue;
            }
            // partial overlaps
            // Target span expands combined span to left
            if((span.start < cspan.start) && (span.end >= cspan.start) && (span.end <= cspan.end)){
               cspan.start = span.start;
            }
            // Target span expands combined span to the right
            if((span.end > cspan.end) && (span.start >= cspan.start) && (span.start <= cspan.end)){
                cspan.end = span.end;
            }
        }

        // Finally, recheck all ranges for any overlap

    }
    return combined;
}