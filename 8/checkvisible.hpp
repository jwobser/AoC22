//
// Created by James Wobser on 12/22/2022.
//

#ifndef AOC22_CHECKVISIBLE_HPP
#define AOC22_CHECKVISIBLE_HPP

struct Tree{
    int row, col;
};

bool checkdir(Tree& t, char d, const unsigned short* a, int, int);
bool checktree(Tree t, unsigned short*, int, int);


#endif //AOC22_CHECKVISIBLE_HPP
