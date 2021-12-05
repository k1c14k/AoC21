//
// Created by marek on 05.12.2021.
//

#include <iostream>
#include "plane.h"

void Plane::add_line(Line *line) {
    lines.push_back(line);
    update_range(line->get_a());
    update_range(line->get_b());
}

void Plane::update_range(const Point *pPoint) {
    if (min_x < 0)
        min_x = pPoint->get_x();
    else
        min_x = std::min(min_x, pPoint->get_x());
    if (min_y < 0)
        min_y = pPoint->get_y();
    else
        min_y = std::min(min_y, pPoint->get_y());
    if (max_x < 0)
        max_x = pPoint->get_x();
    else
        max_x = std::max(max_x, pPoint->get_x());
    if (max_y < 0)
        max_y = pPoint->get_y();
    else
        max_y = std::max(max_y, pPoint->get_y());
}

[[maybe_unused]] void Plane::display() const {
    std::cout << "Lines: " << lines.size() << std::endl;
    std::cout << min_x << " " << min_y << " " << max_x << " " << max_y << std::endl;
}

int Plane::get_min_x() const {
    return min_x;
}

int Plane::get_max_x() const {
    return max_x;
}

int Plane::get_min_y() const {
    return min_y;
}

int Plane::get_max_y() const {
    return max_y;
}

bool Plane::check_collisions(const Point *pPoint) const {
    return check_collisions(pPoint, false);
}

bool Plane::check_collisions(const Point *pPoint, bool diagonal) const {
    int collisions = 0;
    for (auto line: lines) {
        if (line->point_on(pPoint, diagonal))
            collisions++;
        if (collisions > 1)
            return true;
    }
    return false;
}
