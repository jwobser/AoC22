//
// Created by James Wobser on 12/21/2022.
//

#include <fstream>
#include <string>
#include <set>
#include <deque>
#include <array>
#include <algorithm>
#include <iostream>
#include <execution>

bool isSOTfound(std::array<unsigned short, 26> a){
    auto pred = [](const unsigned short c){return c > 1;};
    bool found = !std::any_of(std::execution::par, a.begin(), a.end(), pred);
    return found;
}

void printcounts(std::array<unsigned short, 26> a){
    for(int i{0}; i < 26; i++){
        std::cout << static_cast<char>(i+'a') << " : " << a[i] << '\n';
    }
    std::cout << '\n';
}

int main(int argc, char** argv){
    (void) argc;
    (void) argv;
    std::string buf;
    std::ifstream input;
    std::array<unsigned short, 26> counts {};
    std::deque<char> chars;
    char c;
    int sot_byte {4};
    bool sot_found {false};

    input.open("input");
    for(int i{0}; i < 4; i++){
        input >> c;
        int idx = c - 'a';
        chars.push_back(c);
        counts[idx] += 1;
    }

    sot_found = isSOTfound(counts);

    while(!sot_found){
        int first = chars.front() - 'a';
        counts[first] -= 1;
        chars.pop_front();
        input >> c;
        int last = c - 'a';
        counts[last] += 1;
        chars.push_back(c);
        sot_found = isSOTfound(counts);
        sot_byte++;
        if(input.eof()){return 1;}
    }
    printcounts(counts);

    std::cout << "Start byte: " << sot_byte << '\n';

    return 0;
}
