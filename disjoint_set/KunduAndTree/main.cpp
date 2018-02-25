#include <iostream>
#include <vector>

#define MOD  (1000000007LL)
#define INV2 (500000004LL)
#define INV6 (166666668LL)

using namespace std;

int get_parent(int u, vector<int> &parent) {
    if (parent[u] != u)
        parent[u] = get_parent(parent[u], parent);
    return parent[u];
}

void merge(int u,
           int v,
           vector<int> &parent,
           vector<int> &rank,
           vector<long long> &size) {
    u = get_parent(u, parent), v = get_parent(v, parent);
    if (rank[u] < rank[v]) {
        parent[u] = v;
        size[v] += size[u];
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
        size[u] += size[v];
    } else {
        parent[u] = v;
        ++rank[v];
        size[v] += size[u];
    }
}

long long mul(long long a, long long b) {
    a %= MOD, b %= MOD;
    return (a * b) % MOD;
}

int main() {
    int n;
    cin >> n;

    vector<int> parent(n), rank(n, 0);
    vector<long long> size(n, 1);
    for (int i = 0; i < n; ++i)
        parent[i] = i;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        char col;
        cin >> u >> v >> col;
        if (col == 'b')
            merge(--u,
                  --v,
                  parent,
                  rank,
                  size);
    }

    long long acc = 0;
    for (int i = 0; i < n; ++i)
        if (parent[i] == i)
            acc = (acc + mul(mul(size[i], mul(size[i] - 1, size[i] - 2)), INV6) +
                         mul(mul(size[i], mul((size[i] - 1), (n - size[i]))), INV2)
                  ) % MOD;
    long long total = mul(mul(n, mul(n - 1, n - 2)), INV6);
    acc = (total - acc + MOD) % MOD;
    cout << acc << endl;

    return 0;
}