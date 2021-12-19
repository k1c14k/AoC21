//
// Created by marek on 19.12.2021.
//

#include <algorithm>
#include <set>
#include "../include/height_map.h"

HeightMap::HeightMap(const std::vector<std::string> &heightsString) {
    for (auto const &ln: heightsString) {
        std::vector<int> row;
        for (auto ch: ln)
            row.push_back(ch - '0');
        heights.push_back(row);
    }

    rows = heights.size();
    cols = heights.at(0).size();
}

std::vector<std::pair<unsigned long, unsigned long>> HeightMap::get_low_points() {
    auto result = std::vector<std::pair<unsigned long, unsigned long>>();

    for (auto row = 0; row < rows; row++)
        for (auto col = 0; col < cols; col++) {
            auto point = heights.at(row).at(col);
            std::vector<int> adjacent;

            if (row > 0)
                adjacent.push_back(heights.at(row - 1).at(col));
            if (row < rows - 1)
                adjacent.push_back(heights.at(row + 1).at(col));
            if (col > 0)
                adjacent.push_back(heights.at(row).at(col - 1));
            if (col < cols - 1)
                adjacent.push_back(heights.at(row).at(col + 1));

            if (point < *std::min_element(adjacent.begin(), adjacent.end())) {
                result.emplace_back(row, col);
            }
        }

    return result;
}

int HeightMap::risk_level_at(std::pair<unsigned long, unsigned long> coords) const {
    return 1 + heights.at(coords.first).at(coords.second);
}

unsigned long HeightMap::get_basin_size(std::pair<unsigned long, unsigned long> const &coord) const {
    std::vector<std::pair<unsigned long, unsigned long>> to_process;
    std::set<std::pair<unsigned long, unsigned long>> processed;
    to_process.push_back(coord);

    while (!to_process.empty()) {
        auto working = to_process.back();
        to_process.pop_back();
        std::vector<std::pair<unsigned long, unsigned long >> adjacent;

        if (working.first > 0)
            adjacent.emplace_back(working.first - 1, working.second);
        if (working.first < rows - 1)
            adjacent.emplace_back(working.first + 1, working.second);
        if (working.second > 0)
            adjacent.emplace_back(working.first, working.second - 1);
        if (working.second < cols - 1)
            adjacent.emplace_back(working.first, working.second + 1);

        for (auto const &adj: adjacent) {
            if (risk_level_at(adj) != 10 && risk_level_at(adj) > risk_level_at(working))
                to_process.push_back(adj);
        }

        processed.insert(working);
    }

    return processed.size();
}
