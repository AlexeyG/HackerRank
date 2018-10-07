#include <iostream>
#include <vector>

using namespace std;

#define SMax (10000)

int cost_for(int n, vector<int> &costs, int m) {
    if (n == 0)
        return 0;
    if (n <= costs.size())
        return costs[n - 1];
    return (*(costs.end() - 1)) + (n - costs.size()) * m;
}

int main() {
    int p, d, m, s;
    cin >> p >> d >> m >> s;

    // Fill the costs array.
    vector<int> costs;
    int price = p, agg = p;
    do {
        costs.push_back(agg);
        price -= d;
        agg += price;
    } while (price > m);

    // Binary search on the number of games.
    int l = 0, r = (s / m) + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        //cout << "cost for " << mid << " is " << cost_for(mid, costs, m) << endl;
        if (cost_for(mid, costs, m) > s)
            r = mid;
        else
            l = mid;
    }
    cout << l << endl;
    return 0;
}