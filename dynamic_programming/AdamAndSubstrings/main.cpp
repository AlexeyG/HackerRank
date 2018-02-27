#include <iostream>
#include <string>
#include <vector>

#define MOD ((long long)(1e9 + 7))

using namespace std;

long long mul(long long a, long long b) {
    a %= MOD, b %= MOD;
    return (a * b) % MOD;
}

int main() {
    string str;
    cin >> str;
    int n = str.length();
    vector<long long> sum(n, 0);
    sum[0] = str[0] - '0';
    for (int i = 1; i < str.length(); ++i)
        sum[i] = (mul(sum[i - 1], 10) + mul(str[i] - '0', i + 1)) % MOD;
    long long ans = 0;
    for (auto a : sum)
        ans = (ans + a) % MOD;
    cout << ans << endl;
    return 0;
}