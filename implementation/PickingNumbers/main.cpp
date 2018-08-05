#include <iostream>
#include <iostream>
#include <vector>

using namespace std;

#define NMax (100)

int get_longest_run(const vector<int> &cnt) {
    int ans = -1;
    for (int i = 0; i < NMax; ++i) {
        ans = max(ans, cnt[i]);
        if (i + 1 < NMax)
            ans = max(ans, cnt[i] + cnt[i + 1]);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> cnt(NMax, 0);
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        ++cnt[--num];
    }
    cout << get_longest_run(cnt) << endl;
    return 0;
}