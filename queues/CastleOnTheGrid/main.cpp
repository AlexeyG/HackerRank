#include <iostream>
#include <string>
#include <vector>
#include <queue>

typedef std::vector<std::vector<bool>> boardT;
typedef std::pair<int, int> pointT;

int solve(const boardT& allowed, const pointT& start, const pointT& finish) {
    std::queue<pointT> q;
    q.push(start);

    int n = allowed.size();
    std::vector<std::vector<int>> time(n, std::vector<int>(n, -1));
    time[start.first][start.second] = 0;

    while (!q.empty() && time[finish.first][finish.second] == -1) {
        pointT cur = (pointT) q.front();
        q.pop();
        //std::cout << "row = " << cur.first << " col = " << cur.second << std::endl;
        for (int i = cur.first + 1; i < n; ++i) {
            if (!allowed[i][cur.second])
                break;
            if (time[i][cur.second] == -1) {
                q.emplace(i, cur.second);
                time[i][cur.second] = time[cur.first][cur.second] + 1;
            }
        }
        for (int i = cur.first - 1; i >= 0; --i) {
            if (!allowed[i][cur.second])
                break;
            if (time[i][cur.second] == -1) {
                q.emplace(i, cur.second);
                time[i][cur.second] = time[cur.first][cur.second] + 1;
            }
        }
        for (int i = cur.second + 1; i < n; ++i) {
            if (!allowed[cur.first][i])
                break;
            if (time[cur.first][i] == -1) {
                q.emplace(cur.first, i);
                time[cur.first][i] = time[cur.first][cur.second] + 1;
            }
        }
        for (int i = cur.second - 1; i >= 0; --i) {
            if (!allowed[cur.first][i])
                break;
            if (time[cur.first][i] == -1) {
                q.emplace(cur.first, i);
                time[cur.first][i] = time[cur.first][cur.second] + 1;
            }
        }
    }
    return time[finish.first][finish.second];
}

int main() {
    int n;
    std::cin >> n;
    boardT allowed(n, std::vector<bool>(n, false));
    for (int row = 0; row < n; ++row) {
        std::string line;
        std::cin >> line;
        for (int col = 0; col < n; ++col)
            allowed[row][col] = (line[col] == '.');
    }
    int s_row, s_col, f_row, f_col;
    std::cin >> s_row >> s_col >> f_row >> f_col;
    std::cout << solve(allowed, std::make_pair(s_row, s_col), std::make_pair(f_row, f_col)) << std::endl;
    return 0;
}