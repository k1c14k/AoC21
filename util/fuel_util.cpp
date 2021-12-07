//
// Created by marek on 07.12.2021.
//

#include <algorithm>
#include <numeric>
#include "../include/fuel_util.h"


int find_cheapest_position(std::vector<int> &input) {
    return find_cheapest_position(input, [](auto a) { return a; });
}

int find_cheapest_position(std::vector<int> &input, const std::function<int(int)> &cost_function) {
    auto a = *std::min_element(input.begin(), input.end());
    auto b = *std::max_element(input.begin(), input.end());
    auto cost_a = calculate_cost(input, a, cost_function);
    auto cost_b = calculate_cost(input, b, cost_function);
    int cheapest_pos = -1;

    while (cheapest_pos == -1) {
        if (cost_a < cost_b) {
            b = b - ((b - a) / 2);
        } else {
            a = a + ((b - a) / 2);
        }
        cost_a = calculate_cost(input, a, cost_function);
        cost_b = calculate_cost(input, b, cost_function);

        if (b - a < 2) {
            if (cost_a < cost_b) {
                cheapest_pos = a;
            } else {
                cheapest_pos = b;
            }
        }
    }
    return cheapest_pos;
}

int calculate_cost(const std::vector<int> &positions, int middle) {
    return calculate_cost(positions, middle, [](auto a) { return a; });
}

int calculate_cost(const std::vector<int> &positions, int middle, const std::function<int(int)> &cost_function) {
    return std::accumulate(positions.begin(), positions.end(), 0, [middle, cost_function](int a, int b) {
        return a + cost_function(abs(b - middle));
    });
}
