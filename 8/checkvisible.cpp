//
// Created by James Wobser on 12/22/2022.
//

#include "checkvisible.hpp"
#include <stdexcept>
#include <cassert>

int checktree(Tree t, unsigned short* a, int h, int w){
    if(t.row == 0 || t.col == 0 || t.row == h-1 || t.col == w-1){
        return 0;
    }
    int score {1};
    score *= checkdir(t, 'N', a, h, w);
    score *= checkdir(t, 'E', a, h, w);
    score *= checkdir(t, 'S', a, h, w);
    score *= checkdir(t, 'W', a, h, w);
    return score;
}

int checkdir(Tree& t, char d, const unsigned short* a, int h, int w){
    int step;
    int score{1};
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
    int th = *p;
    p += step;

    if(step > 0){
        while(p < limit){
            if(th <= *p){break;}
            score++;
            p +=step;
        }
    } else {
        while(p >= limit){
            if(th <= *p){break;}
            score++;
            p +=step;
        }
    }
    return score;
}