#include <iostream>
#include <string>
#include <vector>

int count(const std::string &str1, const std::string &str2) {
    std::vector<int> cnt(256, 0);
    for (auto ch : str1)
        cnt[ch]++;
    for (auto ch : str2)
        cnt[ch]--;
    int total = 0;
    for (auto cur : cnt)
        total += abs(cur);
    return total;
}

int main() {
    std::string str1, str2;
    std::cin >> str1 >> str2;
    std::cout << count(str1, str2) << std::endl;
    return 0;
}