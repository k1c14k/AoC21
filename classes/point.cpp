//
// Created by marek on 05.12.2021.
//

#include <iostream>
#include "../include/point.h"

Point::Point(int x, int y) : x(x), y(y) {}

[[maybe_unused]] void Point::display() const {
    std::cout << "(" << x << "," << y << ")" << std::endl;
}

int Point::get_x() const {
    return x;
}

int Point::get_y() const {
    return y;
}
