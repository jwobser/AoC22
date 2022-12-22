//
// Created by James Wobser on 12/22/2022.
//

#include "checkvisible.hpp"
#include <stdexcept>
#include <memory>

bool checktree(Tree t, unsigned short* a, int h, int w){
    bool visible {false};
    visible |= checkdir(t, 'N', a);
    visible |= checkdir(t, 'E', a);
    visible |= checkdir(t, 'S', a);
    visible |= checkdir(t, 'W', a);
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
    auto p = a + t.col + (t.row * w);
    int h = *p;
    p += step;

    if(step > 0){
        while(p < limit){
            if(h <= *p){return false;}
            p +=step;
        }
    } else {
        while(p > limit){
            if(h <= *p){return false;}
            p +=step;
        }
    }

}