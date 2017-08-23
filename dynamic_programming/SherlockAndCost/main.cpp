#include <vector>
#include <iostream>
#include <limits>

#define BMax (2)

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> b(n);
        for (int i = 0; i < n; ++i)
            std::cin >> b[i];
        std::vector<std::vector<int>> dp(n, std::vector<int>(BMax, std::numeric_limits<int>::min()));
        for (int i = 0; i < BMax; ++i)
            dp[0][i] = 0;
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < BMax; ++j)
                for (int k = 0; k < BMax; ++k) {
                    int bj = (j == 0) ? 0 : b[i] - 1;
                    int bk = (k == 0) ? 0 : b[i - 1] - 1;
                    int diff = bj - bk;
                    if (diff < 0)
                        diff = -diff;
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][k] + diff);
                }
        int ans = -1;
        for (int i = 0; i < BMax; ++i)
            ans = std::max(ans, dp[n - 1][i]);
        std::cout << ans << std::endl;
    }
    return 0;
}
