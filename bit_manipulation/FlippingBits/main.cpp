#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        unsigned int n;
        std::cin >> n;
        std::cout << (n ^ ((1LL << 32) - 1)) << std::endl;
    }
    return 0;
}