//
// Created by marek on 19.12.2021.
//

#ifndef AOC21_CHUNK_PARSER_H
#define AOC21_CHUNK_PARSER_H


#include <string>
#include <array>


class ChunkParser {

public:
    explicit ChunkParser(std::__cxx11::basic_string<char> chunk);

    [[nodiscard]] ulong get_corrupted_score() const;

    [[nodiscard]] ulong get_incomplete_score() const;

private:
    std::string chunk;
    const std::array<ulong, 5> INCOMPLETE_SCORE = {1, 2, 3, 4};
    const std::array<ulong, 5> CORRUPTED_SCORE = {3, 57, 1197, 25137};
    const std::string OPENING = "([{<";
    const std::string CLOSING = ")]}>";
};


#endif //AOC21_CHUNK_PARSER_H
