#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

#define NMax (2 * 100000)

typedef std::vector<bool> BS;

// 1011 1001
// 0100 0000
//

// -1
// 1001 0001
// 1011 1110
// 1010 1000

char hex2byte(char s) {
    if (s >= '0' && s <= '9')
        return s - '0';
    if (s >= 'A' && s <= 'F')
        return s - 'A' + 10;
    return 0;
}

std::string to_ustring(const BS &bs, int n) {
    std::stringstream ss;
    ss << std::hex << std::uppercase;
    int cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        //std::cout << "i = " << i << " bs[i] = " << bs[i] << std::endl;
        cur = (cur << 1) | bs[i];
        if (i % 8 == 0) {
            ss << cur;
            cur = 0;
        }
    }
    std::string str = ss.str();
    int i = 0;
    while (i < str.length() - 1 && str[i] == '0')
        ++i;
    return str.substr(i);
}

int convert(const std::string &s, BS &bs) {
    int n = s.length();
    for (int i = n - 1; i >= 0; --i) {
        char x = hex2byte(s[i]);
        for (int k = 0; k < 8; ++k) {
            bs.push_back((x & 1) > 0);
            x >>= 1;
        }
    }
    return bs.size();
}

int solve(BS &a, BS &b, BS &c, int n, int k) {
    a.resize(n, false);
    b.resize(n, false);
    c.resize(n, false);
    for (int i = 0; i < n && k >= 0; ++i) {
        if (a[i] && b[i] && c[i])
            continue;
        else if (a[i] && b[i] && !c[i])
            a[i] = b[i] = false, k -= 2;
        else if (a[i] && !b[i] && c[i])
            continue;
        else if (a[i] && !b[i] && !c[i])
            a[i] = false, --k;
        else if (!a[i] && b[i] && c[i])
            continue;
        else if (!a[i] && b[i] && !c[i])
            b[i] = false, --k;
        else if (!a[i] && !b[i] && c[i])
            b[i] = true, --k;
        else if (!a[i] && !b[i] && !c[i])
            continue;
    }
    return k;
}

void minimize(BS &a, BS &b, const BS &c, int n, int k) {
    for (int i = n - 1; i >= 0 && k > 0; --i) {
        if (a[i] && b[i] && c[i])
            a[i] = false, --k;
        else if (a[i] && !b[i] && c[i] && k >= 2)
            a[i] = false, b[i] = true, k -= 2;
    }
}



int main() {
    int q;
    std::cin >> q;
    while (q--) {
        int k;
        std::cin >> k;
        std::string sa, sb, sc;
        BS a, b, c;
        std::cin >> sa >> sb >> sc;
        int la = convert(sa, a);
        int lb = convert(sb, b);
        int lc = convert(sc, c);
        int n = std::max(std::max(la, lb), lc);
        k = solve(a, b, c, n, k);

        if (k < 0)
            std::cout << -1 << std::endl;
        else {
            minimize(a, b, c, n, k);
            std::cout << to_ustring(a, n) << std::endl;
            std::cout << to_ustring(b, n) << std::endl;
            //std::cout << std::endl;
        }
    }
    return 0;
}
