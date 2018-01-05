#include <vector>
#include <iostream>

#define NMax (32)

std::vector<bool> get_bits(long a) {
    std::vector<bool> bits(NMax);
    for (int i = 0; i < NMax; ++i)
        bits[i] = (a & (1 << i)) > 0;
    return bits;
}

long solve(const std::vector<bool> &a, const std::vector<bool>& b) {
    int i = NMax - 1;
    long ans = 0;
    while (i >= 0 && a[i] == b[i]) {
        ans = (ans << 1) + (int)a[i];
        --i;
    }
    ans <<= (i + 1);
    return ans;
}

int main() {
    long a, b;
    int n;
    std::cin >> n;
    while (n--) {
        std::cin >> a >> b;
        auto a_bits = get_bits(a), b_bits = get_bits(b);
        std::cout << solve(a_bits, b_bits) << std::endl;
    }

    return 0;
}
