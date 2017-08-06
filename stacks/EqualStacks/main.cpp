#include <iostream>
#include <vector>

int main() {
    int n1, n2, n3;
    int h1, h2, h3;
    h1 = h2 = h3 = 0;
    std::cin >> n1 >> n2 >> n3;
    std::vector<int> s1(n1), s2(n2), s3(n3);
    for (int i = 0; i < n1; ++i) {
        std::cin >> s1[n1 - i - 1];
        h1 += s1[n1 - i - 1];
    }
    for (int i = 0; i < n2; ++i) {
        std::cin >> s2[n2 - i - 1];
        h2 += s2[n2 - i - 1];
    }
    for (int i = 0; i < n3; ++i) {
        std::cin >> s3[n3 - i - 1];
        h3 += s3[n3 - i - 1];
    }

    int max_h = std::max(std::max(h1, h2), h3);
    while (h1 != max_h || h2 != max_h || h3 != max_h) {
        if (h1 == max_h) {
            h1 -= s1.back();
            s1.pop_back();
        } else if (h2 == max_h) {
            h2 -= s2.back();
            s2.pop_back();
        } else if (h3 == max_h) {
            h3 -= s3.back();
            s3.pop_back();
        }
        max_h = std::max(std::max(h1, h2), h3);
    }
    std::cout << max_h << std::endl;
    return 0;
}