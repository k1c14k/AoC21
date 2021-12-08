//
// Created by marek on 08.12.2021.
//

#ifndef AOC21_DISPLAY_H
#define AOC21_DISPLAY_H


#include <string>
#include <vector>
#include <map>

class Display {
public:
    explicit Display(const std::string &configuration);

    long count_1478();

    int decode();

private:
    std::vector<std::string> output;
    std::vector<std::string> signals;
    std::map<std::string, int> signal_mapping;
};


#endif //AOC21_DISPLAY_H
