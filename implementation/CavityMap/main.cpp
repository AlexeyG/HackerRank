#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

pair<int, int> deltas[4] = {make_pair(-1, 0), make_pair(+1, 0),
                            make_pair(0, -1), make_pair(0, +1)};

int main() {
    int n;
    cin >> n;
    vector<vector<short>> depth(n, vector<short>(n, -1));
    vector<vector<bool>> is_cavity(n, vector<bool>(n, false));

    string line;
    getline(cin, line);    // read the remainder of the line.
    for (int row=0; row<n; ++row) {
        getline(cin, line);
        //cout << "got " << line << endl;
        int col = 0;
        for (auto ch : line)
            if (ch >= '0' && ch <= '9')
                depth[row][col++] = ch - '0';
    }

    for (int row = 1; row < n - 1; ++row)
        for (int col = 1; col < n - 1; ++col) {
            bool cur_cavity = true;
            for (auto delta : deltas) {
                int drow, dcol;
                tie(drow, dcol) = delta;
                cur_cavity &= (depth[row][col] > depth[row + drow][col + dcol]);
            }
            is_cavity[row][col] = cur_cavity;
        }

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col)
            cout << (is_cavity[row][col] ? "X" : to_string(depth[row][col]));
        cout << endl;
    }

    return 0;
}