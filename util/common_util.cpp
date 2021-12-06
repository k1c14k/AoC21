//
// Created by marek on 06.12.2021.
//

#include "../include/common_util.h"

std::vector<int> read_csi(std::ifstream &input) {
    std::vector<int> result;
    std::string line;
    input >> line;
    size_t pos;
    while ((pos = line.find(',')) != std::string::npos) {
        result.push_back(std::stoi(line.substr(0, pos)));
        line.erase(0, pos + 1);
    }
    result.push_back(std::stoi(line));

    return result;
}