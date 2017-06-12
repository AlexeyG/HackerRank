// https://www.hackerrank.com/challenges/equal

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>

unsigned long long min_operations(const std::vector<int> &c) {
    int min = *std::min_element(c.begin(), c.end());
    //std::cout << "min " << min << std::endl;
    unsigned long long count = std::numeric_limits<unsigned long long>::max();

    // This does not give the correct answer always. Test case 15 requires underflowing (diff > min), no clue why.
    // for (int diff = 0; diff <= 5; ++diff) {   // This gives a correct answer (no need to consider steps beyond 5
                                                 // But underflowing still makes no sense to me
    for (int diff = 0; diff <= min; ++diff) {

        unsigned long long cur_count = 0;
        for (auto it = c.begin(); it != c.end(); ++it) {
            int elem = *it - (min - diff);
            cur_count += elem / 5 + ((elem % 5) >> 1) + ((elem % 5) & 1);
        }
        count = std::min(count, cur_count);
    }
    return count;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> c(n);
        while (n--)
            std::cin >> c[n];
        std::cout << min_operations(c) << std::endl;
    }
    return 0;
}