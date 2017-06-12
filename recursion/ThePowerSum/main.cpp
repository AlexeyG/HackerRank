#include <iostream>
#include <cmath>

long long count(int x, int n, int last) {
    if (x == 0)
        return 1;
    long long total = 0;
    int i = last + 1, i_pow;
    while ((i_pow = std::pow(i, n)) <= x) {
        total += count(x - i_pow, n, i);
        ++i;
    }
    return total;
}

int main() {
    int x, n;
    std::cin >> x >> n;
    std::cout << count(x, n, 0) << std::endl;
    return 0;
}