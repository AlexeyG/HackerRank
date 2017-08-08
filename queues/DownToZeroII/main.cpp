#include <iostream>
#include <array>
#include <limits>
#include <cmath>
#include <queue>

#define NMax (1000000 + 1)

std::array<int, NMax> f;

void search() {
    std::queue<int> q({0});
    for (int i = 0; i < NMax; ++i)
        f[i] = -1;
    f[0] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur + 1 < NMax && f[cur + 1] == -1) {
            f[cur + 1] = f[cur] + 1;
            q.push(cur + 1);
        }
        for (int i = 2; i * cur < NMax && i <= cur && cur != 1; ++i)
            if (f[i * cur] == -1) {
                f[i * cur] = f[cur] + 1;
                q.push(i * cur);
            }
    }
}

int main() {
    search();
    int q;
    std::cin >> q;
    while (q--) {
        int n;
        std::cin >> n;
        std::cout << f[n] << std::endl;
    }
    return 0;
}