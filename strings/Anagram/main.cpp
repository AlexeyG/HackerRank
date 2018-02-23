#include <iostream>
#include <string>
#include <vector>

int get_min(const std::string &str) {
    int len = str.length();
    if (len % 2 == 1)
        return -1;
    std::string str1 = str.substr(0, len / 2);
    std::string str2 = str.substr(len / 2, len / 2);

    std::vector<int> cnt(256, 0);
    for (auto ch : str1)
        cnt[ch]++;
    for (auto ch : str2)
        cnt[ch]--;
    int total = 0;
    for (auto cur : cnt)
        total += abs(cur);
    return total / 2;
}

int main() {
    std::string str;
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> str;
        std::cout << get_min(str) << std::endl;
    }
    return 0;
}