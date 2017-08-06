#include <iostream>
#include <vector>

int play(const std::vector<int> &s1, const std::vector<int> &s2, unsigned long long x) {
    int moves = 0, i = -1, j = -1;
    long long sum = 0L;
    while ((i + 1 < s1.size()) && (sum + s1[i + 1] <= x))
        sum += s1[++i];
    moves = i + 1;
    //std::cout << "sum = " << sum << " i = " << i << " j = " << j << " moves = " << moves << std::endl;
    while (((j + 1 < s2.size()) && (sum + s2[j + 1] <= x)) || (i >= 0)) {
        if ((j + 1 < s2.size()) && (sum + s2[j + 1] <= x)) {
            sum += s2[++j];
            moves = std::max(moves, i + j + 2);
        } else if (i >= 0)
            sum -= s1[i--];
        //std::cout << "sum = " << sum << " i = " << i << " j = " << j << " moves = " << moves << std::endl;
    }
    return moves;
}

int main() {
    int g;
    std::cin >> g;
    while (g--)
    {
        int n, m;
        unsigned long long x;
        std::cin >> n >> m >> x;
        std::vector<int> s1(n), s2(m);
        for (int i = 0; i < n; ++i)
            std::cin >> s1[i];
        for (int i = 0; i < m; ++i)
            std::cin >> s2[i];
        std::cout << play(s1, s2, x) << std::endl;
    }
    return 0;
}