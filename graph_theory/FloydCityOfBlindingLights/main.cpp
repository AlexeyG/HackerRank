#include <cmath>
#include <vector>
#include <iostream>

#define DMax (10000)

int main() {
    int n, m;
    std::cin >> n >> m;

    // prepare graph
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, DMax));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u, --v;
        dist[u][v] = w;
    }

    // calculate min distance
    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;

    for (int k = 0; k < n; ++k)
        for (int u = 0; u < n; ++u)
            for (int v = 0; v < n; ++v)
                dist[u][v] = std::min(dist[u][v], dist[u][k] + dist[k][v]);

    // answer queries
    int q;
    std::cin >> q;
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        int ans = dist[--u][--v];
        std::cout << ((ans == DMax) ? -1 : ans) << std::endl;
    }
    return 0;
}
