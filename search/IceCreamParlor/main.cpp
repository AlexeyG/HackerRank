#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct IceCream {
    int cost, index;

    IceCream(int _cost, int _index)
            : cost(_cost), index(_index) {};

    bool operator< (const IceCream &other) const {
        return (cost < other.cost) || ((cost == other.cost) && (index < other.index));
    };
};

std::pair<int, int> find_sum(const std::vector<IceCream> a, long long sum) {
    int i = 0, j = a.size() - 1;
    while (i < j) {
        //std::cout << "i = " << i << " j = " << j << " a[i] = " << a[i].cost << " a[j] = " << a[j].cost << std::endl;
        long long cur_sum = a[i].cost + a[j].cost;
        if (cur_sum == sum)
            return (a[i].index < a[j].index) ? std::make_pair(a[i].index, a[j].index) : std::make_pair(a[j].index, a[i].index);
        if (cur_sum < sum)
            ++i;
        else
            --j;
    }
    return std::make_pair(-1, -1);
};

int main() {
    int n, m, t, cost;
    std::cin >> t;
    while (t--) {
        cin >> m >> n;
        std::vector<IceCream> arr;
        arr.reserve(n);
        for (int i = 0; i < n; i++) {
            std::cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }

        std::sort(arr.begin(), arr.end());
        auto ans = find_sum(arr, m);
        std::cout << ans.first << " " << ans.second << std::endl;
    }

}

