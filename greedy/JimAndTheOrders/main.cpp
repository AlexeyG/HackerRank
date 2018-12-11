#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> orders(n);
    for (int i = 0; i < n; ++i) {
        int num, time;
        cin >> num >> time;
        orders[i] = make_tuple(num + time, i + 1, num);
    }
    sort(orders.begin(), orders.end());
    for (auto order : orders)
        cout << get<1>(order) << " ";

    return 0;
}