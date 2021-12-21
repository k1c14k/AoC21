//
// Created by marek on 21.12.2021.
//

#ifndef AOC21_CAVE_PATHS_H
#define AOC21_CAVE_PATHS_H


#include <string>
#include <map>
#include "cave_node.h"

class CavePaths {

public:
    void add_path(const std::string_view &path);

    CavePaths();

    ulong get_paths_count(bool enter_small_cave_twice);

private:
    std::map<std::string, CaveNode, std::less<>> nodes;
};


#endif //AOC21_CAVE_PATHS_H
