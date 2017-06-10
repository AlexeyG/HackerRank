#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

int countStations(const std::vector<int> &x, const int k) {
    int l = 0, pos = 0, cnt = 1;
    for (int i = 1; i < x.size(); ++i) {
        while (pos + 1 <= i && x[pos + 1] - x[l] <= k)
            ++pos;
        if (x[i] - x[pos] > k) {
            ++cnt;
            l = i;
        }
    }
    return cnt;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> x(n);
    for (int i = 0; i < n; ++i)
        std::cin >> x[i];
    std::sort(x.begin(), x.end());
    std::cout << countStations(x, k) << std::endl;
    return 0;
}
