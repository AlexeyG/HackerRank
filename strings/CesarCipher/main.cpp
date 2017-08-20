#include <iostream>
#include <vector>

int get_position(char ch) {
    if (ch >= 'a' && ch <= 'z')
        return ch - 'a';
    if (ch >= 'A' && ch <= 'Z')
        return (ch - 'A') + ('z' - 'a' + 1);
    return -1;
}

void encrypt(std::string &s, int k) {
    int alpha_size = 'z' - 'a' + 1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = 'a' + (s[i] - 'a' + k) % alpha_size;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = 'A' + (s[i] - 'A' + k) % alpha_size;
    }
}

int main() {
    int n, k;
    std::string s;
    std::cin >> n >> s >> k;
    encrypt(s, k);
    std::cout << s << std::endl;
    return 0;
}