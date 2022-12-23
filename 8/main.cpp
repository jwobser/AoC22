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
#include <cassert>

extern const int HEIGHT{99};
extern const int WIDTH{99};


int main(int argc, char** argv){
    (void) argc; //unused
    (void) argv; //unused
    unsigned short trees[HEIGHT][WIDTH];
    ingest("input", trees[0], HEIGHT, WIDTH);
//    printarr(trees[0], HEIGHT, WIDTH);
    int count{2 * (WIDTH + HEIGHT - 2)};
//    std::cout << count << '\n';
//    std::cout << std::boolalpha << checktree({1,2}, trees[0], HEIGHT, WIDTH) << '\n';
//    std::cout << std::boolalpha << checktree({1,96}, trees[0], HEIGHT, WIDTH) << '\n';
//    std::cout << std::boolalpha << checktree({50,1}, trees[0], HEIGHT, WIDTH) << '\n';
    /*
    std::cout << std::boolalpha << checktree({1,2}, trees[0], HEIGHT, WIDTH) << '\n';
    std::cout << std::boolalpha << checktree({2,2}, trees[0], HEIGHT, WIDTH) << '\n';
    std::cout << std::boolalpha << checktree({50,98}, trees[0], HEIGHT, WIDTH) << '\n';
    std::cout << std::boolalpha << checktree({0,50}, trees[0], HEIGHT, WIDTH) << '\n';
    std::cout << std::boolalpha << checktree({98,50}, trees[0], HEIGHT, WIDTH) << '\n';
     */
    for(int i{1}; i < HEIGHT - 1; i++){
        assert(i < 99);
        for(int j{1}; j < WIDTH - 1; j++){
            assert(i < 99);
            if(checktree({i,j}, trees[0], HEIGHT, WIDTH)){
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