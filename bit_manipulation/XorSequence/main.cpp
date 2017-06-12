#include <iostream>
#include <vector>
#include <bitset>
#include <iomanip>
#include <array>

std::array<unsigned long long, 10> mem_a = {0, 1, 3, 0, 4, 1, 7, 0, 8, 1};

unsigned long long get_a(unsigned long long i) {
    if (i <= 9)
        return mem_a[i];
    char last_two = i & 0b11;
    if (last_two == 0b00)
        return i;
    if (last_two == 0b01)
        return 1;
    if (last_two == 0b10)
        return i + 1;
    return 0;
}

unsigned long long get_b(unsigned long long i) {
    char mask = (i & 0b111) >> 1;
    if (mask == 0b00)
        return i;
    if (mask == 0b01)
        return 2;
    if (mask == 0b10)
        return i + 2;
    return 0;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long l, r;
        std::cin >> l >> r;
        std::cout << (get_b(l - 1) ^ get_b(r)) << std::endl;
    }

    /*for (int i = 0, acc = 0; i < 50; ++i) {
        acc ^= get_a(i);
        std::cout << std::setw(2) << i << "(" << std::bitset<2>((i & 0b111) >> 1) << ")" << ": " << std::setw(2) << acc << " (" << std::bitset<8>(acc) << ")" << std::endl;
    }*/
    return 0;
}