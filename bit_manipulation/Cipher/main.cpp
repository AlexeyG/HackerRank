#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, k;
    std::string str;
    std::cin >> n >> k;
    std::cin >> str;

    std::vector<bool> bit(n + k);
    for (int i = 0; i < n + k; ++i)
        bit[i] = (str[i] - '0') > 0;

    std::vector<bool> ans(n, false);
    bool cur = bit[0];
    ans[0] = bit[0];
    for (int i = 1; i < k; ++i) {
        ans[i] = cur ^ bit[i];
        cur ^= ans[i];
    }
    for (int i = k; i < n; ++i) {
        ans[i] = cur ^ bit[i] ^ ans[i - k];
        cur ^= ans[i] ^ ans[i - k];
    }
    for (int i = 0; i < n; ++i)
        std::cout << ((ans[i]) ? '1' : '0');
    std::cout << std::endl;
    return 0;
}
