#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <array>

#define NMax (100000 + 1)

std::array<long long, NMax> lb_mem;

long long ub(int len) {
    return (long long) (len) * (len - 1LL) / 2LL;
}

long long lb(int len) {
    if (lb_mem[len] < 0)
        lb_mem[len] = len - 1LL + lb(len / 2) + lb(len - (len / 2) - 1);
    return lb_mem[len];
}

bool array_exists(int len, int comp) {
    return comp >= lb(len) && comp <= ub(len);
}

void print_array(int len, int comp, int shift) {
    if (len == 0)
        return;
    if (len == 1) {
        std::cout << shift + 1 << " ";
        return;
    }
    comp -= len - 1;
    if (comp >= lb(len - 1) && comp <= ub(len - 1)) {
        //std::cout << "(going " << len << " -> " << len - 1 << " | " << lb(len - 1) << " <= " << comp << " <= " << ub(len - 1) << ")";
        std::cout << shift + len << " ";
        print_array(len - 1, comp, shift);
        return;
    }
    int l = 0, r = (len - 1) / 2 + 1;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (lb(m) + lb(len - m - 1) <= comp)
            r = m;
        else
            l = m;
    }
    std::cout << r + shift + 1 << " ";
    print_array(r, lb(r), shift);
    print_array(len - r - 1, comp - lb(r), shift + r + 1);
}

int main() {
    lb_mem.fill(-1);
    lb_mem[0] = lb_mem[1] = 0LL;

    int t;
    std::cin >> t;
    while (t--) {
        int len, comp;
        std::cin >> len >> comp;
        if (!array_exists(len, comp))
            std::cout << -1;
        else
            print_array(len, comp, 0);
        std::cout << std::endl;
    }
    return 0;
}