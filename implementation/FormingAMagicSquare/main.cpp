#include <iostream>
#include <array>
#include <vector>

#define NMax (3)
#define INF (NMax * NMax * NMax * NMax)
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define abs(x) (((x) < 0) ? -(x) : (x))

typedef std::array<std::array<int, NMax>, NMax> SquareT;

int best_so_far = INF;

bool is_magic(const std::vector<int> &rows,
              const std::vector<int> &cols,
              const int sum_diag,
              const int sum_adiag) {
    for (int i = 1; i < NMax; ++i)
        if (rows[0] != rows[i] || rows[i] != cols[i] || cols[0] != cols[i])
            return false;
    return rows[0] == sum_diag && rows[0] == sum_adiag;
}

void print(const SquareT &sq) {
    for (int r = 0; r < NMax; ++r) {
        for (int c = 0; c < NMax; ++c)
            std::cout << sq[r][c] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int rec(SquareT &sq,
        std::vector<bool> &is_avail,
        std::vector<int> &sum_rows,
        std::vector<int> &sum_cols,
        int sum_diag,
        int sum_adiag,
        int row,
        int col,
        int cost) {

    if (cost >= best_so_far)
        return INF;

    if (col == NMax)
        col = 0, ++row;
    //std::cout << row << " " << col << " " << sq[row][col] << std::endl;
    if (row >= NMax) {
        //std::cout << "finish " << cost << " " << is_magic(sum_rows, sum_cols) << std::endl;
        if (is_magic(sum_rows, sum_cols, sum_diag, sum_adiag)) {
            best_so_far = min(best_so_far, cost);
            //std::cout << cost << std::endl;
            //print(sq);
            return cost;
        }
        return INF;
    }

    std::vector<int> values;
    if (is_avail[sq[row][col] - 1])
        values.push_back(sq[row][col]);
    for (int val = 1; val <= NMax * NMax; ++val)
        if (is_avail[val - 1] && val != sq[row][col])
            values.push_back(val);

    int ans = INF;
    for (int val : values) {
        is_avail[val - 1] = false;
        int orig = sq[row][col];
        sq[row][col] = val;
        sum_rows[row] += val;
        sum_cols[col] += val;
        sum_diag += (row == col) ? val : 0;
        sum_adiag += (row == NMax - col - 1) ? val : 0;
        int res = rec(sq,
                      is_avail,
                      sum_rows,
                      sum_cols,
                      sum_diag,
                      sum_adiag,
                      row,
                      col + 1,
                      cost + abs(val - orig));
        ans = min(ans, res);
        sum_diag -= (row == col) ? val : 0;
        sum_adiag -= (row == NMax - col - 1) ? val : 0;
        sum_rows[row] -= val;
        sum_cols[col] -= val;
        sq[row][col] = orig;
        is_avail[val - 1] = true;
    }
    return ans;
}

int main() {
    SquareT sq;
    std::vector<bool> is_avail(NMax * NMax, true);
    std::vector<int> sum_rows(NMax, 0), sum_cols(NMax, 0);
    for (int r = 0; r < NMax; ++r)
        for (int c = 0; c < NMax; ++c)
            std::cin >> sq[r][c];
    std::cout << rec(sq, is_avail, sum_rows, sum_cols, 0, 0, 0, 0, 0) << std::endl;
    return 0;
}
