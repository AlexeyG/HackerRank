#include <string>
#include <iostream>

int main() {
    int n;
    std::string path;
    std::cin >> n >> path;
    int i = 0, cnt = 0;
    int d = 0;
    bool in_valley = false;
    for (int i = 0; i < n; ++i) {
        if (path[i] == 'D')
            --d;
        if (path[i] == 'U')
            ++d;
        if (d < 0) {
            if (!in_valley)
                ++cnt;
            in_valley = true;
        }
        else
            in_valley = false;
    }
    std::cout << cnt << std::endl;
    return 0;
}
