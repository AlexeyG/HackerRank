#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    int page = 1;
    while (n--) {
        int a;
        cin >> a;
        //cout << "new ch" << endl;
        int ex = 1;
        while (a >= k) {
            if (page >= ex && page <= ex + k - 1) {
                //cout << "page = " << page << " ex in [" << ex << " " << (ex + k - 1) << "]" << endl;
                ++cnt;
            }
            a -= k, ++page, ex += k;
        }
        if (a > 0) {
            if (page >= ex && page <= ex + a - 1) {
                //cout << "page = " << page << " ex in [" << ex << " " << (ex + a - 1) << "]" << endl;
                ++cnt;
            }
            ++page;
        }
    }
    cout << cnt << endl;
    return 0;
}