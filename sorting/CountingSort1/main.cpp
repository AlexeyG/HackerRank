#include <iostream>
#include <vector>

#define NMax (100)

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cnt(NMax, 0);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        ++cnt[val];
    }
    for (int i = 0; i < NMax; ++i)
        cout << cnt[i] << " ";
    cout << endl;
    return 0;
}