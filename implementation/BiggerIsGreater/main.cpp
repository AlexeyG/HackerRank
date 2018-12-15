#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool solve(string &str) {
    for (int i = str.length() - 2; i >= 0; --i) {
        int next_min = -1;
        for (int j = i + 1; j < str.length(); ++j)
            if (str[j] > str[i] && (next_min == -1 || str[j] < str[next_min]))
                next_min = j;
        if (next_min >= 0) {
            swap(str[i], str[next_min]);
            sort(str.begin() + i + 1, str.end());
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << (solve(str) ? str : "no answer") << endl;
    }
    return 0;
}