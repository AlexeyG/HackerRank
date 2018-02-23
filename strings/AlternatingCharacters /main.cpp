#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string str;
        std::cin >> str;
        int i = 0, cnt = 0;
        while (i < str.length()) {
            int j = i + 1;
            while (j < str.length() && str[i] == str[j])
                ++j;
            cnt += (j - i) - 1;
            i = j;
        }
        std::cout << cnt << std::endl;
    }
    return 0;
}