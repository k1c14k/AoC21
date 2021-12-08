//
// Created by marek on 08.12.2021.
//

#include <algorithm>
#include <map>
#include <numeric>
#include "../include/display.h"
#include "../include/common_util.h"

Display::Display(const std::string &configuration) {
    auto delim_pos = configuration.find(" | ");
    auto signal_values = configuration.substr(0, delim_pos);
    auto output_values = configuration.substr(delim_pos + 3);

    output = parse_sss(output_values);
    signals = parse_sss(signal_values);
}

long Display::count_1478() {
    return std::count_if(output.begin(), output.end(), [](const std::string_view &o) {
        auto len = o.length();
        return len == 2 || len == 4 || len == 3 || len == 7;
    });
}

int Display::decode() {
    // determine 1
    std::string one = *std::find_if(signals.begin(), signals.end(), [](const std::string_view &signal) {
        return signal.length() == 2;
    });
    std::sort(one.begin(), one.end());
    signal_mapping[one] = 1;

    // determine 7
    std::string seven = *std::find_if(signals.begin(), signals.end(), [](const std::string_view &signal) {
        return signal.length() == 3;
    });
    std::sort(seven.begin(), seven.end());
    signal_mapping[seven] = 7;

    // determine 4
    std::string four = *std::find_if(signals.begin(), signals.end(), [](const std::string_view &signal) {
        return signal.length() == 4;
    });
    std::sort(four.begin(), four.end());
    signal_mapping[four] = 4;

    // determine 8
    std::string eight = *std::find_if(signals.begin(), signals.end(), [](const std::string_view &signal) {
        return signal.length() == 7;
    });
    std::sort(eight.begin(), eight.end());
    signal_mapping[eight] = 8;

    std::map<char, long> signal_occurrences;

    for (auto c: "abcdefg") {
        signal_occurrences[c] = std::count_if(signals.begin(), signals.end(), [c](const auto &item) {
            return item.find(c) != std::string::npos;
        });
    }

    // determine 6

    char f_signal = std::find_if(signal_occurrences.begin(), signal_occurrences.end(),
                                 [](const std::pair<char, int> e) {
                                     return e.second == 9;
                                 })->first;
    char c_signal = one[0] == f_signal ? one[1] : one[0];
    std::string six = *std::find_if(signals.begin(), signals.end(), [c_signal](const std::string &signal) {
        return signal.length() == 6 && signal.find(c_signal) == std::string::npos;
    });
    std::sort(six.begin(), six.end());
    signal_mapping[six] = 6;

    // determine 9

    char e_signal = std::find_if(signal_occurrences.begin(), signal_occurrences.end(),
                                 [](const std::pair<char, int> e) {
                                     return e.second == 4;
                                 })->first;
    std::string nine = *std::find_if(signals.begin(), signals.end(), [e_signal](const std::string &signal) {
        return signal.length() == 6 && signal.find(e_signal) == std::string::npos;
    });
    std::sort(nine.begin(), nine.end());
    signal_mapping[nine] = 9;

    // determine 0

    std::string zero = *std::find_if(signals.begin(), signals.end(),
                                     [e_signal, c_signal](const std::string &signal) {
                                         return signal.length() == 6 &&
                                                signal.find(e_signal) != std::string::npos &&
                                                signal.find(c_signal) != std::string::npos;
                                     });
    std::sort(zero.begin(), zero.end());
    signal_mapping[zero] = 0;

    // determine 2

    std::string two = *std::find_if(signals.begin(), signals.end(), [f_signal](const std::string &signal) {
        return signal.length() == 5 && signal.find(f_signal) == std::string::npos;
    });
    std::sort(two.begin(), two.end());
    signal_mapping[two] = 2;

    // determine 3

    std::string three = *std::find_if(signals.begin(), signals.end(),
                                      [f_signal, c_signal](const std::string &signal) {
                                          return signal.length() == 5 &&
                                                 signal.find(f_signal) != std::string::npos &&
                                                 signal.find(c_signal) != std::string::npos;
                                      });
    std::sort(three.begin(), three.end());
    signal_mapping[three] = 3;

    // determine 5

    std::string five = *std::find_if(signals.begin(), signals.end(),
                                     [f_signal, c_signal](const std::string &signal) {
                                         return signal.length() == 5 &&
                                                signal.find(f_signal) != std::string::npos &&
                                                signal.find(c_signal) == std::string::npos;
                                     });
    std::sort(five.begin(), five.end());
    signal_mapping[five] = 5;

    return std::accumulate(output.begin(), output.end(), 0, [this](int a, std::string &b) {
        std::sort(b.begin(), b.end());
        return a * 10 + signal_mapping[b];
    });
}
