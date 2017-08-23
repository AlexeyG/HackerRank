#include <vector>
#include <iostream>
#include <limits>

#define max(a, b) ((a > b) ? a : b)

long long max_non_cont(const std::vector<int> &a) {
    bool seen_positive = false;
    long long sum = 0;
    long long max_elem = a[0];
    for (int i = 0; i < a.size(); ++i) {
        max_elem = max(max_elem, a[i]);
        if (a[i] > 0) {
            seen_positive = true;
            sum += a[i];
        }
    }
    if (seen_positive)
        return max(sum, max_elem);
    return max_elem;
}

long long max_cont(const std::vector<int> &a) {
    long long max_so_far = std::numeric_limits<long long>::min();
    long long acc = 0;
    for (int i = 0; i < a.size(); ++i) {
        acc += a[i];
        max_so_far = max(max_so_far, acc);
        if (acc < 0)
            acc = 0;
    }
    return max_so_far;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        std::cout << max_cont(a) << " " << max_non_cont(a) << std::endl;
    }
    return 0;
}
