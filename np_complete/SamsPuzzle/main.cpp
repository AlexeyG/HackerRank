#include <iostream>
#include <vector>
#include <array>
#include <tuple>
#include <ctime>
#include <cmath>

#define NMax (30)
#define MaxStep (10)
#define MaxTime (1500000)

typedef std::array<std::array<int, NMax>, NMax> squareT;

squareT sq, buf, n_rotations;
int max_goodness = -1;
std::vector<std::tuple<int, int, int>> max_goodness_steps;
std::vector<std::tuple<int, int, int>> cur_steps;

size_t start_time;

void print_square(int n) {
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++ col)
            std::cout << sq[row][col] << " ";
        std::cout << std::endl;
    }
}

int get_goodness(int n) {
    int good = 0;
    for (int row = 0; row < n; ++row)
        for (int col1 = 0; col1 < n; ++col1)
            for (int col2 = col1 + 1; col2 < n; ++col2)
                if (sq[row][col1] < sq[row][col2])
                    ++good;

    for (int col = 0; col < n; ++col)
        for (int row1 = 0; row1 < n; ++row1)
            for (int row2 = row1 + 1; row2 < n; ++row2)
                if (sq[row1][col] < sq[row2][col])
                    ++good;

    return good;
}

void rotate_cw(int top_row, int left_col, int width) {
    //std::cout << "CW : (" << top_row << ", " << left_col << ") width " << width << std::endl;
    for (int col_offset = 0; col_offset < width; ++col_offset)
        for (int row_offset = 0; row_offset < width ; ++row_offset)
            buf[top_row + col_offset][left_col + width - row_offset - 1] = sq[top_row + row_offset][left_col + col_offset];

    for (int row_offset = 0; row_offset < width ; ++row_offset)
        for (int col_offset = 0; col_offset < width; ++col_offset)
             sq[top_row + row_offset][left_col + col_offset] = buf[top_row + row_offset][left_col + col_offset];
}

void rotate_ccw(int top_row, int left_col, int width) {
    for (int col_offset = 0; col_offset < width; ++col_offset)
        for (int row_offset = 0; row_offset < width ; ++row_offset)
            buf[top_row + width - col_offset - 1][left_col + row_offset] = sq[top_row + row_offset][left_col + col_offset];

    for (int row_offset = 0; row_offset < width ; ++row_offset)
        for (int col_offset = 0; col_offset < width; ++col_offset)
            sq[top_row + row_offset][left_col + col_offset] = buf[top_row + row_offset][left_col + col_offset];
}

bool should_terminate() {
    return clock() - start_time > MaxTime;
}

double get_probability(int delta, int n) {
    if (delta > 0)
        return 1.0;
    delta--;
    return exp((double)delta / ((n * n) * (n - 1)));
}

bool pick(double prob) {
    //std::cout << "prob " << prob << std::endl;
    return rand() <= prob;
}

void search(int n, int step, int last_goodness) {
    if (step > MaxStep)
        return;

    int goodness = get_goodness(n);
    //std::cout << step << " : " << goodness << " " << max_goodness << std::endl;
    //print_square(n);
    //std::cout << std::endl;
    if (pick(1.0 - get_probability(goodness - last_goodness, n)))
        return;
    if (goodness > max_goodness) {
        max_goodness = goodness;
        max_goodness_steps = cur_steps;
        //std::cout << max_goodness << std::endl;
    }

    for (int top_row = 0; top_row < n; ++top_row)
        for (int left_col = 0; left_col < n; ++left_col)
            for (int width = 2; width <= std::min(n - top_row, n - left_col); ++width) {
                int made_steps = 0;
                while (n_rotations[top_row][left_col] < 4) {
                    if (should_terminate())
                        return;
                    ++made_steps;
                    n_rotations[top_row][left_col]++;
                    rotate_cw(top_row, left_col, width);
                    cur_steps.push_back(std::make_tuple(top_row + 1, left_col + 1, width));
                    search(n, step + 1, goodness);
                }
                while (made_steps--) {
                    cur_steps.pop_back();
                    rotate_ccw(top_row, left_col, width);
                    --n_rotations[top_row][left_col];
                }
            }
}

int main() {
    start_time = clock();
    int n;
    std::cin >> n;
    for (int row = 0; row < n; ++row)
        for (int col = 0; col < n; ++col) {
            std::cin >> sq[row][col];
            n_rotations[row][col] = 0;
        }

    search(n, 0, get_goodness(n));
    std::cout << max_goodness_steps.size() << std::endl;
    for (auto it = max_goodness_steps.begin(); it != max_goodness_steps.end(); ++it)
        std::cout << std::get<0>(*it) << " " << std::get<1>(*it) << " " << std::get<2>(*it) << std::endl;

    return 0;
}