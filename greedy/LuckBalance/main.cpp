#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<bool, int>> contests(n);
    int total = 0, n_imp = 0;
    for (int i =  0; i < n; ++i) {
        int l, t;
        cin >> l >> t;
        contests[i] = make_pair(t == 0, l);
        total += l;
        n_imp += t;
    }
    sort(contests.begin(), contests.end());
    for (int i = 0; i < n_imp - k && !contests[i].first; ++i) {
        //cout << contests[i].first << " " << contests[i].second << endl;
        total -= 2 * contests[i].second;
    }
    cout << total << endl;
    return 0;
}