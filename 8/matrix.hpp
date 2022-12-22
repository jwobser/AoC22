//
// Created by jwobser on 12/22/22.
//

#ifndef AOC22_MATRIX_HPP
#define AOC22_MATRIX_HPP

template<typename D>
struct Matrix{
    D* ptr;
    int height;
    int width;

    D* last(void) const;
    D* rowstart(int) const;
    D* rowend(int r) const;
};

template<typename D>
D *Matrix<D>::last(void) const {
    return ptr + (width * height);
}

template<typename D>
D *Matrix<D>::rowend(int r) const {
//    return ptr;
    return ptr + (r + 1) * width - 1;
}

template<typename D>
D *Matrix<D>::rowstart(int r) const {
    return ptr + (r * width) - 1;
}

#endif //AOC22_MATRIX_HPP