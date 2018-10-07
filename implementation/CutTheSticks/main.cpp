#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> cnt;
    while (n--) {
        int num;
        cin >> num;
        auto it = cnt.find(num);
        if (it == cnt.end())
            cnt[num] = 1;
        else
            ++it->second;
    }
    int agg = 0;
    for (auto it = cnt.rbegin(); it != cnt.rend(); ++it)
        it->second += agg, agg = it->second;
    for (auto it : cnt)
        cout << it.second << endl;
    return 0;
}