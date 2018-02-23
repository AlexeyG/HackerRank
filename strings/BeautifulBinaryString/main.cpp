#include <iostream>
#include <string>
#include <vector>

int resolve(std::string &str) {
    int len = str.length();
    std::vector<int> viol(len, 0);
    int max_viol = 0;
    for (int i = 0; i < len - 1; ++i)
        if (str[i] == '1' && str[i - 1] == '0' && str[i + 1] == '0') {
            ++viol[i - 1], ++viol[i], ++viol[i + 1];
            max_viol = std::max(max_viol, std::max(viol[i - 1], std::max(viol[i], viol[i + 1])));
        }

    int changes = 0;
    if (max_viol != 0)
        for (int i = 0; i < len; ++i)
            if (viol[i] == max_viol) {
                str[i] = (1 - (str[i] - '0')) + '0', ++changes;
                break;
            }


    return changes;
}

int main() {
    int l;
    std::cin >> l;
    std::string str;
    std::cin >> str;
    int cur, total = 0;
    while ((cur = resolve(str)) != 0)
        total += cur;
    std::cout << total << std::endl;
    return 0;
}