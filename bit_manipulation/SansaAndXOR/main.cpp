#include <vector>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, a, ans = 0;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::cin >> a;
            ans ^= (((i + 1) * (n - i)) % 2 == 0) ? 0 : a;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
