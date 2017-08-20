#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>

int main() {
    int n, m;
    int l, r;
    std::set<int> ends;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> segments(n), queries(m);


    for (int i = 0; i < n; ++i) {
        std::cin >> l >> r;
        segments[i].first = --l;
        segments[i].second = r;
        ends.insert(l);
        ends.insert(r);
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> l >> r;
        queries[i].first = --l, queries[i].second = --r;
        ends.insert(l);
        ends.insert(r);
    }

    std::unordered_map<int, int> compress;
    int ind = 0;
    for (auto it = ends.begin(); it != ends.end(); ++it)
        compress[*it] = ind++;

    std::vector<int> start(ind + 1, 0), stop(ind + 1, 0);
    for (int i = 0; i < n; ++i) {
        ++start[compress[segments[i].first]];
        ++stop[compress[segments[i].second]];
    }


    for (int i = 1; i <= ind; ++i) {
        start[i] += start[i - 1];
        stop[i] += stop[i - 1];
    }
    long long ans = 0;
    for (int i = 0; i < m; ++i)
        ans += start[compress[queries[i].second]] - stop[compress[queries[i].first]];
    std::cout << ans << std::endl;
    return 0;
}
