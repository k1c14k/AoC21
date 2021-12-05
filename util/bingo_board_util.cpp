//
// Created by marek on 04.12.2021.
//

#include "../include/bingo_board_util.h"

std::vector<int> read_board_data(std::ifstream &input) {
    std::vector<int> result;
    int line;

    for (int i = 0; (i < 25) && (input >> line); i++) {
        result.push_back(line);
    }

    return result;
}

std::vector<int> read_draws(std::ifstream &input) {
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