//
// Created by James Wobser on 12/22/2022.
//

#include "ingest.hpp"

void ingest(std::string fname, unsigned short* trees, int height, int width){
    std::fstream input(fname);
    if(input.fail()){throw std::runtime_error("Couldn't Open File: " + fname);}
    char c;
    for(int i{0}; i < height; i++){
        for(int j{0}; j < width; j++){
            int idx = (i * width) + j;
            input >> c;
            *(trees + idx) = static_cast<unsigned short>(std::atoi(&c));
        }
    }
}


