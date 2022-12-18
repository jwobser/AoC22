#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <cmath>
#include <vector>
// #include <format>
#include "helpers.h"
#include "combine.h"

std::ifstream input;
std::string buf;

const int TARGET_ROW{2'000'000};

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

    /*
    for (const auto& span : spans){
        std::cout << span << '\n';
    }
     */

    auto combined_spans = combine_exclusions(spans);
    for (const auto& span : combined_spans){
        std::cout << span << '\n';
    }
}