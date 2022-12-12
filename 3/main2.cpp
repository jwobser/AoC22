#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <string_view>
#include "main.hpp"

std::ifstream input;
std::string buf;

int main(int argc, char** argv){
    (void)argc; // Unused
    (void)argv; // Unused
    input.open("input");
    input >> buf;
    int score{0};
    while(!input.eof()){
        try {
            check_len(buf);
        }
        catch(const std::invalid_argument& e){
            std::cout << e.what();
            return 1;
        }
        auto dupes = find_duplicates(buf);
        std::for_each(dupes.begin(), dupes.end(), [&](const char c){score+= score_priority(c);});
        input >> buf;
    }
    std::cout << "Score: " << score << '\n';
    return 0;
}



