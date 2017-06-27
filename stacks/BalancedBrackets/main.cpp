#include <iostream>
#include <string>
#include <stack>

bool is_balanced(const std::string& str) {
    std::stack<char> st;
    for (auto ch : str) {
        if (ch == '[' || ch == '{' || ch == '(')
            st.push(ch);
        else if (!st.empty() && ((ch == ']' && st.top() == '[') || (ch == ')' && st.top() == '(') || (ch == '}' && st.top() == '{')))
            st.pop();
        else
            return false;
    }
    return st.empty();
}

int main() {
    std::string str;
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> str;
        std::cout << ((is_balanced(str)) ? "YES" : "NO") << std::endl;
    }
    return 0;
}