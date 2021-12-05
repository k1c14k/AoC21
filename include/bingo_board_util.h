//
// Created by marek on 04.12.2021.
//

#ifndef AOC21_BINGO_BOARD_UTIL_H
#define AOC21_BINGO_BOARD_UTIL_H

#include <vector>
#include <fstream>

std::vector<int> read_draws(std::ifstream &input);

std::vector<int> read_board_data(std::ifstream &input);

#endif //AOC21_BINGO_BOARD_UTIL_H
