#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <tuple>

#define INF (numeric_limits<long long>::max())

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> prio(n, INF);
    vector<vector<pair<int, long long>>> g(n, vector<pair<int, long long>>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        --u, --v;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }

    // dijkstra
    prio[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.emplace(0, 0);

    while (!q.empty()) {
        int u;
        long long prio_u;
        tie(prio_u, u) = q.top();
        q.pop();
        if (prio[u] != prio_u)
            continue;

        for (auto e : g[u]) {
            int v;
            long long c;
            tie(v, c) = e;
            if (max(prio_u, c) < prio[v]) {
                prio[v] = max(prio_u, c);
                q.emplace(prio[v], v);
            }
        }
    }
    if (prio[n - 1] == INF)
        cout << "NO PATH EXISTS" << endl;
    else
        cout << prio[n - 1] << endl;
    return 0;
}