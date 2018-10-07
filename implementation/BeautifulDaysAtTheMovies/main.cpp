#include <iostream>

using namespace std;

int reverse(int n) {
    int m = 0;
    while (n > 0) {
        m = m * 10 + n % 10;
        n /= 10;
    }
    return m;
}

int main() {
    int i, j, k;
    cin >> i >> j >> k;
    long cnt = 0;
    while (i <= j) {
        int diff = abs(i - reverse(i));
        if (diff % k == 0)
            ++cnt;
        ++i;
    }
    cout << cnt << endl;
    return 0;
}