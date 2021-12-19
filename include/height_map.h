//
// Created by marek on 19.12.2021.
//

#ifndef AOC21_HEIGHT_MAP_H
#define AOC21_HEIGHT_MAP_H


#include <vector>
#include <string>

class HeightMap {

public:
    explicit HeightMap(const std::vector<std::string> &heightsString);

    std::vector<std::pair<unsigned long, unsigned long>> get_low_points();

    [[nodiscard]] int risk_level_at(std::pair<unsigned long, unsigned long> coords) const;

    [[nodiscard]] unsigned long get_basin_size(const std::pair<unsigned long, unsigned long> &coord) const;

private:
    std::vector<std::vector<int>> heights;
    unsigned long rows;
    unsigned long cols;
};


#endif //AOC21_HEIGHT_MAP_H
