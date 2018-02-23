#include <iostream>
#include <string>

bool find_next(const std::string &str, int from, long long base) {
    if (str[from] == '0')
        return false;
    if (from == str.length())
        return true;

    long long cur = 0;
    while (from < str.length()) {
        cur = cur * 10 + str[from] - '0';
        if (cur == base + 1)
            return find_next(str, from + 1, cur);
        else if (cur > base + 1)
            return false;
        ++from;
    }
    return false;
}

long long sep(const std::string &str) {
    if (str[0] == '0' && find_next(str, 1, 0))
        return 0;

    long long cur = 0;
    for (int i = 0; i < str.length() - 1; ++i) {
        cur = cur * 10 + str[i] - '0';
        if (find_next(str, i + 1, cur))
            return cur;
    }
    return -1;
}

int main() {
    int q;
    std::string str;
    std::cin >> q;
    while (q--) {
        std::cin >> str;
        long long ans = sep(str);
        if (ans >= 0)
            std::cout << "YES " << ans << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}