#include <iostream>
#include <vector>

using namespace std;

long long solve(const vector<int> &price) {
    int n = price.size();
    int j = n - 1;
    long long ans = 0LL;
    for (int i = n - 2; i >= 0; --i) {
        if (price[i] < price[j])
            ans += price[j] - price[i];
        else
            j = i;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
         int n;
         cin >> n;
         vector<int> p(n);
         for (int i = 0; i < n; ++i)
             cin >> p[i];
        cout << solve(p) << endl;
    }
    return 0;
}