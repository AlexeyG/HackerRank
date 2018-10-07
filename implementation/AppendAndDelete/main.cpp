#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t;
    int edits;
    cin >> s >> t >> edits;

    int ls = s.length(), lt = t.length();

    int prefix = 0;
    while (prefix < ls && prefix < lt && s[prefix] == t[prefix])
        ++prefix;

    bool outcome = false;
    outcome |= edits >= (ls + lt);  // We can rewrite the entire string s.
    outcome |= (edits >= (ls - prefix + lt - prefix)) && (((edits - (ls - prefix + lt - prefix)) % 2) == 0);

    cout << (outcome ? "Yes" : "No") << endl;
    return 0;
}