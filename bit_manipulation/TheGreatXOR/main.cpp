#include <iostream>

long long count(long long n) {
    int i = 0;
    unsigned long long ans = 0;
    while (n > 0) {
        if ((n & 1LL) == 0)
            ans += 1LL << i;
        n >>= 1;
        ++i;
    }
    return ans;
};

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        std::cout << count(n) << std::endl;
    }
    return 0;
}
