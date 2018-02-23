#include <iostream>
#include <cmath>
#include <string>

bool check(const std::string &str) {
    int len = str.length();
    for (int i = 1; i < len; ++i) {
        if (std::abs(str[i] - str[i - 1]) != std::abs(str[len - i - 1] - str[len - i]))
            return false;
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string str;
        std::cin >> str;
        std::cout << (check(str) ? "Funny" : "Not Funny") << std::endl;
    }
    return 0;
}