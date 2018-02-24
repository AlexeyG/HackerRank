#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <limits>
#include <unordered_set>

using namespace std;

#define NMax (1024)

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edges(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        edges[u].emplace_back(v, c);
        edges[v].emplace_back(u, c);
    }
    int s, f;
    cin >> s >> f;
    --s, --f;

    vector<vector<bool>> can_reach(n, vector<bool>(NMax, false));
    can_reach[s][0] = true;

    queue<pair<int, int>> q;
    q.emplace(s, 0);
    while (!q.empty()) {
        int u, c;
        tie(u, c) = q.front();
        q.pop();

        for (auto e : edges[u]) {
            int v, cv;
            tie(v, cv) = e;
            if (!can_reach[v][c | cv]) {
                can_reach[v][c | cv] = true;
                q.emplace(v, c | cv);
            }
        }
    }

    for (int i = 0; i < NMax; ++i)
        if (can_reach[f][i]) {
            cout << i << endl;
            return 0;
        }

    cout << -1 << endl;
    return 0;
}