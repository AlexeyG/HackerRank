#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w, 0));
    int surface = 0;
    for (int r = 0; r < h; ++r)
        for (int c = 0; c < w; ++c) {
            cin >> a[r][c];
            if (a[r][c] > 0)
                surface += 2;  // top and bottom surfaces.
        }

    for (int r = 0; r < h; ++r)
        for (int c = 0; c < w; ++c) {
            int top = (r == 0 ? 0 : a[r - 1][c]);
            int bottom = (r == h - 1 ? 0 : a[r + 1][c]);
            int left = (c == 0 ? 0 : a[r][c - 1]);
            int right = (c == w - 1 ? 0 : a[r][c + 1]);

            surface += max(0, a[r][c] - left);
            surface += max(0, a[r][c] - right);
            surface += max(0, a[r][c] - top);
            surface += max(0, a[r][c] - bottom);
        }
    cout << surface << endl;
    return 0;
}