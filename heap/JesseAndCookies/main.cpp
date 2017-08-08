#include <iostream>
#include <queue>

std::priority_queue<int, std::vector<int>, std::greater<int>> s;

int solve(int k) {
    int cnt = 0;
    while (!s.empty()) {
        int a = s.top();
        s.pop();
        if (a >= k)
            return cnt;
        if (s.empty())
            return -1;
        int b = s.top();
        s.pop();
        int c = a + 2 * b;
        s.push(c);
        ++cnt;
    }
    return -1;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        s.push(x);
    }
    std::cout << solve(k) << std::endl;
    return 0;
}