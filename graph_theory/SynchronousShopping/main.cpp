// Hacker Rank: Algorithms / Graph Theory / Synchronous Shopping
// https://www.hackerrank.com/challenges/synchronous-shopping

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <bitset>

typedef std::pair<int, int> edgeT;
typedef std::vector<std::vector<edgeT>> adjListT;
typedef std::tuple<int, int, int> nodeWeightT;        // (shop, flags, weight)

#define BIT_MAX (1 << 10)
#define INT_INF (100000000)

int solve(const std::vector<int> &types, const adjListT &edges, const int n_types) {
    // Find shortest path in a graph, where each node is (shop, types of fish seen)
    std::vector<std::vector<int>> dist(types.size(), std::vector<int>(BIT_MAX, INT_INF));
    auto isLonger = [](const nodeWeightT &a, const nodeWeightT &b) -> bool { return std::get<2>(a) > std::get<2>(b); };
    std::priority_queue<nodeWeightT, std::vector<nodeWeightT>, decltype(isLonger)> q(isLonger);

    q.emplace(0, types[0], 0);
    while (!q.empty()) {
        int u, flags, weight;
        std::tie(u, flags, weight) = q.top();
        q.pop();
        if (dist[u][flags] > weight) {
            dist[u][flags] = weight;
            for (auto it = edges[u].begin(); it != edges[u].end(); ++it) {
                q.emplace(it->first, flags | types[it->first], weight + it->second);
            }
        }
    }

    int time = INT_INF, last_shop = types.size() - 1;
    for (int i = 0; i < BIT_MAX; ++i)
        for (int j = 0; j < BIT_MAX; ++j)
            if ((i | j) == ((1 << n_types) - 1))
                time = std::min(time, std::max(dist[last_shop][i], dist[last_shop][j]));
    return time;
}

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> types(n);
    for (int i = 0; i < n; ++i) {
        int t, a, flags = 0;
        std::cin >> t;
        while (t--) {
            std::cin >> a;
            flags |= 1 << (--a);
        }
        types[i] = flags;
    }
    adjListT edges(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u, --v;
        edges[u].emplace_back(v, w);
        edges[v].emplace_back(u, w);
    }
    std::cout << solve(types, edges, k) << std::endl;
    return 0;
}