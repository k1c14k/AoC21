//
// Created by marek on 05.12.2021.
//

#ifndef AOC21_PLANE_H
#define AOC21_PLANE_H


#include <vector>
#include <map>
#include "line.h"

class Plane {
public:
    void add_line(const Line *line, bool include_diagonal);

    [[nodiscard]] long count_collisions() const;

private:
    std::map<std::pair<int, int>, int> point_occurrences;
};


#endif //AOC21_PLANE_H
