//
// Created by James Wobser on 12/22/2022.
//
#include <iostream>
#include <fstream>
#include <string>
#include "printarray.hpp"
#include "ingest.hpp"
#include "checkvisible.hpp"

extern const int HEIGHT{99};
extern const int WIDTH{99};


int main(int argc, char** argv){
    (void) argc; //unused
    (void) argv; //unused
    unsigned short trees[HEIGHT][WIDTH];
    ingest("input", trees[0], HEIGHT, WIDTH);
    printarr(trees[0]);

    std::cout << std::boolalpha <<


    return 0;
}