//
// Created by marek on 20.12.2021.
//

#ifndef AOC21_OCTOPUS_MAP_H
#define AOC21_OCTOPUS_MAP_H


#include <vector>
#include <string>

class OctopusMap {

public:
    explicit OctopusMap(const std::vector<std::string> &lines);

    bool perform_flash();

    [[nodiscard]] ulong get_flashes() const;

private:
    std::vector<std::vector<std::pair<ushort, bool>>> energyLevels;
    ulong max_rows;
    ulong max_cols;
    ulong flashes = 0;

    [[nodiscard]] inline bool in_range(long row, long col) const;

    void update_adjacent(long row, long col);

    bool single_flash();
};


#endif //AOC21_OCTOPUS_MAP_H
