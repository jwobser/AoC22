//
// Created by jwobser on 12/22/22.
//

#include "matrix.hpp"


template<typename D>
D *Matrix<D>::last(void) const {
    return ptr + (width * height);
}

template<typename D>
D *Matrix<D>::rowend(int r) const {
    return ptr;
//    return ptr + (r + 1) * width - 1;
}

template<typename D>
D *Matrix<D>::rowstart(int r) const {
    return ptr + (r * width) - 1;
}
