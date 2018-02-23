#include <iostream>
#include <string>
#include <vector>

bool find(const std::string &str, const std::string goal="hackerrank") {
    int len_goal = goal.length();
    int len_str = str.length();
    std::vector<std::vector<bool>> dp(len_str + 1, std::vector<bool>(len_goal + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= len_str; ++i)
        for (int j = 0; j <= len_goal; ++j) {
            dp[i][j] = dp[i][j] || dp[i - 1][j];
            if (j > 0)
                dp[i][j] = dp[i][j] || (dp[i - 1][j - 1] && (str[i - 1] == goal[j - 1]));
        }
    return dp[len_str][len_goal];
}

bool find_fast(const std::string &str, std::string goal="hackerrank") {
    int len_goal = goal.length();
    int len_str = str.length();
    goal = goal + "$";

    std::vector<int> dp(len_str + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= len_str; ++i) {
        dp[i] = (str[i - 1] == goal[dp[i - 1]]) ? dp[i - 1] + 1 : dp[i - 1];
        std::cout << i << " : " << dp[i] << std::endl;
    }
    return dp[len_str] == len_goal;
}

bool find_fast_no_arr(const std::string &str, std::string goal="hackerrank") {
    int len_goal = goal.length();
    int len_str = str.length();
    int so_far = 0;
    for (int i = 1; i <= len_str; ++i) {
        if (str[i - 1] == goal[so_far])
            ++so_far;
        if (so_far == len_goal)
            return true;
    }
    return false;
}

int main() {
    int q;
    std::cin >> q;
    while (q--) {
        std::string str;
        std::cin >> str;
        std::cout << (find_fast_no_arr(str) ? "YES" : "NO") << std::endl;
    }
    return 0;
}