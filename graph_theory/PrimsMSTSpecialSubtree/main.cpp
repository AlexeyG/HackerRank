#include <iostream>
#include <tuple>
#include <queue>

using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> selected(n, false);
    vector<vector<tuple<int, int, int>>> edges(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        // build graph
        --u, --v;
        auto edgeUV = make_tuple(w, u, v);
        auto edgeVU = make_tuple(w, v, u);
        edges[u].push_back(edgeUV);
        edges[v].push_back(edgeVU);
    }
    int s;
    cin >> s;
    --s;

    // init priority queue
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    selected[s] = true;
    for (auto e : edges[s])
        q.push(e);

    long long acc = 0;
    while (!q.empty()) {
        int w, u, v;
        tie(w, u, v) = q.top();
        q.pop();

        if (selected[v])
            continue;

        selected[v] = true;
        acc += w;
        for (auto e : edges[v])
            q.push(e);
    }

    cout << acc << endl;
    return 0;
}