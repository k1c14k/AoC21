#include <iostream>
#include <fstream>

int main() {
    std::ifstream infile("input/input_3_1.txt");
    std::string entry;
    infile >> entry;

    unsigned long entry_length = entry.length();
    int *zeros = new int[entry_length];
    int *ones = new int[entry_length];

    do {
        for (std::string::size_type i = 0; i < entry_length; i++) {
            if (entry[i] == '0') zeros[i]++;
            else if (entry[i] == '1') ones[i]++;
        }
    } while (infile >> entry);

    int gamma_rate = 0, epsilon_rate = 0;

    for (unsigned long i = 0; i < entry_length; i++) {
        gamma_rate <<= 1;
        epsilon_rate <<=1;
        if (ones[i] > zeros[i]) gamma_rate++;
        else epsilon_rate++;
    }

    std::cout << gamma_rate * epsilon_rate << std::endl;

    return 0;
}
