#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include "main.hpp"
#include <array>

std::ifstream input;
std::string buf;

int main(int argc, char** argv){
    (void)argc; // Unused
    (void)argv; // Unused
    input.open("input");
    int score{0};
    while(!input.eof()){
        std::array<std::string, 3> lines;
        for(int i{0}; i < 3; ++i){
            input >> buf;
            lines[i] = buf;
        }
        // left, middle, right, common
        std::array<std::set<char>, 4> charsets;
        for(int i{0}; i < 3; ++i){
            for(auto c : lines[i]){
                charsets[i].insert(c);
            }
        }
        for(auto c : charsets[0]){
            if( charsets[1].count(c) > 0 &&
                charsets[2].count(c) > 0
              ){ charsets[3].insert(c);}
        }

        for(auto c : charsets[3]){
            score += score_priority(c);
        }
    }
    std::cout << "Score: " << score << '\n';
    return 0;
}