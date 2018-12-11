#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        bool ok = true;
        for (int i = 0; i < n && ok; ++i)
            ok &= ((a[i] + b[i]) >= k);
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}