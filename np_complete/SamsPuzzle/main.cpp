#include <iostream>
#include <vector>
#include <array>
#include <tuple>
#include <ctime>
#include <cmath>
#include <queue>
#include <numeric>
#include <map>
#include <functional>

#define NMax (30)
#define MaxStep (500)
#define MaxTime (2000000)
#define FracConstruct (0.7)
#define MaxTime1 (FracConstruct * MaxTime)
#define MaxTime2 (MaxTime)
#define PathBudget (10)

typedef std::array<std::array<int, NMax>, NMax> squareT;
typedef std::tuple<int, int, int> stepT;
typedef std::tuple<int, int, int, int, int> backtrackT;

squareT sq, buf, n_rotations;
std::vector<stepT> cur_steps;

size_t start_time;

void print_square(int n) {
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++ col)
            std::cerr << sq[row][col] << " ";
        std::cerr << std::endl;
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

bool should_terminate(int max_time) {
    return clock() - start_time > max_time;
}

std::pair<int, int> find_number(int n, int num) {
    for (int row = 0; row < n; ++row)
        for (int col = 0; col < n; ++col)
            if (sq[row][col] == num)
                return {row, col};
    return {-1, -1};
};

bool can_rotate(const std::vector<std::vector<bool>> &is_placed, int top_row, int left_col, int len) {
    for (int row = top_row; row < top_row + len; ++row)
        for (int col = left_col; col < left_col + len; ++col)
            if (is_placed[row][col])
                return false;
    return true;
}

bool is_next_placed(int n, int row, int col, const std::vector<std::vector<bool>> &is_placed, bool minimise) {
    return (minimise && (row == 0 || is_placed[row - 1][col]) && (col == 0 || is_placed[row][col - 1])) ||
           (!minimise && (row == n - 1 || is_placed[row + 1][col]) && (col == n - 1 || is_placed[row][col + 1]));
}

bool find_path(int n,
               const std::vector<std::vector<bool>> &is_placed,
               std::pair<int, int> src,
               std::vector<stepT> &path,
               bool minimise,
               int budget,
               int& dest_row,
               int& dest_col) {
    int src_row, src_col;
    std::tie(src_row, src_col) = src;
    std::queue<stepT> q;
    std::map<std::pair<int, int>, backtrackT> backtrack;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

    q.emplace(0, src_row, src_col);
    visited[src_row][src_col] = true;
    backtrack[std::make_pair(src_row, src_col)] = std::make_tuple(-1, -1, -1, -1, -1);

    while (!q.empty()) {
        int time, cur_row, cur_col;
        std::tie(time, cur_row, cur_col) = q.front();
        if (time > budget)
            return false;
        //std::cout << "BFS at " << cur_row << " " << cur_col << std::endl;
        q.pop();
        visited[cur_row][cur_col] = true;

        if (is_next_placed(n, cur_row, cur_col, is_placed, minimise)) {
            std::function<void(int,int)> track = [&] (int row, int col) {
                int rot_row, rot_col, len, old_row, old_col;
                std::tie(rot_row, rot_col, len, old_row, old_col) = backtrack[{row, col}];
                if (rot_row == -1 || rot_col == -1 || len == -1 || old_row == -1 || old_col == -1)
                    path.clear();
                else {
                    track(old_row, old_col);
                    path.emplace_back(rot_row, rot_col, len);
                }

            };
            track(cur_row, cur_col);
            dest_row = cur_row, dest_col = cur_col;
            return true;
        }

        for (int rot_row = 0; rot_row <= cur_row; ++rot_row)
            for (int rot_col = 0; rot_col <= cur_col; ++rot_col) {
                int min_len = std::max(std::max(cur_row - rot_row + 1, cur_col - rot_col + 1), 2);
                int max_len = std::min(n - rot_row, n - rot_col);
                for (int len = min_len; len <= max_len; ++len)
                    if (can_rotate(is_placed, rot_row, rot_col, len)) {
                        int row_offset = cur_row - rot_row, col_offset = cur_col - rot_col;
                        int new_row = rot_row + col_offset, new_col = rot_col + len - row_offset - 1;
                        if (!visited[new_row][new_col]) {
                            visited[new_row][new_col] = true;
                            q.emplace(time + 1, new_row, new_col);
                            backtrack[{new_row, new_col}] = {rot_row, rot_col, len, cur_row, cur_col};
                        }
                    }
            }
    }
    return false;
}

void construct(int n) {
    std::vector<std::vector<bool>> is_placed(n, std::vector<bool>(n, false));
    cur_steps.clear();
    int i = 1, j = n * n, step = 0;
    while (i <= j) {
        step++;
        if (should_terminate(MaxTime1))
            return;
        int src_row, src_col;
        int num = (step & 1) ? i : j;
        std::tie(src_row, src_col) = find_number(n, num);
        if (src_row == -1 && src_col == -1) {
            std::cout << "Unable to find " << num << " with n = " << n << std::endl;
            exit(1);
        }
        std::vector<std::tuple<int, int, int>> path;
        int dest_row, dest_col;
        if (find_path(n, is_placed, {src_row, src_col}, path, step & 1, PathBudget, dest_row, dest_col)) {
            if (cur_steps.size() + path.size() > MaxStep)
                return;
            for (auto step : path) {
                int top_row = std::get<0>(step), left_col = std::get<1>(step), len = std::get<2>(step);
                rotate_cw(top_row, left_col, len);
                cur_steps.push_back(std::make_tuple(top_row + 1, left_col + 1, len));
            }
            is_placed[dest_row][dest_col] = true;
            std::cerr << "placed " << num << std::endl;
        } else {
            std::cerr << "unable to place " << num << std::endl;
            break;
        }
        if (step & 1)
            ++i;
        else
            --j;
    }
}

void bruteforce(int n) {
    int cur_goodness = get_goodness(n);
    while (!should_terminate(MaxTime2) && cur_steps.size() < MaxStep) {
        int best_top_row = -1, best_left_col = -1, best_len = -1;
        for (int top_row = 0; top_row < n; ++top_row)
            for (int left_col = 0; left_col < n; ++left_col)
                for (int len = 2; len <= std::min(n - top_row, n - left_col); ++len) {
                    rotate_cw(top_row, left_col, len);
                    int new_goodness = get_goodness(n);
                    rotate_ccw(top_row, left_col, len);
                    if (new_goodness > cur_goodness) {
                        best_top_row = top_row, best_left_col = left_col, best_len = len;
                        cur_goodness = new_goodness;
                    }
                }

        if (best_top_row != -1 && best_left_col != -1 && best_len != -1)
        {
            rotate_cw(best_top_row, best_left_col, best_len);
            cur_steps.emplace_back(best_top_row + 1, best_left_col + 1, best_len);
        }
    }
}

void print_path(const std::vector<stepT> &path) {
    std::cout << path.size() << std::endl;
    for (auto step : path)
        std::cout << std::get<0>(step) << " " << std::get<1>(step) << " " << std::get<2>(step) << std::endl;
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

    construct(n);
    bruteforce(n);
    print_path(cur_steps);

    print_square(n);
    std::cerr << "goodness: " << get_goodness(n) << std::endl;

    return 0;
}