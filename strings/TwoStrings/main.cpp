#include <iostream>
#include <unordered_set>
#include <string>

bool check(const std::string &str1, const std::string &str2) {
    std::unordered_set<char> s;
    for (char ch : str1)
        s.insert(ch);
    for (char ch : str2)
        if (s.find(ch) != s.end())
            return true;
    return false;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string str1, str2;
        std::cin >> str1 >> str2;
        std::cout << (check(str1, str2) ? "YES" : "NO") << std::endl;
    }
    return 0;
}