//
// Created by marek on 21.12.2021.
//

#include "../include/octopus_util.h"

OctopusMap load_map(std::ifstream &input) {
    std::string ln;
    std::vector<std::string> lns;

    while (std::getline(input, ln)) {
        lns.push_back(ln);
    }
    return OctopusMap(lns);
}