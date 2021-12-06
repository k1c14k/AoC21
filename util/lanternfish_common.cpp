//
// Created by marek on 06.12.2021.
//

#include <array>
#include <numeric>
#include "../include/lanternfish_common.h"

unsigned long breed_lanternfish(const std::vector<int> &fishes, int days) {
    std::array<long, 9> lanternfish_counters{};

    for (auto fish: fishes)
        lanternfish_counters[fish]++;

    for (int i = 0; i < days; i++) {
        auto new_spawns = lanternfish_counters[0];
        for (int j = 0; j < 8; j++) {
            lanternfish_counters[j] = lanternfish_counters[j + 1];
        }
        lanternfish_counters[8] = new_spawns;
        lanternfish_counters[6] += new_spawns;
    }
    return std::accumulate(lanternfish_counters.begin(), lanternfish_counters.end(), 0l);
}