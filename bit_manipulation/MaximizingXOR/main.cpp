#include <iostream>
#include <cmath>

int max_xor(int l, int r) {
    int max_so_far = -1;
    for (int i = l; i <= r; ++i)
        for (int j = l; j <= r; ++j)
            max_so_far = std::max(max_so_far, i ^ j);
    return max_so_far;
}

int main() {
    int l, r;
    std::cin >> l >> r;
    std::cout << max_xor(l, r) << std::endl;
    return 0;
}