#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <format>
#include <string_view>
#include "main.hpp"

std::ifstream input;
std::string buf;

int main(int argc, char** argv){
    (void)argc; // Unused
    (void)argv; // Unused
    input.open("input");
    // TODO Check that opening input succeeded
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
        // std::cout << "Number of dupes: " << dupes.size() << '\n';
        std::for_each(dupes.begin(), dupes.end(), [&](const char c){score+= score_priority(c);});
        std::cout << "Score: " << score << '\n';
        input >> buf;
    }
    /*
    std::cout << "First line of input: " << buf << '\n';
    std::cout << "Line Length: " << buf.length() << '\n';
    std::string_view fhalf(buf.begin(), buf.begin() + buf.length()/2);
    std::cout << "First Half: " << fhalf << '\n';
     */
}



