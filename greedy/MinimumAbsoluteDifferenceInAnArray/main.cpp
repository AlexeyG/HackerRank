#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

int getDifference(std::vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int min_so_far = INT_MAX;
    for (auto i = arr.begin(), j = arr.begin() + 1; j != arr.end(); ++i, ++j)
        min_so_far = std::min(min_so_far, std::abs(*i - *j));
    return min_so_far;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    while (n--) std::cin >> arr[n];
    std::cout << getDifference(arr) << std::endl;
    return 0;
}