#include <iostream>
#include <string>
#include <vector>

#define NMax (26 + 1)

using namespace std;

int main() {
    int t;
    string line;
    cin >> t;
    while (t--) {
        vector<int> cnt(NMax, 0);
        vector<int> prev(NMax, -1);
        int len;
        cin >> len;
        cin >> line;
        bool is_ordered = true;
        for (int pos = 0; pos < len; ++pos) {
            int ind = (line[pos] == '_' ? 0 : line[pos] - 'A' + 1);
            ++cnt[ind];
            is_ordered &= (prev[ind] < 0 || pos == prev[ind] + 1);
            prev[ind] = pos;
        }
        bool has_spaces = cnt[0] > 0;
        bool has_singletons = false;
        for (int i = 1; i < NMax; ++i)
            has_singletons |= (cnt[i] == 1);
        cout << (!has_singletons && (has_spaces || is_ordered) ? "YES" : "NO") << endl;
    }
    return 0;
}