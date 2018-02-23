#include <iostream>
#include <string>
#include <vector>

bool test(const std::string &str) {
    std::vector<int> cnt(256, 0);
    for (auto ch : str)
        cnt[ch]++;
    int n_odd = 0;
    for (int i = 0; i < 256; ++i)
        if (cnt[i] % 2 == 1)
            ++n_odd;
    return n_odd <= 1;
}

int main() {
    std::string str;
    std::cin >> str;
    std::cout << (test(str) ? "YES" : "NO") << std::endl;
    return 0;
}