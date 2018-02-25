#include <iostream>
#include <map>
#include <vector>

using namespace std;

long long rec(long long state, const vector<long long> &s, map<long long, long long> &mem) {
    auto it = mem.find(state);
    if (it != mem.end())
        return it->second;

    long long ans = 0;
    for (auto new_state : s)
        if (new_state != state && state % new_state == 0)
            ans = max(ans, (state / new_state) * rec(new_state, s, mem)  + 1LL);

    mem[state] = ans;
    return ans;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        long long n;
        int m;
        cin >> n >> m;
        vector<long long> s;
        s.reserve(m);
        for (int i = 0; i < m; ++i) {
            long long candidate;
            cin >> candidate;
            if (n % candidate == 0)
                s.push_back(candidate);
        }
        map<long long, long long> mem;
        cout << rec(n, s, mem) << endl;
    }
    return 0;
}