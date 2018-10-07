#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    set<int> left, right;
    int n, d;
    cin >> n >> d;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        right.insert(nums[i]);
    }
    int cnt = 0;
    for (int a : nums) {
        right.erase(a);
        if (left.find(a - d) != left.end() && right.find(a + d) != right.end())
            ++cnt;
        left.insert(a);
    }
    cout << cnt << endl;
    return 0;
}