#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n), d(n);
    for (int i = 0; i < n; ++i)
        std::cin >> p[i] >> d[i];

    int i = 0, start;
    while (i < n) {
        start = i;
        int f = p[i];
        while (i + 1 < n && d[i] <= f)
            f -= d[i], f += p[++i];
        ++i;
    }

    std::cout << start;

    return 0;
}