#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>

using namespace std;

int get_parent(int u, vector<int> &parent) {
    if (parent[u] != u)
        parent[u] = get_parent(parent[u], parent);
    return parent[u];
}

long long get_size(int u, vector<int> &parent, const vector<long long> &size) {
    return size[get_parent(u, parent)];
}

void merge(int u, int v, vector<int> &parent, vector<int> &rank, vector<long long> &size) {
    u = get_parent(u, parent), v = get_parent(v, parent);
    if (rank[u] < rank[v]) {
        size[v] += get_size(u, parent, size);
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        size[u] += get_size(v, parent, size);
        parent[v] = u;
    } else {
        size[v] += get_size(u, parent, size);
        parent[u] = v;
        ++rank[v];
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<tuple<int, int, int>> edges;
    edges.reserve(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.emplace_back(w, u, v);
    }

    // Setup disjiont set data structure
    vector<int> parent(n), rank(n, 1);
    vector<long long> size(n, 1);
    for (int i = 0; i < n; ++i)
        parent[i] = i;

    // Find all paths
    sort(edges.begin(), edges.end());
    map<int, long long> counts;
    for (auto e : edges) {
        int w, u, v;
        tie(w, u, v) = e;
        if (get_parent(u, parent) != get_parent(v, parent)) {
            if (counts.find(w) == counts.end())
                counts[w] = 0LL;
            counts[w] = counts[w] + get_size(u, parent, size) * get_size(v, parent, size);
            merge(u, v, parent, rank, size);
        }
    }

    long long acc = 0LL;
    for (auto it = counts.begin(); it != counts.end(); ++it) {
        acc += it->second;
        it->second = acc;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        auto left = counts.lower_bound(l);
        auto right = counts.upper_bound(r);
        long long left_value = (left == counts.begin() ? 0 : (--left)->second);
        long long right_value = (--right)->second;
        long long cnt = right_value - left_value;
        cout << cnt << endl;
    }

    return 0;
}