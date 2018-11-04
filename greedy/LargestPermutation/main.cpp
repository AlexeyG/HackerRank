#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>> q;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        q.push(make_pair(arr[i], i));
    }

    for (int i = 0; i < k && !q.empty(); ++i) {
        pair<int, int> top;
        do {
            top = q.top();
            q.pop();
        } while (arr[top.second] != top.first && !q.empty());

        if (arr[top.second] != top.first)
            break;

        //cout << "got " << top.first << endl;

        if (top.second == i) {
            ++k;
            continue;
        }

        swap(arr[i], arr[top.second]);
        q.push(make_pair(arr[top.second], top.second));
    }

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}