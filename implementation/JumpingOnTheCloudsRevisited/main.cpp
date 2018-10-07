#include <iostream>
#include <vector>

using namespace std;

int simulate(const vector<bool> &is_thunder, int step) {
    int n = is_thunder.size();
    int pos = 0, energy = 100;
    do {
        pos = (pos + step) % n;
        --energy;
        if (is_thunder[pos])
            energy -= 2;
    } while (pos != 0);
    return energy;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> is_thunder(n);
    for (int i=0; i<n; ++i) {
        int flag;
        cin >> flag;
        is_thunder[i] = (flag == 1);
    }
    cout << simulate(is_thunder, k) << endl;
    return 0;
}