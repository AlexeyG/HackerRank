#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define MOD (101)

// precompute (i.e. bruteforce mod equations)
vector<vector<int>> mod_div(MOD, vector<int>(MOD));

void precompute(vector<vector<int>> &mod_div) {
    for (int i = 0; i < MOD; ++i)
        for (int j = 0; j < MOD; ++j) {
            // (x * i) % MOD = j
            bool found = false;
            for (int x = 0; x < MOD; ++x)
                if ((x * i) % MOD == j) {
                    mod_div[i][j] = x;
                    found = true;
                    break;
                }
            if (!found)
                mod_div[i][j] = -1;
        }
}

bool rec(const vector<int> &nums, int pos, int want, vector<vector<int>>& dp, vector<vector<char>>& op) {
    if (pos == 0) {
        dp[0][want] = nums[0] == want;
        if (dp[0][want])
            op[0][want] = '1';
        return nums[0] == want;
    }

    if (dp[pos][want] >= 0)
        return dp[pos][want] == 1;

    int new_want;
    // addition
    // new_want + nums[pos] = want
    new_want = (want - nums[pos] + MOD) % MOD;
    if (rec(nums, pos - 1, new_want, dp, op)) {
        dp[pos][want] = 1;
        op[pos][want] = '+';
        return true;
    }

    // subtraction
    // new_want - nums[pos] = want
    new_want = (want + nums[pos]) % MOD;
    if (rec(nums, pos - 1, new_want, dp, op)) {
        dp[pos][want] = 1;
        op[pos][want] = '-';
        return true;
    }

    // multiplication
    // new_want * nums[pos] = want
    new_want = mod_div[nums[pos]][want];
    if (new_want >= 0)
        if (rec(nums, pos - 1, new_want, dp, op)) {
            dp[pos][want] = 1;
            op[pos][want] = '*';
            return true;
        }

    dp[pos][want] = 0;
    return false;
}

string get_path(const vector<int> &nums, const vector<vector<char>>& op, int pos, int want = 0) {
    if (pos < 0)
        return "";

    stringstream ss;
    int new_want;
    switch (op[pos][want]) {
        case '1' :
            ss << nums[pos];
            break;
        case '+' :
            new_want = (want - nums[pos] + MOD) % MOD;
            ss << get_path(nums, op, pos - 1, new_want) << '+' << nums[pos];
            break;
        case '-' :
            new_want = (want + nums[pos]) % MOD;
            ss << get_path(nums, op, pos - 1, new_want) << '-' << nums[pos];
            break;
        case '*' :
            new_want = mod_div[nums[pos]][want];
            ss << get_path(nums, op, pos - 1, new_want) << '*' << nums[pos];
            break;
    }
    return ss.str();
}

int main() {
    precompute(mod_div);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        nums[i] %= MOD;
    }

    vector<vector<int>> can_reach(n, vector<int>(MOD, -1));
    vector<vector<char>> op(n, vector<char>(MOD, 0));
    if (rec(nums, n - 1, 0, can_reach, op))
        cout << get_path(nums, op, n - 1, 0) << endl;
    else
        return 777;


    return 0;
}