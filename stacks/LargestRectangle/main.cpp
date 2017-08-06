#include <iostream>
#include <vector>
#include <stack>
#include <numeric>

long long solve(std::vector<long long> &h) {
    h.push_back(0);
    std::stack<std::pair<int, long>> st;
    long long ans = 0;
    for (int i = 0; i < h.size(); ++i) {
        if (!st.empty() && (st.top().second >= h[i])) {
            std::pair<int, long> latest;
            while (!st.empty() && (st.top().second >= h[i])) {
                latest = st.top();
                long long cur_ans = latest.second * (i - latest.first);
                ans = std::max(ans, cur_ans);
                st.pop();
            }
            st.emplace(latest.first, h[i]);
        }
        else
            st.emplace(i, h[i]);
    }

    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> h(n);
    for (int i = 0; i < n; ++i)
        std::cin >> h[i];
    std::cout << solve(h) << std::endl;
    return 0;
}