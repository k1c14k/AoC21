#include <iostream>
#include <fstream>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>

unsigned long get_gen_rating(std::vector<unsigned long> data, unsigned long size);

unsigned long get_scrubber_rating(std::vector<unsigned long> data, unsigned long word_size);

unsigned long get_rating(std::vector<unsigned long> data, unsigned long word_size, bool lower);

int main() {
    std::ifstream infile("input/input_3_1.txt");
    std::string entry;
    std::vector<unsigned long> entries;

    infile >> entry;
    auto word_size = entry.size();
    do {
        long entry_long = stol(entry, nullptr, 2);
        entries.push_back(entry_long);
    } while (infile >> entry);

    auto gen_rating = get_gen_rating(entries, word_size);

    auto scrubber_rating = get_scrubber_rating(entries, word_size);

    std::cout << gen_rating * scrubber_rating << std::endl;
    return 0;
}

unsigned long get_rating(std::vector<unsigned long> data, unsigned long word_size, bool lower) {
    unsigned long a = 0;
    unsigned long b = (1 << word_size);
    unsigned long r = 1 << (word_size - 1);
    std::vector<unsigned long> remaining;
    std::copy(data.begin(), data.end(), std::back_inserter(remaining));
    std::vector<unsigned long> group_a;
    std::vector<unsigned long> group_b;
    while (true) {
        std::copy_if(remaining.begin(), remaining.end(), std::back_inserter(group_a), [&](const auto &item) {
            return (a <= item) && (item < b - r);
        });
        std::copy_if(remaining.begin(), remaining.end(), std::back_inserter(group_b), [&](const auto &item) {
            return (b - r <= item) && (item < b);
        });

        if (lower ? group_b.size() < group_a.size() : group_b.size() >= group_a.size()) {
            if (group_b.size() == 1)
                return group_b[0];
            remaining.clear();
            std::copy(group_b.begin(), group_b.end(), std::back_inserter(remaining));
            a += r;
        } else {
            if (group_a.size() == 1)
                return group_a[0];
            remaining.clear();
            std::copy(group_a.begin(), group_a.end(), std::back_inserter(remaining));
            b -= r;
        }
        group_a.clear();
        group_b.clear();
        r >>= 1;
    }
}
unsigned long get_scrubber_rating(std::vector<unsigned long> data, unsigned long word_size) {
    return get_rating(std::move(data), word_size, true);
}

unsigned long get_gen_rating(std::vector<unsigned long> data, unsigned long word_size) {
    return get_rating(std::move(data), word_size, false);
}
