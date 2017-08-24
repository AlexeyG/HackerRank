#include <vector>
#include <iostream>


int main() {
    int n, k, ck;
    long long sum = 0;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int c;
        std::cin >> c;
        sum += c;
        if (i == k)
            ck = c;
    }
    long long b;
    std::cin >> b;
    if (b == (sum - ck) / 2 && (sum - ck) % 2 == 0)
        std::cout << "Bon Appetit" << std::endl;
    else
        std::cout << (b - (sum - ck) / 2) << std::endl;
    return 0;
}
