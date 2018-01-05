/*
 * Problem:
 * Data Structures / Disjoint Set / Merging Communities
 * https://www.hackerrank.com/challenges/merging-communities/problem
 *
 * Note:
 * Just a plain application of the Union-Find data structure, with an additional size quantity
 * that gets updated with each Union operation.
 * */

#include <iostream>
#include <vector>

using namespace std;

class UnionSet {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    int n;

public:
    UnionSet(int n): n(n), parent(n), rank(n, 0), size(n, 1) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    void merge(int u, int v) {
        u = get_parent(u);
        v = get_parent(v);
        if (u == v)
            return;

        if (rank[u] < rank[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
            size[u] += size[v];
        }
        else {
            parent[u] = v;
            rank[u] = rank[u] + 1;
            size[v] += size[u];
        }
    }

    int get_size(int u) {
        u = get_parent(u);
        return size[u];
    }

    int get_parent(int u) {
        if (parent[u] == u)
            return u;
        parent[u] = get_parent(parent[u]);
        return parent[u];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionSet us(n);
    for (int i = 0; i < q; ++i) {
        char cmd;
        int u, v;
        cin >> cmd;
        switch (cmd) {
            case 'M':
                cin >> u >> v;
                us.merge(--u, --v);
                break;
            case 'Q':
                cin >> u;
                cout << us.get_size(--u) << endl;
                break;
        }
    }
    return 0;
}