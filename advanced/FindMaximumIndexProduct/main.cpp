#include <vector>
#include <stack>
#include <iostream>
#include <cmath>


int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), left(n), right(n);
    std::stack<int> st;
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();
        left[i] = (st.empty()) ? 0 : (st.top() + 1);
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();
        right[i] = (st.empty()) ? 0 : (st.top() + 1);
        st.push(i);
    }

    long long m = -1;
    for (int i = 0; i < n; ++i)
        m = std::max(m, (long long)left[i] * right[i]);
    std::cout << m << std::endl;
    return 0;
}
