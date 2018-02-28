#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool match(const string &a, const string &b, int n, int m, vector<vector<int>> &mem) {
    //cout << "at " << a.substr(0, n + 1) << " and " << b.substr(0, m + 1) << endl;
    if (n == -1 && m >= 0)
        return false;
    if (m == -1)
        return true;

    if (mem[n][m] >= 0)
        return mem[n][m] == 1;

    for (int i = n; i >= 0; --i)
        if (toupper(a[i]) == b[m] && match(a, b, i - 1, m - 1, mem)) {
            mem[n][m] = 1;
            return true;
        } else if (toupper(a[i]) == a[i]) // have a capital letter in a
            break;
    mem[n][m] = 0;
    return false;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        string a, b;
        cin >> a >> b;
        int n = a.length(), m = b.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        cout << (match(a, b, n - 1, m - 1, dp) ? "YES" : "NO") << endl;
    }
    return 0;
}