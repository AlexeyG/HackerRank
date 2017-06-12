#include <iostream>

int main() {
    unsigned long long n, p = 1;
    int cnt = 0;
    std::cin >> n;
    while (p <= n)
        cnt += (p & n) == 0, p <<= 1;
    std::cout << (1ULL << cnt);
    return 0;
}