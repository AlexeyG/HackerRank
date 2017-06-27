#include <iostream>
#include <vector>
#include <unordered_set>

#define MODULO (1000000007L)

std::vector<int> parent;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;
std::vector<int> depth;

void dfs(int u, int p, int d) {
    visited[u] = true;
    parent[u] = p;
    depth[u] = d;
    for (auto v : adj[u])
        if (!visited[v])
            dfs(v, u, d + 1);
}

int get_lca(int u, int v) {
    std::unordered_set<int> on_path;
    while (u >= 0)
        on_path.insert(u), u = parent[u];
    while (v >= 0 && on_path.find(v) == on_path.end())
        v = parent[v];
    return v;
}

int get_dist(int u, int v) {
    int lca = get_lca(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
}

long get_expression(std::vector<int> &elems) {
    int n = elems.size();
    long acc = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            acc = (acc + (elems[i] + 1) * (elems[j] + 1) * get_dist(elems[i], elems[j])) % MODULO;
    return acc;
}

int main() {
    int n, q;
    std::cin >> n >> q;
    parent.resize(n);
    adj.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        std::cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited.resize(n);
    depth.resize(n);
    std::fill(visited.begin(), visited.end(), false);
    std::fill(depth.begin(), depth.end(), false);
    dfs(rand() % n, -1, 0);
    while (q--) {
        int k;
        std::cin >> k;
        std::vector<int> elems(k);
        while (k--) {
            std::cin >> elems[k];
            elems[k]--;
        }
        std::cout << get_expression(elems) << std::endl;
    }
    return 0;
}