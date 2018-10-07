#include <iostream>

using namespace std;

int count_diabetes(int n, int c, int m) {
    int choco = n / c, wrappers = 0, total = 0;
    while (choco > 0) {
        total += choco;
        int new_choco = (choco + wrappers) / m;
        wrappers = (choco + wrappers) % m;
        choco = new_choco;
    }
    return total;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c, m;
        cin >> n >> c >> m;
        cout << count_diabetes(n, c, m) << endl;
    }
    return 0;
}