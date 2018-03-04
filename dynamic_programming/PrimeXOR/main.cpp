#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <tuple>
#include <limits>

#define MOD ((long long)1e9 + 7LL)
#define NMax (8191 + 1)

using namespace std;

vector<bool> is_prime(NMax);

void precomute_primes(vector<bool> &is_prime) {
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < NMax; ++i)
        if (is_prime[i])
            for (int j = i + i; j < NMax; j += i)
                is_prime[j] = false;
}

long long count(const vector<pair<int, int>> &nums, set<int> &primes) {
    int m = nums.size();
    vector<long long> dp(NMax, 0), dp_new(NMax, 0);
    dp[0] = 1LL;

    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < NMax; ++j) {
            int a, cnt;
            tie(a, cnt) = nums[i - 1];
            int odd = cnt / 2 + (cnt % 2);
            int even = cnt / 2;
            dp_new[j] = (dp_new[j] + dp[j] * (even + 1) + dp[j ^ a] * odd) % MOD;
        }
        fill(dp.begin(), dp.end(), 0);
        dp.swap(dp_new);
    }

    long long ans = 0LL;
    for (auto prime : primes)
        ans = (ans + dp[prime]) % MOD;
    return ans;
}

int main() {
    precomute_primes(is_prime);
    set<int> primes;
    for (int i = 0; i < NMax; ++i)
        if (is_prime[i])
            primes.insert(i);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        unordered_map<int, int> a;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            auto it = a.find(num);
            if (it == a.end())
                tie(it, ignore) = a.emplace(num, 0LL);
            it->second++;
        }

        vector<pair<int, int>> nums;
        int m = a.size();
        nums.reserve(m);
        for (auto p : a)
            nums.push_back(p);

        cout << count(nums, primes) << endl;
    }
    return 0;
}