#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> score(n);
    vector<int> rank(n);
    rank[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> score[i];
        if (i > 0) {
            if (score[i] == score[i - 1])
                rank[i] = rank[i - 1];
            else
                rank[i] = rank[i - 1] + 1;
        }
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int score_alice;
        cin >> score_alice;
        auto it = lower_bound(score.begin(), score.end(), score_alice, [](int a, int b) { return a > b; });
        //cout << "Alice = " << score_alice << endl;
        //cout << "Lower = " << (*it) << endl;

        if (it == score.end())
            cout << rank[n - 1] + 1 << endl;
        else if (*it == score_alice)
            cout << rank[it - score.begin()] << endl;
        else if ((it == score.begin()) && (score_alice > score[0]))
            cout << 1 << endl;
        else
            cout << rank[it - score.begin()] << endl;
    }
    return 0;
}