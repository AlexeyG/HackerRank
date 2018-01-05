#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

long expr(long a, long b) {
    return ((a & b) ^ (a | b)) & (a ^ b);
};

int main() {
    int n;
    stack<long> st;
    std::cin >> n;
    long ans = -1;
    for (int i = 0; i < n; ++i) {
        long a;
        std::cin >> a;
        while (!st.empty() && st.top() > a) {
            ans = max(ans, expr(a, st.top()));
            st.pop();
        }
        if (!st.empty())
            ans = max(ans, expr(a, st.top()));
        st.push(a);
    }
    std::cout << ans << std::endl;
}