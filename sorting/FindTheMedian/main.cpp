#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());
    std::cout << a[n / 2] << std::endl;
    return 0;
}
