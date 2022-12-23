//
// Created by James Wobser on 12/22/2022.
//
#include <iostream>
#include "ingest.hpp"
#include "checkvisible.hpp"
#include <cassert>

extern const int HEIGHT{99};
extern const int WIDTH{99};


int main(int argc, char** argv){
    (void) argc; //unused
    (void) argv; //unused
    unsigned short trees[HEIGHT][WIDTH];
    ingest("input", trees[0], HEIGHT, WIDTH);

    // Able to skip all outside tress, since they will inherently be visible
    int count{2 * (WIDTH + HEIGHT - 2)};
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
    return 0;
}