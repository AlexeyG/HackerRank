#include <iostream>
#include <set>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<long long> p;
    long long ans = numeric_limits<long long>::max();
    while (n--) {
        long long price;
        cin >> price;
        auto it = p.lower_bound(price);
        if (it != p.end())
            ans = min(ans, *it - price);
        p.insert(price);
    }
    cout << ans << endl;
    return 0;
}