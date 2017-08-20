#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define NMax (100 + 2)

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::cin >> m;
    std::vector<int> b(m);
    std::unordered_map<int, int> compress, uncompress;
    std::vector<int> counts(NMax, 0);
    int ind = 0;
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
        if (compress.find(b[i]) == compress.end()) {
            compress[b[i]] = ind;
            uncompress[ind] = b[i];
            ++ind;
        }
        ++counts[compress[b[i]]];
    }
    for (auto val : a)
        --counts[compress[val]];

    std::vector<int> ans;
    for (int i = 0; i < NMax; ++i)
        if (counts[i] != 0)
            ans.push_back(uncompress[i]);
    std::sort(ans.begin(), ans.end());
    for (auto val : ans)
        std::cout << val << " ";
    std::cout << std::endl;
    return 0;
}