//
// Created by marek on 05.12.2021.
//

#include <iostream>
#include "../include/line.h"

Line::Line(Point *point_a, Point *point_b) : point_a(point_a), point_b(point_b) {
    if (point_a->get_x() == point_b->get_x())
        type = LineType::vertical;
    else if (point_a->get_y() == point_b->get_y())
        type = LineType::horizontal;
    else
        type = LineType::diagonal;
}

[[maybe_unused]] void Line::display() const {
    std::cout << "(" << point_a->get_x() << "," << point_a->get_y() << ") to (" << point_b->get_x() << ","
              << point_b->get_y() << ")" << std::endl;
}

std::vector<std::pair<int, int>> Line::get_points() const {
    std::vector<std::pair<int, int>> result;

    if (type == LineType::vertical) {
        for (int y = std::min(point_a->get_y(), point_b->get_y());
             y <= std::max(point_a->get_y(), point_b->get_y()); y++) {
            result.emplace_back(point_a->get_x(), y);
        }
    } else if (type == LineType::horizontal) {
        for (int x = std::min(point_a->get_x(), point_b->get_x());
             x <= std::max(point_a->get_x(), point_b->get_x()); x++) {
            result.emplace_back(x, point_a->get_y());
        }
    } else if (type == LineType::diagonal) {
        auto dx = point_b->get_x() - point_a->get_x() < 0 ? -1 : 1;
        auto dy = point_b->get_y() - point_a->get_y() < 0 ? -1 : 1;
        int step = 0;
        while (true) {
            result.emplace_back(point_a->get_x() + dx * step, point_a->get_y() + dy * step);
            if (point_a->get_x() + step * dx == point_b->get_x())
                break;
            step++;
        }
    }

    return result;
}

LineType Line::get_type() const {
    return type;
}
