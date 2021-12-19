//
// Created by marek on 19.12.2021.
//

#include "../include/height_map_util.h"

HeightMap read_map(std::ifstream &input) {
    std::string ln;
    std::vector<std::string> map;

    while (std::getline(input, ln)) {
        map.push_back(ln);
    }
    return HeightMap(map);
}