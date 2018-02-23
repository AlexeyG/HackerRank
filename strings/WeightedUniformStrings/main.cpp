#include <iostream>
#include <string>
#include <vector>

bool check(const std::vector<int> &cnt, int w) {
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        int pos = ch - 'a';
        if (w % (pos + 1) == 0 && w / (pos + 1) <= cnt[pos])
            return true;
    }
    return false;
}

int main() {
    std::string str;
    int q;
    std::cin >> str >> q;

    // pre-process counts
    std::vector<int> cnt('z' - 'a' + 1, 0);
    int i = 0;
    while (i < str.length()) {
        int j = i + 1;
        while (j < str.length() && str[i] == str[j])
            ++j;
        int pos = str[i] - 'a';
        cnt[pos] = std::max(cnt[pos], j - i);
        i = j;
    }

    while (q--) {
        int w;
        std::cin >> w;
        std::cout << (check(cnt, w) ? "Yes" : "No") << std::endl;
    }
    return 0;
}