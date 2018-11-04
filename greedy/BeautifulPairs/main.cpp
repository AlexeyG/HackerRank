#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> a, b;
    set<int> nums;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        auto it = a.insert(a.begin(), make_pair(t, 0));
        a[t] = it->second + 1;
        nums.insert(t);
    }
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        auto it = b.insert(b.begin(), make_pair(t, 0));
        b[t] = it->second + 1;
        nums.insert(t);
    }
    int n_disjoint = 0, n_possible_a = 0, n_possible_b = 0;
    for (auto num : nums) {
        auto it_a = a.find(num), it_b = b.find(num);
        if (it_a == a.end())
            n_possible_a += it_b->second;
        else if (it_b == b.end())
            n_possible_b += it_a->second;
        else {
            int val = min(it_a->second, it_b->second);
            n_disjoint += val;
            n_possible_a += it_a->second - val;
            n_possible_b += it_b->second - val;
        }
    }
    if (n_possible_b)
        ++n_disjoint;
    else
        --n_disjoint;
    cout << n_disjoint << endl;

    return 0;
}