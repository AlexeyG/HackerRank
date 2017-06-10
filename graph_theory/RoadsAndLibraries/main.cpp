#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>

typedef std::vector<std::vector<int>> adjListT;
typedef std::vector<std::vector<int>> ccT;

ccT get_connected_components(const adjListT &edges, int n) {
    std::vector<std::vector<int>> CCs;
    std::vector<bool> visited(n, false);
    for (int u = 0; u < n; ++u)
        if (!visited[u]) {
            std::vector<int> cur_cc;
            std::stack<int> st({u});
            while (!st.empty()) {
                int v = st.top();
                st.pop();
                if (visited[v])
                    continue;
                visited[v] = true;
                cur_cc.push_back(v);
                for (auto w = edges[v].begin(); w != edges[v].end(); ++w)
                    if (!visited[*w])
                        st.push(*w);
            }
            CCs.push_back(cur_cc);
        }
    return std::move(CCs);
}

long calculate_cost(const adjListT &edges, int n, int cost_road, int cost_lib) {
    if (cost_lib <= cost_road)
        return (long)n * (long)cost_lib;
    ccT conn_comp = get_connected_components(edges, n);
    long cost = 0;
    for (auto it = conn_comp.begin(); it != conn_comp.end(); ++it)
        cost += cost_lib + (long) (it->size() - 1) * (long) cost_road;
    return cost;
}

int main() {
    int q;
    std::cin >> q;
    while (q--) {
        int n, m, c_road, c_lib;
        std::cin >> n >> m >> c_lib >> c_road;
        adjListT edges(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        std::cout << calculate_cost(edges, n, c_road, c_lib) << std::endl;
    }
    return 0;
}
