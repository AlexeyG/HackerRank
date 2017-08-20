#include <vector>
#include <iostream>
#include <queue>
#include <limits>

#define DMax (std::numeric_limits<int>::max())

struct Edge {
    int u, v, w;

    Edge(int _u, int _v, int _w)
            : u(_u), v(_v), w(_w) {};
};

struct Vertex {
    int index;
    long dist;

    Vertex(int i, int d)
            : index(i), dist(d) {};

    bool operator< (const Vertex &other) const {
        return dist > other.dist;
    };
};

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;

        // read input
        std::vector<std::vector<Edge>> adj(n, std::vector<Edge>());
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            --u, --v;
            adj[u].push_back(Edge(u, v, w));
            adj[v].push_back(Edge(v, u, w));
        }
        int s;
        std::cin >> s;
        --s;

        // construct priority queue
        std::vector<long> dist(n, DMax);
        dist[s] = 0;
        std::priority_queue<Vertex> q;
        for (int i = 0; i < n; ++i)
            q.push(Vertex(i, dist[i]));

        // do dijkstra
        while (!q.empty()) {
            Vertex cur = q.top();
            q.pop();
            int u = cur.index;

            // outdated entry
            if (cur.dist != dist[u])
                continue;
            for (auto e : adj[u]) {
                int v = e.v, w = e.w;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.push(Vertex(v, dist[v]));
                }
            }
        }

        // print dist
        for (int u = 0; u < n; ++u)
            if (u != s)
                std::cout << ((dist[u] == DMax) ? -1L : dist[u]) << " ";
        std::cout << std::endl;
    }
    return 0;
}
