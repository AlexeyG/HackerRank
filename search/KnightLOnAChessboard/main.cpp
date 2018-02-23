#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n, int d_row, int d_col) {
    vector<vector<int>> time(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    time[0][0] = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int row = cur.first, col = cur.second;
        if (row == n - 1 && col == n - 1)
            break;
        for (int s_row = -1; s_row <= 1; s_row += 2)
            for (int s_col = -1; s_col <= 1; s_col += 2) {
                int new_row = row + d_row * s_row, new_col = col + d_col * s_col;
                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < n)
                    if (time[new_row][new_col] < 0) {
                        time[new_row][new_col] = time[row][col] + 1;
                        q.push(make_pair(new_row, new_col));
                    }

                new_row = row + d_col * s_row, new_col = col + d_row * s_col;
                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < n)
                    if (time[new_row][new_col] < 0) {
                        time[new_row][new_col] = time[row][col] + 1;
                        q.push(make_pair(new_row, new_col));
                    }
            }
    }
    return time[n - 1][n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> ans(n - 1, vector<int>(n - 1, 0));
    for (int i = 0; i < n - 1; ++i)
        for (int j = i; j < n - 1; ++j) {
            int dist = bfs(n, i + 1, j + 1);
            ans[i][j] = ans[j][i] = dist;
        }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}