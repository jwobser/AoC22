#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <string_view>
#include "main.hpp"
#include <vector>
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
        /*
        for(int i{0}; i < 3; ++i){
            std::cout << std::hex << reinterpret_cast<void*>(lines[i].data()) << '\t';
        }
        */
        std::cout << '\n';

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
        /*
        for (auto c : lines[0]){
            items_in_common.insert(c);
        }
        for (int i {1}; i < 3; ++i){
            for(auto c : lines[i]){
                if(items_in_common.find(c) == items_in_common.end()){
                    items_in_common.erase(c);
                }
            }
        }
        */

        for(auto c : charsets[3]){
            std::cout << c << " ";
            score += score_priority(c);
        }

        std::cout << '\n';

        /*
        auto dupes = find_duplicates(buf);
        std::for_each(dupes.begin(), dupes.end(), [&](const char c){score+= score_priority(c);});
        input >> buf;
        */
    }
    std::cout << "Score: " << score << '\n';
    return 0;
}



