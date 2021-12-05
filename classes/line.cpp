//
// Created by marek on 05.12.2021.
//

#include <iostream>
#include "line.h"

Line::Line(Point *point_a, Point *point_b) : point_a(point_a), point_b(point_b) {}

[[maybe_unused]] void Line::display() const {
    std::cout << "(" << point_a->get_x() << "," << point_a->get_y() << ") to (" << point_b->get_x() << ","
              << point_b->get_y() << ")" << std::endl;
}

Point *Line::get_a() {
    return point_a;
}

Point *Line::get_b() {
    return point_b;
}

bool Line::point_on(const Point *pPoint, bool diagonal) const {
    if (((point_a->get_x() == point_b->get_x()) && (point_a->get_x() == pPoint->get_x()) &&
         (std::min(point_a->get_y(), point_b->get_y()) <= pPoint->get_y()) &&
         std::max(point_a->get_y(), point_b->get_y()) >= pPoint->get_y()) ||
        ((point_a->get_y() == point_b->get_y()) && (point_a->get_y() == pPoint->get_y()) &&
         (std::min(point_a->get_x(), point_b->get_x()) <= pPoint->get_x()) &&
         std::max(point_a->get_x(), point_b->get_x()) >= pPoint->get_x()))
        return true;
    else if (diagonal && (point_a->get_x() != point_b->get_x()) && (point_a->get_y() != point_b->get_y())) {
        auto vx = pPoint->get_x() - point_a->get_x();
        auto vy = pPoint->get_y() - point_a->get_y();
        if (abs(vx) == abs(vy) && (std::min(point_a->get_x(), point_b->get_x()) <= pPoint->get_x()) &&
            std::max(point_a->get_x(), point_b->get_x()) >= pPoint->get_x() &&
            (std::min(point_a->get_y(), point_b->get_y()) <= pPoint->get_y()) &&
            std::max(point_a->get_y(), point_b->get_y()) >= pPoint->get_y())
            return true;
    }
    return false;
}
