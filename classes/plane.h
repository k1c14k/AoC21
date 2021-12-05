//
// Created by marek on 05.12.2021.
//

#ifndef AOC21_PLANE_H
#define AOC21_PLANE_H


#include <vector>
#include "line.h"

class Plane {
public:
    void add_line(Line *line);

    [[maybe_unused]] void display() const;

    [[nodiscard]] int get_min_x() const;

    [[nodiscard]] int get_min_y() const;

    [[nodiscard]] int get_max_x() const;

    [[nodiscard]] int get_max_y() const;

    bool check_collisions(const Point *pPoint) const;

    bool check_collisions(const Point *pPoint, bool diagonal) const;

private:
    std::vector<Line *> lines;
    int min_x = -1;
    int min_y = -1;
    int max_x = -1;
    int max_y = -1;

    void update_range(const Point *pPoint);
};


#endif //AOC21_PLANE_H
