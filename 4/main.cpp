#include <fstream>
#include <iostream>
#include <string>
#include <regex>

std::ifstream input;
std::string buf;

struct CleanAssignment{
    int start;
    int end;

    bool overlap(CleanAssignment other){
        return (( (start <= other.start) && (end >= other.end) ) || ((start >= other.start) && (end <= other.end)));
    }
};

int main(int argc, char** argv){
    std::regex pattern("([0-9]+)-([0-9]+),([0-9]+)-([0-9]+)", std::regex::optimize);
    (void)argc; // Unused
    (void)argv; // Unused
    int numOverlaps {0};
    input.open("input");
    input >> buf;
    while(!input.eof()){
        std::smatch values;
        std::regex_match(buf, values, pattern);
        // std::cout << "Number of matches: " <<  values.size();
        CleanAssignment assign1 {stoi(values[1].str()), stoi(values[2].str())};
        CleanAssignment assign2 {stoi(values[3].str()), stoi(values[4].str())};
        // std::cout << "Overlap: " << std::boolalpha << assign1.overlap(assign2) << '\n';
        if (assign1.overlap(assign2)){++numOverlaps;}
        // printf("\t %d %d %d %d\n", stoi(values[1].str()), stoi(values[2].str()), stoi(values[3].str()), stoi(values[4].str()));
        input >> buf;
    }
    std::cout << "Number of overlaps: " << numOverlaps << '\n';
}

