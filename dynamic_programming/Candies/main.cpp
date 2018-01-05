#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> rating(n), candy(n, 1);
    for (int i = 0; i < n; ++i)
        cin >> rating[i];

    for (int i = 1; i < n; ++i)  // forward
        if (rating[i] > rating[i - 1])
            candy[i] = candy[i - 1] + 1;

    for (int i = n - 2; i >= 0; --i) // backward
        if (rating[i + 1] < rating[i] && candy[i + 1] >= candy[i])
            candy[i] = candy[i + 1] + 1;

    long long ans = accumulate(candy.begin(), candy.end(), 0LL);
    std::cout << ans << std::endl;
    return 0;
}