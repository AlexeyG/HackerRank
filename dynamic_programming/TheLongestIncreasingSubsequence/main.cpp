#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<pair<int, int>> prev;      // set of (last element, seq length)
    int overall_max = 0;
    vector<int> dp(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        int l = 0, r = overall_max + 1;
        //cout << "at " << i << endl;
        while (r - l > 1) {
            int m = (r + l) / 2;
            //cout << "   l = " << l << " r = " << r << " m = " << m << endl;
            if (dp[m] >= a)
                r = m;
            else
                l = m;
        }
        int j = l;
        //cout << "   j = " << j << "  dp[j] = " << dp[j] << " dp[j + 1] = " << dp[j + 1] << endl;
        if (dp[j + 1] > a || dp[j + 1] == -1)
            dp[j + 1] = a;
        overall_max = max(overall_max, j + 1);
    }
    cout << overall_max << endl;
    return 0;
}