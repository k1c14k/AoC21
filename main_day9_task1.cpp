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

    auto total_risk = std::accumulate(lowPoints.begin(), lowPoints.end(), 0,
                                      [heightMap](auto acc, std::pair<unsigned long, unsigned long> coords) {
                                          return acc + heightMap.risk_level_at(coords);
                                      });

    std::cout << total_risk << std::endl;

    return 0;
}

