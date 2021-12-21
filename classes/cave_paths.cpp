//
// Created by marek on 21.12.2021.
//

#include <algorithm>
#include "../include/cave_paths.h"

void CavePaths::add_path(const std::string_view &path) {
    std::string from{path.substr(0, path.find('-'))};
    std::string to{path.substr(path.find('-') + 1)};

    if (nodes.find(from) == nodes.end())
        nodes.try_emplace(from, from);

    if (nodes.find(to) == nodes.end())
        nodes.try_emplace(to, to);

    auto &fromNode = nodes.at(from);
    auto &toNode = nodes.at(to);

    fromNode.routeTo(toNode);
    toNode.routeTo(fromNode);
}

CavePaths::CavePaths() {
    nodes.try_emplace("start", "start");
    nodes.try_emplace("end", "end");
}

ulong CavePaths::get_paths_count(const bool enter_small_cave_twice) {
    std::vector<std::vector<std::string>> paths;
    std::vector<std::vector<std::string>> finished_paths;
    std::vector<std::vector<std::string>> duplicated_caves;
    std::vector<std::string> starting_path;
    starting_path.emplace_back("start");
    paths.push_back(starting_path);

    while (!paths.empty()) {
        auto working_path = paths.back();
        paths.pop_back();
        auto working_node = nodes.at(working_path.back());

        if (working_node.isEndNode()) {
            finished_paths.push_back(working_path);
            continue;
        }

        for (auto const &next: working_node.getRoutes()) {
            auto next_node = nodes.at(next);
            if (next_node.isStartNode())
                continue;
            auto new_path = working_path;
            new_path.push_back(next);
            if (next_node.isBigCave() ||
                (std::find(working_path.begin(), working_path.end(), next_node.getName()) == working_path.end())) {
                paths.push_back(new_path);
            } else if (enter_small_cave_twice) {
                duplicated_caves.push_back(new_path);
            }
        }
    }

    while (!duplicated_caves.empty()) {
        auto working_path = duplicated_caves.back();
        duplicated_caves.pop_back();
        auto working_node = nodes.at(working_path.back());

        if (working_node.isEndNode()) {
            finished_paths.push_back(working_path);
            continue;
        }

        for (auto const &next: working_node.getRoutes()) {
            auto next_node = nodes.at(next);
            auto new_path = working_path;
            new_path.push_back(next);
            if (next_node.isBigCave() ||
                (std::find(working_path.begin(), working_path.end(), next_node.getName()) == working_path.end())) {
                duplicated_caves.push_back(new_path);
            }
        }
    }

    return finished_paths.size();
}
