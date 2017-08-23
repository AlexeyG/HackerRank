#include <vector>
#include <stack>
#include <iostream>

typedef std::vector<std::vector<std::pair<int, int>>> TB;
typedef std::vector<std::vector<int>> DP;

std::stack<int> get_sequence(const std::vector<int> &a, const std::vector<int> &b, const TB &tr) {
    std::stack<int> ans;
    int i = a.size(), j = b.size();
    while (i > 0 && j > 0) {
        //std::cout << "i = " << i << " j = " << j << std::endl;
        int i_new = tr[i][j].first, j_new = tr[i][j].second;
        if (i - i_new > 0 && j - j_new > 0)
            ans.push(a[i - 1]);
        i = i_new, j = j_new;
    }
    return ans;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int j = 0; j < m; ++j)
        std::cin >> b[j];

    DP dp(n + 1, std::vector<int>(m + 1, 0));
    TB tr(n + 1, std::vector<std::pair<int, int>>(m + 1, std::make_pair(-1, -1)));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (dp[i][j - 1] < dp[i - 1][j]) {
                dp[i][j] = dp[i - 1][j];
                tr[i][j] = std::make_pair(i - 1, j);
            } else {
                dp[i][j] = dp[i][j - 1];
                tr[i][j] = std::make_pair(i, j - 1);
            }
            if (a[i - 1] == b[j - 1] && dp[i][j] < dp[i - 1][j - 1] + 1) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                tr[i][j] = std::make_pair(i - 1, j - 1);
            }
        }

    //std::cout << dp[n][m] << std::endl;

    auto seq = get_sequence(a, b, tr);
    while (!seq.empty()) {
        std::cout << seq.top() << " ";
        seq.pop();
    }
    std::cout << std::endl;

    return 0;
}
