#include <iostream>
#include <vector>

using namespace std;

#define MOD ((long long)(1e9) + 7LL)

enum EndType {
    one = 0,
    x = 1,
    rest = 2
};

inline long long mul(long long a, long long b) {
    a %= MOD, b %= MOD;
    return (a * b) % MOD;
}

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<vector<long long>> cnt(n, vector<long long>(3, 0LL));

    if (x != 1) {
        cnt[0][EndType::one] = 1LL;
        for (int i = 1; i < n; ++i) {
            cnt[i][EndType::one] = cnt[i - 1][EndType::x] +
                                   cnt[i - 1][EndType::rest];
            cnt[i][EndType::x] = cnt[i - 1][EndType::one] +
                                 cnt[i - 1][EndType::rest];
            cnt[i][EndType::rest] = mul(cnt[i - 1][EndType::one], k - 2) +
                                    mul(cnt[i - 1][EndType::x], k - 2) +
                                    mul(cnt[i - 1][EndType::rest], k - 3);

            cnt[i][EndType::one] %= MOD;
            cnt[i][EndType::x] %= MOD;
            cnt[i][EndType::rest] %= MOD;
        }
    } else {
        cnt[0][EndType::x] = 1LL;
        for (int i = 1; i < n; ++i) {
            cnt[i][EndType::x] = cnt[i - 1][EndType::rest];
            cnt[i][EndType::rest] = mul(cnt[i - 1][EndType::x], k - 1) +
                                    mul(cnt[i - 1][EndType::rest], k - 2);

            cnt[i][EndType::x] %= MOD;
            cnt[i][EndType::rest] %= MOD;
        }
    }

    cout << cnt[n - 1][EndType::x] << endl;

    return 0;
}