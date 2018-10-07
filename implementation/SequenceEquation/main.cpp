#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> perm(n);
    for (int i = 0; i <n; ++i) {
        cin >> perm[i];
        --perm[i];
    }

    map<int, int> ppy;
    for (int i = 0; i < n; ++i)
        ppy[perm[perm[i]]] = i;
    for (int i = 0; i < n; ++i)
        cout << (ppy[i] + 1) << endl;

    return 0;
}