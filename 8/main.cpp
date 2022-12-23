//
// Created by James Wobser on 12/22/2022.
//
#include <iostream>
#include <fstream>
#include <string>
#include "printarray.hpp"
#include "ingest.hpp"
#include "matrix.hpp"
#include "checkvisible.hpp"

extern const int HEIGHT{99};
extern const int WIDTH{99};


int main(int argc, char** argv){
    (void) argc; //unused
    (void) argv; //unused
    unsigned short trees[HEIGHT][WIDTH];
    ingest("input", trees[0], HEIGHT, WIDTH);
    int count{0};
    for(int i{0}; i < HEIGHT; i++){
        for(int j{0}; j < WIDTH; j++){
            if(checktree({i,j}, trees[0], HEIGHT, WIDTH)){
                std::cout << "Tree (" << i << ", " << j << ") is visible\n";
                count++;
            }
        }
    }
    std::cout << "Count: " << count << '\n';
    // printarr(trees[0], HEIGHT, WIDTH);
    /*
    Matrix<unsigned short> m{trees[0], 99,99};
    std::cout << std::hex << m.ptr << '\n';
    std::cout << m.last() << '\n';
    std::cout << std::dec << (m.last() - m.ptr);
     */

//    std::cout << std::boolalpha <<


    return 0;
}