//
// Created by marek on 21.12.2021.
//

#include "../include/cave_node.h"

#include <utility>

CaveNode::CaveNode(std::string name) {
    this->name = std::move(name);
    is_big_cave = std::isupper(this->name.at(0));
    is_end_node = this->name == "end";
    is_start_node = this->name == "start";
}

void CaveNode::routeTo(CaveNode const &node) {
    routes.push_back(node.name);
}

std::vector<std::string> CaveNode::getRoutes() const {
    return routes;
}

bool CaveNode::isBigCave() const {
    return is_big_cave;
}

const std::string &CaveNode::getName() const {
    return name;
}

bool CaveNode::isEndNode() const {
    return is_end_node;
}

bool CaveNode::isStartNode() const {
    return is_start_node;
}
