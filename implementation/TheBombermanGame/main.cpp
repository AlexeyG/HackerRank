#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <map>

using namespace std;

vector<vector<int>> normalize(const vector<vector<int>> &a, int time) {
    int rows = a.size();
    int cols = a[0].size();

    vector<vector<int>> b(rows, vector<int>(cols, -1));
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            b[r][c] = (a[r][c] > 0 ? a[r][c] - time : -1);
    return b;

}

void print(const vector<vector<int>> &board) {
    for (auto row : board) {
        for (auto elem : row)
            cout << (elem < 0 ? '.' : 'O');
        cout << endl;
    }
}

void step(vector<vector<int>> &a, int time, bool plant) {
    int rows = a.size();
    int cols = a[0].size();

    vector<vector<int>> b(rows, vector<int>(cols, -1));
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            b[r][c] = a[r][c];

    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c) {
            if (a[r][c] == time) {
                b[r][c] = -1;
                if (r > 0)
                    b[r - 1][c] = -1;
                if (r < rows - 1)
                    b[r + 1][c] = -1;
                if (c > 0)
                    b[r][c - 1] = -1;
                if (c < cols - 1)
                    b[r][c + 1] = -1;
            } else if ((a[r][c] == -1) && plant) {
                b[r][c] = time + 3;
            }
        }

    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            a[r][c] = b[r][c];
}

int main() {
    int rows, cols, n;
    cin >> rows >> cols >> n;

    vector<vector<int>> board(rows, vector<int>(cols, -1));
    for (int r = 0; r < rows; ++r) {
        string str;
        cin >> str;
        for (int c = 0; c < cols; ++c) {
            if (str[c] == 'O')
                board[r][c] = 3;
        }
    }

    map<vector<vector<int>>, int> states;
    map<int, vector<vector<int>>> rev_states;
    int output_time = n;
    for (int time = 1; time <= n; ++time) {
        bool plant = (time % 2 == 0 && time > 0);
        step(board, time, plant);
        vector<vector<int>> key = normalize(board, time);
        rev_states[time] = key;
        auto it = states.find(key);
        if (it == states.end()) {
            states[key] = time;
        }
        else {
            int length = time - it->second;
            output_time = it->second + (n - time) % length;
            //cout << "step " << time << " found loop of length " << length << endl;
            //cout << "output time " << output_time << endl;
            break;
        }
    }
    if (rev_states.find(output_time) == rev_states.end())
        cout << "not found! " << output_time << endl;
    print(rev_states[output_time]);

    return 0;
}