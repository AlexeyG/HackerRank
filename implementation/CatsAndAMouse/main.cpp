#include <iostream>

int d(int x, int y) {
    if (x > y)
        return x - y;
    return y - x;
}

int main() {
    int q;
    std::cin >> q;
    while (q--) {
        int x, y, z;
        std::cin >> x >> y >> z;
        if (d(x, z) < d(y, z))
            std::cout << "Cat A";
        else if (d(x, z) > d(y, z))
            std::cout << "Cat B";
        else
            std::cout << "Mouse C";
        std::cout << std::endl;
    }
    return 0;
}
