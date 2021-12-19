#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "include/height_map.h"
#include "include/height_map_util.h"

int main() {
    std::ifstream infile("input/input_9_1.txt");

    HeightMap heightMap = read_map(infile);
    std::vector<std::pair<unsigned long, unsigned long>> lowPoints = heightMap.get_low_points();
    std::vector<ulong> basin_sizes;

    basin_sizes.reserve(lowPoints.size());
    for (auto const &low_point: lowPoints) {
        basin_sizes.push_back(heightMap.get_basin_size(low_point));
    }

    std::sort(basin_sizes.begin(), basin_sizes.end(), std::greater<>());

    std::cout << basin_sizes.at(0) * basin_sizes.at(1) * basin_sizes.at(2) << std::endl;

    return 0;
}

