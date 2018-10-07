#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define AMax (26)

int main() {
    vector<int> height(AMax, 0);
    for (int i=0; i<AMax; ++i)
        cin >> height[i];

    string word;
    cin >> word;

    int max_height = 0;
    for (auto ch: word)
        max_height = max(max_height, height[ch - 'a']);
    cout << max_height * word.length();
    return 0;
}