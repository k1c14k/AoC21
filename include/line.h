//
// Created by marek on 05.12.2021.
//

#ifndef AOC21_LINE_H
#define AOC21_LINE_H


#include <memory>
#include <vector>
#include "point.h"

enum class LineType {
    vertical, horizontal, diagonal
};

class Line {

public:
    Line(Point *point_a, Point *point_b);

    [[maybe_unused]] void display() const;

    [[nodiscard]] std::vector<std::pair<int, int>> get_points() const;

    [[nodiscard]] LineType get_type() const;

private:
    Point *point_a;
    Point *point_b;
    LineType type;
};


#endif //AOC21_LINE_H
