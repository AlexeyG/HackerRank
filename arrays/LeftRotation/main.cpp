#include <iostream>
#include <vector>

int main() {
    int n, d;
    std::cin >> n >> d;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < n; ++i)
        std::cout << a[(i + d) % n] << " ";
    return 0;
}