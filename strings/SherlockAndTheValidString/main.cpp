#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool is_valid(const string &str) {
    unordered_map<char, int> cnt;
    for (auto ch : str)
        cnt[ch] = (cnt.find(ch) == cnt.end() ? 0 : cnt[ch]) + 1;

    unordered_map<int, int> freq;
    for (auto p : cnt)
        freq[p.second] = (freq.find(p.second) == freq.end() ? 0 : freq[p.second]) + 1;

    int max_freq = -1, max_freq_cnt = -1;
    for (auto p : freq)
        if ((p.second > max_freq) || (p.second == max_freq && p.first < max_freq_cnt))
            max_freq = p.second, max_freq_cnt = p.first;

    bool other_freq = freq.size() != 1;
    if (!other_freq)
        return true;

    if (freq.size() > 2)
        return false;
    for (auto p : freq)
        if (p.first != max_freq_cnt)
            return ((p.first * p.second - max_freq_cnt) == 1) || (p.first * p.second == 1);
    return false;
}

int main() {
    string str;
    cin >> str;
    cout << (is_valid(str) ? "YES" : "NO") << endl;
    return 0;
}