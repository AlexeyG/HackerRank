#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#define MIN_LENGTH (6L)

#define DIGIT   ("0123456789")
#define LOWER   ("abcdefghijklmnopqrstuvwxyz")
#define UPPER   ("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
#define SPECIAL ("!@#$%^&*()-+")

bool is(const char ch, const string &chars) {
    return chars.find(ch) != string::npos;
}

int main() {
    int t;
    string password;
    cin >> t;
    cin >> password;
    bool has_upper, has_lower, has_special, has_digit;
    has_upper = has_lower = has_special = has_digit = false;
    for (auto ch: password) {
        has_upper |= is(ch, UPPER);
        has_lower |= is(ch, LOWER);
        has_digit |= is(ch, DIGIT);
        has_special |= is(ch, SPECIAL);
    }

    long needed = long(!has_upper) + long(!has_lower) + long(!has_digit) + long(!has_special);
    cout << max(MIN_LENGTH - (long)password.length(), needed) << endl;

    return 0;
}