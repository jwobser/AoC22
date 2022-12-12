//
// Created by James Wobser on 12/11/2022.
//
#include <string>
#include <unordered_set>

#ifndef AOC22_MAIN_HPP
#define AOC22_MAIN_HPP

int score_priority(const char& letter) {
    if(letter >= 'a' && letter <= 'z'){
        return 1 + static_cast<int>(letter - 'a');
    } else if(letter >= 'A' && letter <= 'Z'){
        return 27 + static_cast<int>(letter - 'A');
    }
    return 0;
}

bool check_len(const std::string_view& s){
    if((s.length() % 2) != 0){
        throw(std::invalid_argument("String Length not even"));
    } else {
        return true;
    }
}

std::vector<char> find_duplicates(std::string_view s){
    std::vector<char> dupes;
    std::unordered_set<char> leftchars;
    int i{0};
    for(; i < s.length()/2; ++i){
        leftchars.insert(s[i]);
    }
    for(;i < s.length(); ++i){
        if(leftchars.find(s[i]) == leftchars.end()){
            continue;
        } else {
            dupes.push_back(s[i]);
            // HACK Return early to avoid double counting
            return dupes;
        }
    }
    return dupes;
}

#endif //AOC22_MAIN_HPP
