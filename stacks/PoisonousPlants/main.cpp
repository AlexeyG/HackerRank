#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];

    stack<pair<int, int>> st;
    int max_pop = -1;
    for (int i = n - 1; i >= 0; --i) {
        int pop = 0;
        while (!st.empty() && st.top().first > p[i]) {
            pop = max(pop + 1, st.top().second);
            st.pop();
        }
        st.emplace(p[i], pop);
        max_pop = max(pop, max_pop);
    }
    cout << max_pop << endl;
    return 0;
}