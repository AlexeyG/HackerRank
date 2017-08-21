#include <vector>
#include <iostream>
#include <queue>

typedef std::vector<std::vector<int>> AdjM;

void bfs(int s, const AdjM &adj, std::vector<int> &time) {
    int n = adj.size();
    time.resize(n);
    std::fill(time.begin(), time.end(), -1);
    std::queue<int> q;
    q.push(s);

    time[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
            if (time[v] == -1) {
                time[v] = time[u] + 1;
                q.push(v);
            }
    }
};

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        AdjM adj(n, std::vector<int>());
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int s;
        std::cin >> s;
        --s;
        std::vector<int> time;
        bfs(s, adj, time);

        for (int u = 0; u < n; ++u)
            if (u != s)
                std::cout << ((time[u] >= 0) ? time[u] * 6 : time[u]) << " ";
        std::cout << std::endl;
    }
    return 0;
}
