#include <iostream>

using namespace std;

long long solve(int day, int shared_day1=5) {
    int shared = shared_day1;
    int liked;

    long long liked_total = 0;

    while (day--) {
        liked = shared / 2;
        liked_total += liked;
        shared = liked * 3;
    }
    return liked_total;
}

int main() {
    int day;
    cin >> day;
    cout << solve(day) << endl;
    return 0;
}