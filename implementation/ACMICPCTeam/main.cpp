#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

#define NMax (500)

typedef bitset<NMax> SkillSet;

int main() {
    int n, m;
    cin >> n >> m;
    vector<SkillSet> person(n);
    for (int i=0; i<n; ++i)
        cin >> person[i];

    int n_topics = -1, n_ways = 1;
    for (int i=0; i < n-1; ++i)
        for (int j=i+1; j<n; ++j) {
            int cur = (int)(person[i] | person[j]).count();
            if (cur > n_topics)
                n_topics = cur, n_ways = 1;
            else if (cur == n_topics)
                ++n_ways;
        }
    cout << n_topics << endl << n_ways << endl;
    return 0;
}