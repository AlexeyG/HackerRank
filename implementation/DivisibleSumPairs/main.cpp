#include <vector>
#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if ((a[i] + a[j]) % k == 0)
                ++cnt;
    std::cout << cnt << std::endl;
    return 0;
}
