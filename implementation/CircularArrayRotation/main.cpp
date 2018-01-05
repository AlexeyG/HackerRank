#include <vector>
#include <iostream>

int main() {
    int n, k, q;
    std::cin >> n >> k >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < q; ++i) {
        int m;
        std::cin >> m;
        m -= k;
        while (m < 0)
            m += n;
        std::cout << a[m] << std::endl;
    }
    return 0;
}
