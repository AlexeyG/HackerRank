#include <iostream>
#include <string>

int check(const std::string &str) {
    int i, j;
    i = 0, j = str.length() - 1;
    while (i < j) {
        if (str[i] != str[j])
            break;
        ++i, --j;
    }

    if (i >= j)
        return -1;
    int i_orig = i, j_orig = j;

    if (i + 1 <= j && str[i + 1] == str[j]) {
        ++i;
        while (i < j) {
            if (str[i] != str[j])
                break;
            ++i, --j;
        }
    }
    if (i >= j)
        return i_orig;

    i = i_orig, j = j_orig;
    if (i <= j - 1 && str[i] == str[j - 1]) {
        --j;
        while (i < j) {
            if (str[i] != str[j])
                break;
            ++i, --j;
        }
    }
    if (i >= j)
        return j_orig;

    return -1;
}

int main() {
    std::string str;
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> str;
        std::cout << check(str) << std::endl;
    }
    return 0;
}