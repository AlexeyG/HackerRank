#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

typedef std::pair<unsigned int, unsigned int> trackT;
typedef std::map<unsigned int, std::vector<trackT>> mapT;

unsigned long long processRow(const std::vector<trackT> &row, unsigned int m) {
    unsigned long long acc = 0;
    int prev = 0;
    for (auto it = row.begin(); it != row.end(); ++it) {
        int c1 = it->first, c2 = it->second;
        int prevBefore = prev;
        if (prev < c1)
            acc += (unsigned long long)(c1 - prev - 1);
        prev = std::max(prev, c2);
        std::cout << acc << " : " << prevBefore << " (" << c1 << " " << c2 << ") " << prev << std::endl;
    }
    acc += (unsigned long long)(m - prev);
    return acc;
}

unsigned long long processGrid(mapT &map, unsigned int n, unsigned int m) {
    unsigned long long acc = (unsigned long long)(n - map.size()) * (unsigned long long)m;
    //std::cout << "starting from " << acc << std::endl;
    for (auto it = map.begin(); it != map.end(); ++it) {
        sort(it->second.begin(), it->second.end());
        std::cout << "row " << it->first << std::endl;
        acc += processRow(it->second, m);
        //std::cout << "row " << it->first << " = " << processRow(it->second, m) << std::endl;
    }
    return acc;
}

int main() {
    unsigned int n, m, k;
    std::cin >> n >> m >> k;
    mapT tracks;

    for (int i = 0; i < k; ++i) {
        int r, c1, c2;
        std::cin >> r >> c1 >> c2;
        if (tracks.find(r) == tracks.end())
            tracks[r] = std::vector<trackT>();
        tracks[r].push_back(std::make_pair(c1, c2));
    }

    std::cout << processGrid(tracks, n, m) << std::endl;

    return 0;
}
