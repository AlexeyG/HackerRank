#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <limits>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());
    std::set<std::pair<int, int>> found;
    long long min_diff = std::numeric_limits<long long>::max();
    for (int i = 0; i < n - 1; ++i) {
        int cur_diff = a[i + 1] - a[i];
        if (cur_diff < 0)
            cur_diff = -cur_diff;
        if (cur_diff < min_diff) {
            found.clear();
            min_diff = cur_diff;
            found.emplace(a[i], a[i + 1]);
        } else if (cur_diff == min_diff)
            found.emplace(a[i], a[i + 1]);
    }
    for (auto p : found)
        std::cout << p.first << " " << p.second << " ";
    std::cout << std::endl;
    return 0;
}
