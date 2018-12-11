#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define OFFSET (4)

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i=0; i<n; ++i)
        cin >> w[i];
    sort(w.begin(), w.end());
    int i=0, cnt=0;
    while (i < n) {
        int j = i + 1;
        while (j < n && w[j] - w[i] <= OFFSET)
            ++j;
        ++cnt;
        i = j;
    }
    cout << cnt << endl;
    return 0;
}