#include <iostream>

bool simulate(unsigned long long n) {
    bool wasLouise = false;
    //int steps = 0;
    while (true) {
        //++steps;
        //std::cout << "step " << steps << " : " << n << std::endl;
        if (n == 1)
            break;
        wasLouise = !wasLouise;
        if ((n & (n - 1)) == 0)
            n >>= 1;
        else {
            unsigned long long m = n;
            while ((m & (m - 1)) != 0)
                m &= m - 1;
            n ^= m;
        }
    }
    return wasLouise;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        unsigned long long n;
        std::cin >> n;
        std::cout << (simulate(n) ? "Louise" : "Richard") << std::endl;
    }
    return 0;
}