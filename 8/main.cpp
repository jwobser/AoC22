//
// Created by James Wobser on 12/22/2022.
//
#include <iostream>
#include "ingest.hpp"
#include "checkvisible.hpp"

extern const int HEIGHT{99};
extern const int WIDTH{99};


int main(int argc, char** argv){
    (void) argc; //unused
    (void) argv; //unused
    unsigned short trees[HEIGHT][WIDTH];
    ingest("input", trees[0], HEIGHT, WIDTH);

    // Able to skip all outside tress, since they will inherently be visible
    int count{2 * (WIDTH + HEIGHT - 2)};
    int maxscore{0};

    for(int i{1}; i < HEIGHT - 1; i++){
        for(int j{1}; j < WIDTH - 1; j++){
            int score = checktree({i,j}, trees[0], HEIGHT, WIDTH);
            maxscore = (score > maxscore) ? score : maxscore;
        }
    }
    std::cout << "Maxscore: " << maxscore << '\n';
    return 0;
}