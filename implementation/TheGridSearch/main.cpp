#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool match(const vector<vector<short>> &G, const vector<vector<short>> &P, int offset_r, int offset_c) {
    for (int r = 0; r < P.size(); ++r)
        for (int c = 0; c < P[0].size(); ++c)
            if (G[offset_r + r][offset_c + c] != P[r][c])
                return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<short>> G(R, vector<short>(C, 0));
        for (int RR = 0; RR < R; ++RR) {
            string str;
            cin >> str;
            for (int CC = 0; CC < C; ++CC)
                G[RR][CC] = str[CC] - '0';
        }

        int r, c;
        cin >> r >> c;
        vector<vector<short>> P(r, vector<short>(c, 0));
        for (int rr = 0; rr < r; ++rr) {
            string str;
            cin >> str;
            for (int cc = 0; cc < c; ++cc)
                P[rr][cc] = str[cc] - '0';
        }

        bool found = false;
        for (int offset_r = 0; offset_r <= R - r && !found; ++offset_r)
            for (int offset_c = 0; offset_c <= C - c && !found; ++offset_c)
                if (match(G, P, offset_r, offset_c))
                    found = true;
        cout << (found ? "YES" : "NO") << endl;
    }
    return 0;
}