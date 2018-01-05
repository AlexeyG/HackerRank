#include <iostream>
#include <sstream>
#include <numeric>
#include <string>
#include <set>

using namespace std;

bool check(const string& str) {
    for (int i = 1; i < str.length(); ++i)
        if (str[i] == str[i - 1])
            return false;
    return true;
}

int get_ans(const string& str, char ch1, char ch2) {
    int len = 0;
    char past = 0;
    for (auto cur : str)
        if (cur == ch1 || cur == ch2) {
            ++len;
            if (past == cur)
                return -1;
            past = cur;
        }
    return len;
}

int get_max(string str) {
    int ans = 0;
    set<char> chars(str.begin(), str.end());
    for (auto ch1 = chars.begin(); ch1 != chars.end(); ++ch1)
        for (auto ch2 = ch1; ch2 != chars.end(); ++ch2)
            if (ch1 != ch2)
                ans = max(ans, get_ans(str, *ch1, *ch2));
    return ans;
}

int main() {
    int n;
    string str;
    cin >> n >> str;
    cout << get_max(str) << endl;
    return 0;
}