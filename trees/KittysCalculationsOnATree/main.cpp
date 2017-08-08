#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

#define MODULO (1000000007L)

std::vector<std::vector<int>> adj;
std::vector<int> color;
std::vector<int> ancestor, parent, rank, depth;

void make_set(int u) {
    parent[u] = u;
    rank[u] = 0;
}

int find_set(int u) {
    if (parent[u] != u)
        parent[u] = find_set(parent[u]);
    return parent[u];
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[v] = rank[u] + 1;
    }
}

long dfs(int u, int d, std::set<int> &elems) {
    long acc = 0L;
    make_set(u);
    color[u] = 1, ancestor[u] = u, depth[u] = d;
    for (auto v : adj[u])
        if (color[v] == 0) {
            acc = (acc + dfs(v, d + 1, elems)) % MODULO;
            union_set(u, v);
            ancestor[find_set(u)] = u;
        }
    color[u] = 2;
    if (elems.find(u) != elems.end()) {
        for (auto v : elems)
            if (color[v] == 2) {
                long dist = depth[u] + depth[v] - 2 * depth[ancestor[find_set(v)]];
                //std::cout << "(" << u << ", " << v << ") : " << ancestor[find_set(v)] << " and " << dist << " -> "
                //          << (dist * (u + 1) * (v + 1)) << std::endl;
                acc = (acc + dist * (u + 1) * (v + 1)) % MODULO;
            }
    }
    return acc;
}

int main() {
    int n, q;
    std::cin >> n >> q;
    adj.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        std::cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    color.resize(n);
    parent.resize(n);
    ancestor.resize(n);
    rank.resize(n);
    depth.resize(n);
    while (q--) {
        int k;
        std::cin >> k;
        std::set<int> elems;
        while (k--) {
            int elem;
            std::cin >> elem;
            elems.insert(--elem);
        }
        std::fill(color.begin(), color.end(), 0);
        std::fill(parent.begin(), parent.end(), -1);
        std::fill(ancestor.begin(), ancestor.end(), -1);

        //std::cout << "elems: ";
        //for (auto v : elems)
        //    std::cout << v << " ";
        //std::cout << std::endl;

        std::cout << dfs(rand() % n, 0, elems) << std::endl;
    }
    return 0;
}