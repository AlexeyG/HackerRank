#include <iostream>
#include <stack>

long long accumulate(std::stack<long> &st) {
    if (st.empty())
        return 0L;
    int top = st.top();
    long long cnt = 0LL;
    while (!st.empty() && st.top() == top)
        st.pop(), ++cnt;
    return cnt * (cnt - 1LL);
};

int main() {
    std::stack<long> st;
    int n;
    long h;
    long long ans = 0;
    std::cin >> n;
    while (n--) {
        std::cin >> h;
        while (!st.empty() && st.top() < h)
            ans += accumulate(st);
        st.push(h);
    }
    while (!st.empty())
        ans += accumulate(st);
    std::cout << ans << std::endl;
    return 0;
};
