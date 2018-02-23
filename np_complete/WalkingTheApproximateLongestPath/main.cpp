#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

#define TL (3000)

std::vector<std::vector<int>> adj_list;
std::vector<bool> visited;

unsigned long start_time;

bool should_terminate() {
    return (clock() - start_time) >= TL;
}

void find_longest(int v, std::vector<int> &cur_path, std::vector<int> &max_path) {
    bool can_continue = false;
    for (auto u = adj_list[v].begin(); u != adj_list[v].end(); ++u)
        if (!visited[*u]) {
            if (should_terminate()) break;
            can_continue = true, visited[*u] = true;
            cur_path.push_back(*u);
            find_longest(*u, cur_path, max_path);
            cur_path.pop_back();
            visited[*u] = false;
        }
    if (!can_continue && max_path.size() < cur_path.size())
        max_path = cur_path;
}

std::vector<int> find_longest() {
    std::vector<int> path;
    for (int i = 0; i < visited.size(); ++i) {
        if (should_terminate()) break;
        visited[i] = true;
        std::vector<int> candidate = {i};
        find_longest(i, candidate, path);
        visited[i] = false;
    }
    return std::move(path);
}

int main() {
    start_time = clock();
    int n, m;
    std::cin >> n >> m;
    adj_list.resize(n, std::vector<int>());
    visited.resize(n, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    std::vector<int> path = find_longest();
    std::cout << path.size() << std::endl;
    for (auto it = path.begin(); it != path.end(); ++it)
        std::cout << (*it + 1) << " ";
    return 0;
}