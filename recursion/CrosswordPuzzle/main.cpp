#include <iostream>
#include <string>
#include <array>
#include <string>
#include <vector>

#define NMax (10)

typedef std::array<std::array<char, NMax>, NMax> boardT;
typedef std::vector<std::string> wordsT;

boardT board;
wordsT words;

std::vector<std::string> split_words(const std::string &line) {
    std::vector<std::string> words;
    int len = line.length(), i = 0;
    while (i < len) {
        int j = i + 1;
        while (j < len && line[j] != ';')
            ++j;
        words.push_back(line.substr(i, j - i));
        i = j + 1;
    }
    return std::move(words);
}

void print_board(const boardT &board) {
    for (int r = 0; r < NMax; ++r) {
        for (int c = 0; c < NMax; ++c)
            std::cout << board[r][c];
        std::cout << std::endl;
    }
}

bool place_words(int ind);

bool is_between(int a, int mi, int ma) {
    return a >= mi && a < ma;
}

bool place_word(int ind, int pos, int row, int col, int drow, int dcol) {
    if (pos >= words[ind].length())
        return place_words(ind + 1);
    if (!is_between(row, 0, NMax) || !is_between(col, 0, NMax))
        return false;
    if (board[row][col] != '-' && board[row][col] != words[ind][pos])
        return false;
    char orig = board[row][col];
    board[row][col] = words[ind][pos];
    if (place_word(ind, pos + 1, row + drow, col + dcol, drow, dcol))
        return true;
    board[row][col] = orig;
    return false;
}

bool place_words(int ind) {
    if (ind >= words.size())
        return true;
    for (int r = 0; r < NMax; ++r)
        for (int c = 0; c < NMax; ++c)
            if (board[r][c] == '-' || board[r][c] == words[ind][0])
                for (int dr = -1; dr <= 1; ++dr)
                    for (int dc = -1; dc <= 1; ++dc)
                        if (std::abs(dr) + std::abs(dc) == 1)
                            if (place_word(ind, 0, r, c, dr, dc))
                                return true;
    return false;
}

int main() {
    std::string line;
    for (int i = 0; i < NMax; ++i) {
        std::cin >> line;
        for (int j = 0; j < NMax; ++j)
            board[i][j] = line[j];
    }
    std::cin >> line;
    words = split_words(line);
    if (place_words(0))
        print_board(board);
    return 0;
}