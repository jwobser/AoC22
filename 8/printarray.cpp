//
// Created by James Wobser on 12/22/2022.
//

#include "printarray.hpp"
#include <iostream>

void printarr(unsigned short* a, int h, int w){
    const unsigned short* end = a + (w * h);
    while(a < end){
        for(int i{0}; i < w; i++){
            std::cout << *a++ << '.';
        }
        std::cout << '\n';
    }
}
