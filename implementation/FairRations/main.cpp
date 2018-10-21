#include <iostream>
#include <vector>

using namespace std;

bool is_odd(int n) {
    return n % 2 == 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    // Determine chain lengths.
    bool is_possible = true;
    int i = 0, cnt = 0;
    while (i < n && is_possible) {
        int j = i + 1;
        if (is_odd(b[i])) {
            while (j < n && !is_odd(b[j]))
                ++j;
            int len = j - i;
            if (j == n) {
                //cout << "impossible " << i << " -> " << j << " len=" << len << endl;
                is_possible = false;
            }
            cnt += len * 2;
            //cout << "increment by " << (len * 2) << endl;
            //cout << "i = " << i << " j = " << j << endl;
            i = j;
        }
        ++i;
    }
    if (is_possible)
        cout << cnt << endl;
    else
        cout << "NO" << endl;
    return 0;
}