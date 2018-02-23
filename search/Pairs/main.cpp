#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    long long cnt = 0;
    int n, k;
    cin >> n >> k;
    unordered_set<int> s;
    for (int i=0; i<n; ++i) {
        int cur;
        cin >> cur;
        auto it = s.find(cur - k);
        if (it != s.end())
            ++cnt;
        it = s.find(cur + k);
        if (it != s.end())
            ++cnt;
        s.insert(cur);
    }
    cout << cnt << endl;
    return 0;
}