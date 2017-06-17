#include <iostream>
#include <vector>

bool can_win(std::vector<int> &s) {
    int all_xor = 0;
    for (auto it = s.begin(); it != s.end(); ++it)
        all_xor ^= *it;
    return all_xor > 0;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> s(n);
        while (n--)
            std::cin >> s[n];
        std::cout << (can_win(s) ? "First" : "Second") << std::endl;
    }
    return 0;
}