#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    int shifts = 0;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        int j = i - 1;
        while (j >= 0 && value < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
            ++shifts;
        }
        arr[j + 1] = value;
    }
    cout << shifts << endl;
    return 0;
}