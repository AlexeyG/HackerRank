#include <iostream>
#include <vector>

using namespace std;

bool is_kaprekar(long long p) {
    long long n_digits = 0, p_copy = p;
    long long split_base = 1;
    while (p_copy)
        ++n_digits, p_copy /= 10, split_base *= 10;
    long long p2 = p * p;

    long long l = p2 / split_base;
    long long r = p2 % split_base;
    if (l + r == p)
        return true;
    return false;
}

vector<int> get_nums(int p, int q) {
    vector<int> nums;
    for (int i = p; i <= q; ++i)
        if (is_kaprekar(i))
            nums.push_back(i);
    return move(nums);
}

int main() {
    int p, q;
    cin >> p >> q;
    vector<int> nums = get_nums(p, q);
    if (nums.empty())
        cout << "INVALID RANGE";
    else
        for (auto a : nums)
            cout << a << " ";
    cout << endl;
    return 0;
}