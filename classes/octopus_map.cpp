//
// Created by marek on 20.12.2021.
//

#include "../include/octopus_map.h"

OctopusMap::OctopusMap(const std::vector<std::string> &lines) {
    for (auto &line: lines) {
        std::vector<std::pair<ushort, bool>> mapLine;
        for (auto &level: line) {
            mapLine.emplace_back(level - '0', false);
        }
        energyLevels.push_back(mapLine);
    }
    max_rows = energyLevels.size();
    max_cols = energyLevels.at(0).size();
}

bool OctopusMap::perform_flash() {
    for (auto &line: energyLevels)
        for (auto &[level, flashed]: line)
            level++;

    bool flashed_in_step = true;
    while (flashed_in_step) {
        flashed_in_step = single_flash();
    }

    ulong number_flashed = 0;
    for (auto &line: energyLevels)
        for (auto &[level, flashed]: line)
            if (flashed) {
                flashed = false;
                level = 0;
                number_flashed++;
            }

    flashes += number_flashed;

    return number_flashed == max_rows * max_cols;
}

bool OctopusMap::single_flash() {
    bool flashed_in_step = false;
    for (long row = 0; row < max_rows; row++)
        for (long col = 0; col < max_cols; col++) {
            auto &[level, flashed] = energyLevels.at(row).at(col);
            if (!flashed && level > 9) {
                flashed = true;
                flashed_in_step = true;
                update_adjacent(row, col);
            }
        }
    return flashed_in_step;
}

void OctopusMap::update_adjacent(long row, long col) {
    for (int ri = -1; ri <= 1; ri++)
        for (int ci = -1; ci <= 1; ci++)
            if ((ri != 0 || ci != 0) && in_range(row + ri, col + ci)) {
                energyLevels.at(row + ri).at(col + ci).first++;
            }
}

ulong OctopusMap::get_flashes() const {
    return flashes;
}

inline bool OctopusMap::in_range(long row, long col) const {
    return row >= 0 && row < max_rows && col >= 0 && col < max_cols;
}
