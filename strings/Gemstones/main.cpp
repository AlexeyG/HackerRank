#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> agg(26, 0);
    for (int i = 0; i < n; ++i) {
        std::string rock;
        std::cin >> rock;
        std::vector<bool> comp(26, false);
        for (auto ch : rock)
            comp[ch - 'a'] = true;
        for (int j = 0; j < 26; ++j)
            agg[j] += int(comp[j]);
    }
    int cnt = 0;
    for (int j = 0; j < 26; ++j)
        cnt += int(agg[j] == n);
    std::cout << cnt << std::endl;
    return 0;
}