#include <iostream>
#include <set>

using namespace std;

#define INF (10000 + 1)

int main() {
    set<pair<int, int>> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        nums.insert(make_pair(tmp, i));
    }
    auto i = nums.begin(), j = nums.begin();
    ++j;
    int min_dist = INF;
    while (j != nums.end()) {
        if (i->first == j->first)
            min_dist = min(min_dist, j->second - i->second);
        i = j++;
    }
    cout << (min_dist == INF? -1 : min_dist) << endl;
    return 0;
}