#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_valid(long long a, long long b, long long c) {
    return (a < b + c) && (b < a + c) && (c < a + b);
}

int main() {
    int n;
    cin >> n;
    vector<long long> len(n);
    for (int i = 0; i < n; ++i)
        cin >> len[i];
    sort(len.begin(), len.end(), greater<int>());
    bool found = false;
    for (int i = 0; i < n && !found; ++i)
        for (int j = i + 1; j < n && !found; ++j)
            for (int k = j + 1; k < n && !found; ++k)
                if (is_valid(len[i], len[j], len[k])) {
                    cout << len[k] << " " << len[j] << " " << len[i] << endl;
                    found = true;
                    break;
                }
    if (!found)
        cout << -1 << endl;
    return 0;
}