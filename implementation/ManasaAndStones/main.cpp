#include <iostream>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        set<int> nums;
        for (int i = 0; i < n; ++i)
            nums.insert(i * a + (n - 1 - i) * b);
        for (auto num : nums)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}