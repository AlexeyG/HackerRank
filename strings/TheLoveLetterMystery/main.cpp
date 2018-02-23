#include <iostream>
#include <string>

int get_min(const std::string &str) {
    int len = str.length();
    int i = 0, j = len - 1;
    int ans = 0;
    while (i < j) {
        char mi = std::min(str[i], str[j]);
        char ma = std::max(str[i], str[j]);
        ans += ma - mi;
        ++i, --j;
    }
    return ans;
}

int main() {
    int q;
    std::cin >> q;
    while (q--) {
        std::string str;
        std::cin >> str;
        std::cout << get_min(str) << std::endl;
    }
    return 0;
}