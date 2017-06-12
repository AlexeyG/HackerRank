#include <iostream>
#include <vector>
#include <algorithm>

unsigned long long count(const int m, const std::vector<int> &c) {
    std::vector<unsigned long long> counts(m + 1, 0);
    counts[0] = 1;
    for (int j = 0; j < c.size(); ++j)    // allowed coin
        for (int i = 1; i <= m; ++i)      // target sum
            if (i - c[j] >= 0)
                counts[i] += counts[i - c[j]];
    return counts[m];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> c(m);
    for (int i = 0; i < m; ++i)
        std::cin >> c[i];
    std::cout << count(n, c) << std::endl;
    return 0;
}