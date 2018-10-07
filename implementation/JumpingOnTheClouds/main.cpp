#include <iostream>
#include <vector>

using namespace std;

#define INF (101)

int path_len(const vector<bool> &allowed, int pos) {
    if (pos == 0)
        return 0;
    if (pos < 0)
        return INF;
    if (!allowed[pos])
        return INF;
    return min(path_len(allowed, pos - 1), path_len(allowed, pos - 2)) + 1;
}

int main() {
    int n;
    cin >> n;
    vector<bool> allowed(n);
    for (int i=0; i<n; ++i) {
        int tmp;
        cin >> tmp;
        allowed[i] = tmp == 0;
    }

    cout << path_len(allowed, n - 1) << endl;
    return 0;
}