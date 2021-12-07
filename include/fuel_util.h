//
// Created by marek on 07.12.2021.
//

#ifndef AOC21_FUEL_UTIL_H
#define AOC21_FUEL_UTIL_H

#include <vector>

int calculate_cost(const std::vector<int> &positions, int middle);

int calculate_cost(const std::vector<int> &positions, int middle, const std::function<int(int)> &cost_function);

int find_cheapest_position(std::vector<int> &input);

int find_cheapest_position(std::vector<int> &input, const std::function<int(int)> &cost_function);

#endif //AOC21_FUEL_UTIL_H
