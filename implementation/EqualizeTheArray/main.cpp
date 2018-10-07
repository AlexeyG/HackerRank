#include <iostream>
#include <vector>

using namespace std;

#define NMax (100)

int main() {
    vector<int> cnt(NMax, 0);
    int n;
    cin >> n;
    int overall_max = -1;
    for (int i=0; i<n; ++i) {
        int tmp;
        cin >> tmp;
        overall_max = max(overall_max, ++cnt[--tmp]);
    }
    cout << (n - overall_max) << endl;

    return 0;
}