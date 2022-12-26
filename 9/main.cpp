//
// Created by James Wobser on 12/26/2022.
//
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <stdexcept>
#include <cmath>


struct Point{
    int x,y;

    auto operator<=>(const Point& a) const = default;
};

namespace std{
    template <>
    struct hash<Point>{
        size_t operator()(const Point& p) const noexcept {
            return p.x * 10'000 + p.y;
        }
    };
}

void movetail(const int& hx, const int& hy, int& tx, int& ty){
    if(hx == tx && hy == ty){return;}
    int dx = hx - tx;
    int dy = hy - ty;
    if(abs(dx) <= 1 && abs(dy) <= 1){return;}
    if(dy == 0){
        tx += (dx < 0) ? -1 : 1;
    } else if(dx == 0){
        ty += (dy < 0) ? -1 : 1;
    } else {
        ty += (dy < 0) ? -1 : 1;
        tx += (dx < 0) ? -1 : 1;
    }
    return;
}

int main(int argc, char** argv){
    std::fstream input("input");
    std::unordered_set<Point, std::hash<Point>> visited;
    int xhead {0}, yhead{0};
    int xtail {0}, ytail{0};
    if(input.fail()){return 1;}
    while(!input.eof()){
        char dir;
        int magnitude;
        input >> dir >> magnitude;
        int xstep {0}, ystep{0};
        switch(dir){
            case 'U':
                ystep = 1;
                break;
            case 'D':
                ystep = -1;
                break;
            case 'L':
                xstep = -1;
                break;
            case 'R':
                xstep = 1;
                break;
            default:
                throw std::runtime_error("Bad direction given");
        }
        while(magnitude--){
            xhead += xstep;
            yhead += ystep;
            movetail(xhead, yhead, xtail, ytail);
            visited.insert({xtail, ytail});
        }
//        std::cout << "Head location: (" << xhead << ", " << yhead << ")\n";
    }
    std::cout << "Number of tail locations: " << visited.size() << '\n';

    return 0;
}
