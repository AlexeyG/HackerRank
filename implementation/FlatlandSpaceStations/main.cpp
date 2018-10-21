#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ind(m);
    for (int i=0; i<m; ++i)
        cin >> ind[i];
    sort(ind.begin(), ind.end());

    int prev = -1, cur, max_dist = *ind.begin();
    for (int i=0; i<m; ++i) {
        cur = ind[i];
        if (prev >= 0)
            max_dist = max(max_dist, (cur - prev - 1) / 2 + (cur - prev - 1) % 2);
        else
            max_dist = max(max_dist, prev);
        prev = cur;
    }
    max_dist = max(max_dist, (n - 1) - prev);
    cout << max_dist << endl;
    return 0;
}