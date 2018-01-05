#include <vector>
#include <iostream>

int main() {
    int n, m, s;
    std::cin >> s >> n >> m;
    std::vector<int> keyboard(n), usb(m);
    int max = -1;
    for (int i = 0; i < n; ++i)
        std::cin >> keyboard[i];
    for (int i = 0; i < m; ++i)
        std::cin >> usb[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (keyboard[i] + usb[j] <= s && max < keyboard[i] + usb[j])
                max = keyboard[i] + usb[j];
    std::cout << max << std::endl;
    return 0;
}
