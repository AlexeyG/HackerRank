#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i=0; i<n; ++i)
        cin >> p[i];
    int s = 0, i = 0;
    do {
        nth_element(p.begin(), p.begin() + i, p.end());
        if (s + p[i] <= k)
            s += p[i++];
        else
            break;
    } while (i < n);
    cout << i << endl;
    return 0;
}