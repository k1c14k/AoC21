//
// Created by marek on 19.12.2021.
//

#include "../include/chunk_parser.h"

#include <utility>
#include <vector>
#include <numeric>

ChunkParser::ChunkParser(std::__cxx11::basic_string<char> chunk) : chunk(std::move(chunk)) {
}

ulong ChunkParser::get_corrupted_score() const {
    std::vector<ulong> stack;
    for (auto ch: chunk) {
        if (OPENING.find(ch) != std::string::npos) {
            stack.push_back(OPENING.find(ch));
        } else {
            if (CLOSING.find(ch) == stack.back()) {
                stack.pop_back();
            } else {
                return CORRUPTED_SCORE.at(CLOSING.find(ch));
            }
        }
    }
    return 0;
}

ulong ChunkParser::get_incomplete_score() const {
    std::vector<ulong> stack;
    for (auto ch: chunk) {
        if (OPENING.find(ch) != std::string::npos) {
            stack.push_back(OPENING.find(ch));
        } else {
            if (CLOSING.find(ch) == stack.back()) {
                stack.pop_back();
            } else {
                return 0;
            }
        }
    }

    return std::accumulate(stack.rbegin(), stack.rend(), (ulong) 0, [this](ulong acc, auto ch) {
        return acc * 5 + INCOMPLETE_SCORE.at(ch);
    });
}
