#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <queue>

std::vector<std::string> str;
typedef std::vector<int>::iterator intVectorIterator;

// sorts in place (i.e. overwrite the sequence given by st and fn iterators)
void sort_strings_by_digit(const std::vector<std::string> &str, int pos, intVectorIterator st, intVectorIterator fn) {
    std::vector<std::queue<int>> buckets(10);
    for (auto it = st; it != fn; ++it) {
        char digit = str[*it][pos] - '0';
        buckets[digit].push(*it);
    }
    auto write_it = st;
    for (auto it = buckets.begin(); it != buckets.end(); ++it) {
        while (!it->empty())
        {
            (*(write_it++)) = it->front();
            it->pop();
        }
    }
}

// sorts in place (i.e. overwrite the sequence given by st and fn iterators)
void sort_strings_within_group(const std::vector<std::string> &str, intVectorIterator st, intVectorIterator fn) {
    int len = (int)str[*st].length();
    for (int pos = len - 1; pos >= 0; --pos)
        sort_strings_by_digit(str, pos, st, fn);
}

std::vector<int> sort_strings(const std::vector<std::string> &str) {
    std::vector<int> indices(str.size());
    std::iota(indices.begin(), indices.end(), 0);
    // first sort by length
    auto cmp = [&str](int i, int j) -> bool { return str[i].length() < str[j].length(); };
    sort(indices.begin(), indices.end(), cmp);

    // then sort within length group by digits
    auto st = indices.begin();
    while (st != indices.end()) {
        auto fn = st + 1;
        while (fn != indices.end() && str[*fn].length() == str[*st].length())
            ++fn;
        if (fn - st > 1) {
            // sort strings within one group
            sort_strings_within_group(str, st, fn);
        }
        st = fn;
    }

    return std::move(indices);
}

int main() {
    int n;
    std::cin >> n;
    str.resize(n);
    for (int i=0; i<n; ++i)
        std::cin >> str[i];
    std::vector<int> ind = sort_strings(str);
    for (auto it = ind.begin(); it != ind.end(); ++it)
        std::cout << str[*it] << std::endl;
    return 0;
}
