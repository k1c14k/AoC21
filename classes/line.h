//
// Created by marek on 05.12.2021.
//

#ifndef AOC21_LINE_H
#define AOC21_LINE_H


#include <memory>
#include "point.h"

enum class LineType {
    vertical, horizontal, diagonal
};

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
    LineType type;

    bool in_y_range(const Point *pPoint) const;

    bool in_x_range(const Point *pPoint) const;
};


#endif //AOC21_LINE_H
