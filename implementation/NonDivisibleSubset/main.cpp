#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(k, 0);
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        ++cnt[s % k];
    }
    int ans = 0;
    if (cnt[0] > 0)
        ++ans;
    for (int i = 1; i < k; ++i) {
        //cout << i << " " << cnt[i] << " " << cnt[k - i] << endl;
        if (cnt[i] > 0 && k % 2 == 0 && i == k / 2)
            ++ans;
        else if (cnt[i] > cnt[k - i] || (cnt[i] == cnt[k - i] && i > k - i))
            ans += cnt[i];
    }
    cout << ans << endl;
    return 0;
}