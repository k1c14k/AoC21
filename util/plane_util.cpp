//
// Created by marek on 05.12.2021.
//

#include <charconv>
#include <fstream>
#include "../include/plane_util.h"

std::unique_ptr<Plane> load_plane(std::ifstream &infile, bool include_diagonals) {
    auto plane = std::make_unique<Plane>();
    for (std::string line; std::getline(infile, line);) {
        auto point_sep = line.find(" -> ");
        auto point_a = line.substr(0, point_sep);
        auto point_b = line.substr(point_sep + 4);
        auto a = parse_point(point_a);
        auto b = parse_point(point_b);
        auto l = std::make_unique<Line>(a.release(), b.release());
        plane->add_line(l.release(), include_diagonals);
    }
    return plane;
}

std::unique_ptr<Point> parse_point(const std::string_view &str) {
    auto sep = str.find(',');
    const std::string_view &x_str = str.substr(0, sep);
    int x;
    int y;
    std::from_chars(x_str.data(), x_str.data() + x_str.size(), x);
    const std::string_view &y_str = str.substr(sep + 1);
    std::from_chars(y_str.data(), y_str.data() + y_str.size(), y);
    return std::make_unique<Point>(x, y);
}