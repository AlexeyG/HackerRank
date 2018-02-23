#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int get_n_unique(const string &str) {
    unordered_set<char> s;
    for (auto ch : str)
        s.insert(ch);
    return s.size();
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        cout << get_n_unique(str) << endl;
    }
    return 0;
}