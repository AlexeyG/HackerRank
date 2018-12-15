#include <iostream>
#include <map>
#include <string>

using namespace std;

map<int, string> spell = {
        {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"},
        {9, "nine"}, {10, "ten"}, {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"}, {15, "quarter"},
        {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"}, {20, "twenty"}, {30, "half"}};

int main() {
    int hh, mm;
    cin >> hh >> mm;

    if (mm == 0)
        cout << spell[hh] << " o' clock";
    else if (mm == 1)
        cout << spell[mm] << " minute past " << spell[hh];
    else if (mm == 15 || mm == 30)
        cout << spell[mm] << " past " << spell[hh];
    else if (mm <= 20)
        cout << spell[mm] << " minutes past " << spell[hh];
    else if (mm < 30)
        cout << spell[20] << " " << spell[mm - 20] << " minutes past " << spell[hh];
    else if (mm == 45)
        cout << spell[60 - mm] << " to " << spell[hh + 1];
    else if (mm < 40)
        cout << spell[20] << " " << spell[60 - mm - 20] << " minutes to " << spell[(hh + 1)];
    else if (mm == 59)
        cout << spell[1] << " minute to " << spell[(hh + 1)];
    else
        cout << spell[60 - mm] << " minutes to " << spell[(hh + 1)];

    cout << endl;
    return 0;
}