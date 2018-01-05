#include <iostream>
#include <vector>

#define NMax (100)

int main() {
    int n;
    std::cin >> n;
    std::vector<int> count(NMax, 0);
    for (int i = 0; i < n; ++i) {
        int c;
        std::cin >> c;
        count[--c]++;
    }
    int ans = 0;
    for (int i = 0; i < NMax; ++i)
        ans += (count[i] >> 1);
    std::cout << ans << std::endl;
    return 0;
}