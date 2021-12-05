//
// Created by marek on 05.12.2021.
//

#ifndef AOC21_PLANE_UTIL_H
#define AOC21_PLANE_UTIL_H

#include <string_view>
#include <memory>
#include "../classes/point.h"
#include "../classes/plane.h"

std::unique_ptr<Point> parse_point(const std::string_view &str);

std::unique_ptr<Plane> load_plane(std::ifstream &infile);

#endif //AOC21_PLANE_UTIL_H
