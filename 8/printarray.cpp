//
// Created by James Wobser on 12/22/2022.
//

#include "printarray.hpp"
#include <iostream>

extern const int HEIGHT;
extern const int WIDTH;

void printarr(unsigned short* a){
    const unsigned short* end = a + (WIDTH * HEIGHT);
    while(a < end){
        for(int i{0}; i < WIDTH; i++){
            std::cout << *a++ << '.';
        }
        std::cout << '\n';
    }
}
