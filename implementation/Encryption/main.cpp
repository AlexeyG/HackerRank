#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.length();
    int sqrt_floor = (int)floor(sqrt((float)len));
    int sqrt_ceil = (int)ceil(sqrt((float)len));
    int rows, cols;
    if (sqrt_floor * sqrt_floor >= len)
        rows = cols = sqrt_floor;
    else if (sqrt_floor * sqrt_ceil >= len)
        rows = sqrt_floor, cols = sqrt_ceil;
    else
        rows = cols = sqrt_ceil;
    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row < rows; ++row)
            if (row * cols + col < len)
                cout << str[row * cols + col];
        cout << " ";
    }
    return 0;
}