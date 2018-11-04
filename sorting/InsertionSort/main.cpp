#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> &arr) {
    for (auto a : arr)
        cout << a << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
            swap(arr[j], arr[j - 1]), --j;
        print(arr);
    }

    return 0;
}