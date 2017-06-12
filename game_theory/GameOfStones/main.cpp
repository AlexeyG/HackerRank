#include <iostream>
#include <array>

#define NMax (101)

std::array<int, 3> steps = {2, 3, 5};
std::array<int, NMax> mem;

bool can_win(int n) {
    if (mem[n] >= 0)
        return mem[n] == 1;

    for (auto it = steps.begin(); it != steps.end(); ++it)
        if ((n >= *it) && (can_win(n - *it) == false)) {
            mem[n] = 1;
            return true;
        }
    mem[n] = 0;
    return false;
}

int main() {
    mem.fill(-1);
    mem[0] = mem[1] = 0;
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::cout << ((can_win(n)) ? "First" : "Second") << std::endl;
    }
    return 0;
}