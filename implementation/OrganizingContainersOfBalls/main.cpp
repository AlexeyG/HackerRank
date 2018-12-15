#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> row_acc(n, 0), col_acc(n, 0);
        for (int r = 0; r < n; ++r) {
            int cur_row = 0;
            for (int c = 0; c < n; ++c) {
                int num;
                cin >> num;
                cur_row += num;
                col_acc[c] += num;
            }
            row_acc[r] = cur_row;
        }
        sort(row_acc.begin(), row_acc.end());
        sort(col_acc.begin(), col_acc.end());
        cout << ((row_acc == col_acc) ? "Possible" : "Impossible") << endl;
    }
    return 0;
}