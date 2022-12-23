//
// Created by James Wobser on 12/22/2022.
//

#include "checkvisible.hpp"
#include <stdexcept>
#include <memory>
#include <iostream>
#include <cassert>

bool checktree(Tree t, unsigned short* a, int h, int w){
//    std::cout << "a: " << a << '\n';
    if(t.row == 0 || t.col == 0 || t.row == h-1 || t.col == w-1){
        return true;
    }
    bool visible {false};
    visible |= checkdir(t, 'N', a, h, w);
    visible |= checkdir(t, 'E', a, h, w);
    visible |= checkdir(t, 'S', a, h, w);
    visible |= checkdir(t, 'W', a, h, w);
    return visible;
}

bool checkdir(Tree& t, char d, const unsigned short* a, int h, int w){
    int step;
    decltype(a) limit;
    switch(d){
        case 'N':
            limit = a;
            step = -1 * w;
            break;
        case 'E':
            limit = a + ((1 + t.row) * w);
            step = 1;
            break;
        case 'S':
            limit = a + (w * h);
            step = 1 * w;
            break;
        case 'W':
            limit = a + (t.row * w);
            step = -1;
            break;
        default:
            throw std::runtime_error("Check direction not given.");
    }
//    std::cout << "Check " << d << " - lim: " << limit << "\t step: " << step << '\n';
    auto p = a + t.col + (t.row * w);
    size_t row = (p - a) / w;
    size_t col = (p - a) % w;
//    std::cout << row << ", " << col << '\n';
    int th = *p;
//    std::cout << "Tree Height: " << th << '\n';
//    std::cout << "p: " << p << '\n';// " -> " << p + step << '\n';
    p += step;

    if(step > 0){
        while(p < limit){
            assert(p < (a + (h * w)));
            if(th <= *p){return false;}
            p +=step;
        }
//        std::cout << "p: " << p << " >= " << limit << '\n';
    } else {
        while(p >= limit){
            assert(p >= a);
            if(th <= *p){return false;}
            p +=step;
        }
//        std::cout << "p: " << p << " < " << limit << '\n';
    }
    return true;
}