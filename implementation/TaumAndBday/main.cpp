#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long b, w, bc, wc, z;
        cin >> b >> w >> bc >> wc >> z;
        cout << (b * min(bc, wc + z) + w * min(wc, bc + z)) << endl;
    }
    return 0;
}