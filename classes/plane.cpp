//
// Created by marek on 05.12.2021.
//

#include <iostream>
#include <algorithm>
#include "../include/plane.h"
#include "../include/line.h"

void Plane::add_line(const Line *line, bool include_diagonal) {
    if (include_diagonal || line->get_type() != LineType::diagonal)
        for (auto point: line->get_points()) {
            if (point_occurrences.find(point) != point_occurrences.end())
                point_occurrences[point]++;
            else
                point_occurrences[point] = 1;
        }
}

long Plane::count_collisions() const {
    return std::count_if(point_occurrences.begin(), point_occurrences.end(), [](auto entry) {
        return entry.second > 1;
    });
}
