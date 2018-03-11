#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <algorithm>

#define NMax (400000)
#define DMax (10)

#define MOD ((long long)1e9 + 7LL)

using namespace std;

typedef tuple<int, int, int, int, int> Transition;

void calculate_primes(vector<bool> &is_prime) {
    fill(is_prime.begin(), is_prime.end(), true);
    int n = is_prime.size();
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < n; ++i)
        if (is_prime[i])
            for (int j = i + i; j < n; j += i)
                is_prime[j] = false;
}

void get_transitions(vector<Transition> &trans, const vector<bool> &is_prime) {
    for (int d1 = 0; d1 < DMax; ++d1)
        for (int d2 = 0; d2 < DMax; ++d2)
            for (int d3 = 0; d3 < DMax; ++d3)
                if (is_prime[d1 + d2 + d3])
                    for (int d4 = 0; d4 < DMax; ++d4)
                        if (is_prime[d2 + d3 + d4] && is_prime[d1 + d2 + d3 + d4])
                            for (int d5 = 0; d5 < DMax; ++d5)
                                if (is_prime[d1 + d2 + d3 + d4 + d5] && is_prime[d2 + d3 + d4 + d5] && is_prime[d3 + d4 + d5])
                                    trans.emplace_back(d1, d2, d3, d4, d5);
}

void fill_dp(vector<long long> &answers, const vector<Transition> &transitions5, const vector<bool> &is_prime) {
    vector<int> mask2ind(DMax * DMax * DMax * DMax, -1);
    vector<pair<int, int>> transitions5_ind;
    int k = 0;
    for (auto transition : transitions5) {
        int d1, d2, d3, d4, d5;
        tie(d1, d2, d3, d4, d5) = transition;

        int mask25 = d2 * 1000 + d3 * 100 + d4 * 10 + d5;
        int mask14 = d1 * 1000 + d2 * 100 + d3 * 10 + d4;

        if (mask2ind[mask14] < 0)
            mask2ind[mask14] = k++;

        if (mask2ind[mask25] < 0)
            mask2ind[mask25] = k++;

        transitions5_ind.emplace_back(mask2ind[mask14], mask2ind[mask25]);
    }

    for (int d1 = 1; d1 < DMax; ++d1)
        for (int d2 = 0; d2 < DMax; ++d2)
            for (int d3 = 0; d3 < DMax; ++d3)
                if (is_prime[d1 + d2 + d3])
                    for (int d4 = 0; d4< DMax; ++d4)
                        if (is_prime[d2 + d3 + d4] && is_prime[d1 + d2 + d3 + d4]) {
                            int mask = d1 * 1000 + d2 * 100 + d3 * 10 + d4;
                            if (mask2ind[mask] < 0)
                                mask2ind[mask] = k++;
                        }

    // initialise the DP
    // We will use brute force here
    vector<tuple<int, int, int, int>> transitions4;
    vector<long long> dp1(k, 0);
    for (int d1 = 1; d1 < DMax; ++d1)
        for (int d2 = 0; d2 < DMax; ++d2)
            for (int d3 = 0; d3 < DMax; ++d3)
                if (is_prime[d1 + d2 + d3]) {
                    ++answers[3 - 1];
                    for (int d4 = 0; d4 < DMax; ++d4)
                        if (is_prime[d2 + d3 + d4] && is_prime[d1 + d2 + d3 + d4]) {
                            ++answers[4 - 1];
                            transitions4.emplace_back(d1, d2, d3, d4);
                            for (int d5 = 0; d5 < DMax; ++d5) {
                                if (is_prime[d1 + d2 + d3 + d4 + d5] && is_prime[d3 + d4 + d5] && is_prime[d2 + d3 + d4 + d5]) {
                                    int mask = d2 * 1000 + d3 * 100 + d4 * 10 + d5;
                                    int ind = mask2ind[mask];
                                    ++dp1[ind];
                                    ++answers[5 - 1];
                                }
                            }
                        }
                }
    // 1..9
    answers[0] = 9;
    // 10..99
    answers[1] = 90;

    vector<long long> dp2(k, 0);
    for (int len = 6; len <= NMax; ++len) {
        // DP step
        answers[len - 1] = 0LL;
        for (auto transition : transitions5_ind) {
            int ind14, ind25;
            tie(ind14, ind25) = transition;
            dp2[ind25] = (dp2[ind25] + dp1[ind14]) % MOD;
            answers[len - 1] = (answers[len - 1] + dp1[ind14]) % MOD;
        }

        // Reset DP tables
        dp1.swap(dp2);
        fill(dp2.begin(), dp2.end(), 0LL);
    }
}

int main() {
    vector<long long> answers(NMax, 0);
    vector<Transition> transitions;
    vector<bool> is_prime(DMax * DMax * DMax * DMax * DMax, true);
    calculate_primes(is_prime);
    get_transitions(transitions, is_prime);
    fill_dp(answers, transitions, is_prime);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << answers[n - 1] << endl;
    }
    return 0;
}