#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <cstring>

#define MODULO (1000000)
#define PADW (6)


#define L (100)

class bint {
public:
    bint(long long x) {
        len = -1;
        std::memset(arr, L, 0);
        while (x > 0)
            arr[++len] = x % MODULO, x /= MODULO;
    }

    bint &operator+= (const bint &other) {
        len = std::max(len, other.len);
        int carry = 0;
        for (int i = 0; i <= len || carry > 0; ++i) {
            arr[i] += other.arr[i] + carry;
            carry = arr[i] / MODULO;
            arr[i] %= MODULO;
            len = std::max(len, i);
        }
        return *this;
    }

private:
    int arr[L];
    int len;

    friend std::ostream &operator<< (std::ostream &stream, const bint &other) {
        stream << std::setw(0) << other.arr[other.len];
        for (int i = other.len - 1; i >= 0 ; --i)
            stream << std::setfill('0') << std::setw(PADW) << other.arr[i];
        return stream;
    }
};

bint solve(std::vector<int> &c) {
    std::sort(c.begin(), c.end(), std::greater<int>());
    bint cost(0);
    long long pow = 1;
    for (auto it = c.begin(); it != c.end(); ++it)
        cost += bint((*it) * pow), pow *= 2;
    return cost;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> c(n);
    while (n--)
        std::cin >> c[n];
    std::cout << solve(c) << std::endl;

    //std::cout << bint(11) << std::endl << bint(123) << std::endl << bint(1313147671863) << std::endl;

    return 0;
}