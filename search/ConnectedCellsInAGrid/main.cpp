#include <iostream>
#include <array>

#define NMax (10)

using namespace std;

typedef array<array<bool, NMax>, NMax> Grid;

int dfs(const Grid &grid, Grid &visited, int n, int m, int r, int c) {
    if (!grid[r][c])
        return 0;
    if (visited[r][c])
        return 0;
    visited[r][c] = true;
    int acc = 1;
    for (int dr = -1; dr <= 1; ++dr)
        for (int dc = -1; dc <= 1; ++dc)
            if (abs(dr) + abs(dc) != 0) {
                int new_r = r + dr, new_c = c + dc;
                if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m)
                    if (grid[new_r][new_c] && !visited[new_r][new_c])
                        acc += dfs(grid, visited, n, m, new_r, new_c);
            }
    return acc;
}


int main() {
    int n, m;
    Grid grid, visited;
    cin >> n >> m;
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; ++c)
            grid[r][c] = visited[r][c] = false;

    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; ++c) {
            int flag;
            cin >> flag;
            grid[r][c] = flag == 1;
        }

    int ans = -1;
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; ++c)
            if (!visited[r][c] && grid[r][c])
                ans = max(ans, dfs(grid, visited, n, m, r, c));
    cout << ans << endl;
    return 0;
}