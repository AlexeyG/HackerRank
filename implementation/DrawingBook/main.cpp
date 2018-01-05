#include <iostream>

int main() {
    int n, p;
    std::cin >> n >> p;
    int a = (p - 1) / 2 + (p - 1) % 2;
    int e = (n != p) ? n & 1 : 0;
    int b = (n - p - e) / 2 + (n - p - e) % 2;
    //std::cout << a << " " << b << std::endl;

    std::cout << ((a < b) ? a : b) << std::endl;
    return 0;
}
