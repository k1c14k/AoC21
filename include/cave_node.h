//
// Created by marek on 21.12.2021.
//

#ifndef AOC21_CAVE_NODE_H
#define AOC21_CAVE_NODE_H


#include <string_view>
#include <vector>
#include <string>

class CaveNode {

public:
    explicit CaveNode(std::string name);

    void routeTo(CaveNode const &node);

    [[nodiscard]] std::vector<std::string> getRoutes() const;

    [[nodiscard]] bool isBigCave() const;

    [[nodiscard]] bool isEndNode() const;

    [[nodiscard]] bool isStartNode() const;

    [[nodiscard]] const std::string &getName() const;

private:
    std::string name;
    std::vector<std::string> routes;
    bool is_big_cave;
    bool is_end_node;
    bool is_start_node;
};


#endif //AOC21_CAVE_NODE_H
