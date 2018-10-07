#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int max_h = -1;
    while (n--) {
        int h;
        cin >> h;
        max_h = max(max_h, h);
    }
    cout << max(max_h - k, 0);
    return 0;
}