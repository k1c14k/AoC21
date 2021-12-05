//
// Created by marek on 05.12.2021.
//

#ifndef AOC21_LINE_H
#define AOC21_LINE_H


#include <memory>
#include "point.h"

class Line {

public:
    Line(Point *point_a, Point *point_b);

    [[maybe_unused]] void display() const;

    Point *get_a();

    Point *get_b();

    bool point_on(const Point *pPoint, bool diagonal) const;

private:
    Point *point_a;
    Point *point_b;
};


#endif //AOC21_LINE_H
