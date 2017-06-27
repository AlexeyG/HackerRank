#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <stack>
#include <limits>

typedef std::tuple<int, int, int> opT;

std::vector<opT> ops;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<long long> arr(n + 1, 0);
    while (m--) {
        int a, b, k;
        std::cin >> a >> b >> k;
        arr[a - 1] += k;
        arr[b] -= k;
    }

    long long max_value = 0, value = 0;
    for (int i = 0; i <= n; ++i)
        value += arr[i], max_value = std::max(max_value, value);

    std::cout << max_value << std::endl;

    return 0;
}