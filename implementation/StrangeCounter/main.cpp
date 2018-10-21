#include <iostream>
#include <cmath>

using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))

long long get_counter(long long t) {
    long long full_cycles = floor(log2((t - 1) / 3.0 + 1));
    long long full_steps = 3LL * (pow(2LL, full_cycles) - 1LL);
    long long initial_value = 3LL * pow(2LL, full_cycles);
    long long at_t = initial_value - (t - full_steps) + 1LL;

    /*cout << "full cycles " << full_cycles << endl;
    cout << "full steps "<< full_steps << endl;
    cout << "init value "<< initial_value << endl;*/

    return at_t;
}

long long get_counter_slow(long long t) {
    long long prev_init = 3;
    long long cnt = 3;
    --t;
    while (t > 0) {
        --t, --cnt;
        if (cnt == 0) {
            cnt = prev_init * 2;
            prev_init = cnt;
        }
    }
    return cnt;
}

int main() {
    long long t;
    cin >> t;
    /*for (int i = 1; i < 1000; ++i)
        if (get_counter(i) != get_counter_slow(i))
            cout << "!! " << i << endl;*/
    cout << get_counter(t) << endl;
    //cout << get_counter_slow(t) << endl;
    return 0;
}