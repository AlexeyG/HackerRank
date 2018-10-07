#include <iostream>

using namespace std;

int main() {
    int n, m, s, t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> s;
        cout << ((s + m - 2) % n + 1) << endl;
    }
    return 0;
}