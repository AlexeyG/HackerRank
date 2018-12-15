#include <iostream>
#include <set>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int n, k;
    int row_start, col_start;
    cin >> n >> k >> row_start >> col_start;
    --row_start, --col_start;
    set<pair<int, int>> blocked;
    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        blocked.insert(make_pair(--r, --c));
    }

    int cnt = 0;
    queue<tuple<int, int, int, int>> q;
    for (auto dr : {-1, 0, +1})
        for (auto dc : {-1, 0, +1})
            if (abs(dr) + abs(dc) != 0)
                q.push(make_tuple(row_start + dr, col_start + dc, dr, dc));
    while (!q.empty()) {
        int r, c, dr, dc;
        tie(r, c, dr, dc) = q.front();
        q.pop();

        if (r >= 0 && r < n && c >= 0 && c < n && blocked.find(make_pair(r, c)) == blocked.end()) {
            ++cnt;
            q.push(make_tuple(r + dr, c + dc, dr, dc));
        }
    }
    cout << cnt << endl;
    return 0;
}