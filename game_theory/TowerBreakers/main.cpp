#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::cout << (((m > 1) && (n & 1)) ? 1 : 2) << std::endl;
    }
    return 0;
}