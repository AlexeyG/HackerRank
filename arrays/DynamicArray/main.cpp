#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<int>> arr(n);
    int la = 0;
    while (q--) {
        int type, x, y;
        std::cin >> type >> x >> y;
        if (type == 1)
            arr[(la ^ x) % n].push_back(y);
        else {
            int ind = (la ^ x) % n;
            la = arr[ind][y % arr[ind].size()];
            std::cout << la << std::endl;
        }
    }
    return 0;
}