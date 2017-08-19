#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

std::vector<int> rank, parent;

void make_set(int i) {
    parent[i] = i;
    rank[i] = 0;
}

int get_parent(int i) {
    if (parent[i] == i)
        return i;
    parent[i] = get_parent(parent[i]);
    return parent[i];
}

void union_set(int i, int j) {
    i = get_parent(i);
    j = get_parent(j);
    if (rank[i] < rank[j])
        parent[i] = j;
    else if (rank[i] > rank[j])
        parent[j] = i;
    else {
        parent[j] = i;
        ++rank[i];
    }
}

std::pair<int, int> get_sizes(int n) {
    std::vector<int> sizes(2 * n, 0);
    for (int i = 0; i < 2 * n; ++i)
        ++sizes[get_parent(i)];
    int all_min = std::numeric_limits<int>::max(), all_max = std::numeric_limits<int>::min();
    for (int i = 0; i < 2 * n; ++i)
        if (sizes[i] > 1) {
            all_min = std::min(all_min, sizes[i]);
            all_max = std::max(all_max, sizes[i]);
        }
    return std::make_pair(all_min, all_max);
}

int main() {
    int n;
    std::cin >> n;
    parent.resize(2 * n);
    rank.resize(2 * n);
    for (int i = 0; i < 2 * n; ++i)
        make_set(i);

    for (int i = 0; i < n; ++i) {
        int g, b;
        std::cin >> g >> b;
        --g, --b;
        union_set(g, b);
    }
    auto ans = get_sizes(n);
    std::cout << ans.first << " " << ans.second << std::endl;
    return 0;
}