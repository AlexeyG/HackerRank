// https://www.hackerrank.com/challenges/a-chessboard-game-1
// Classic minimax

#include <iostream>
#include <array>

#define NMax (15)
#define NSteps (4)

// Passes tests even without memorisation, apparently
std::array<std::array<short, NMax>, NMax> mem;

int d_row[4] = {+1, -1, -2, -2};
int d_col[4] = {-2, -2, +1, -1};

bool can_win(int row, int col) {
    if (mem[row][col] >= 0)
        return mem[row][col] == 1;

    for (int i = 0; i < NSteps; ++i)
        if (row + d_row[i] >= 0 && row + d_row[i] < NMax)
            if (col + d_col[i] >= 0 && col + d_col[i] < NMax)
                if (!can_win(row + d_row[i], col + d_col[i])) {
                    mem[row][col] == 1;
                    return true;
                }
    mem[row][col] == 0;
    return false;
}

int main() {
    for (int row = 0; row < NMax; ++row)
        for (int col = 0; col < NMax; ++col)
            mem[row][col] = -1;
    int t;
    std::cin >> t;
    while (t--) {
        int row, col;
        std::cin >> col >> row;
        std::cout << (can_win(--row, --col) ? "First" : "Second") << std::endl;
    }
    return 0;
}