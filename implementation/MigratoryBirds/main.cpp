#include <array>
#include <iostream>
#include <algorithm>

#define NMax (5)

int main() {
    std::array<int, NMax> count;
    for (int i = 0; i < NMax; ++i)
        count[i] = 0;
    int n, max_t = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        std::cin >> t;
        ++count[--t];
        if ((count[t] > count[max_t]) || ((count[t] == count[max_t]) && (t < max_t)))
            max_t = t;
    }
    std::cout << (max_t + 1) << std::endl;
    return 0;
}
