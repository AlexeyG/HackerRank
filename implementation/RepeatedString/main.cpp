#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    long long n;
    cin >> n;
    long long l = str.length();
    long long full = n / l;
    long long part = n % l;
    long long a_part = 0, a_full = 0;
    for (auto ch : str)
        if (ch == 'a')
            ++a_full;
    for (int i=0; i<part; ++i)
        if (str[i] == 'a')
            ++a_part;
    cout << (full * a_full + a_part) << endl;
    return 0;
}