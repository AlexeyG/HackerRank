#include <iostream>
#include <tuple>
#include <iomanip>
#include <vector>

using namespace std;

bool is_leap_year_gregorian(int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

bool is_leap_year_julian(int year) {
    return year % 4 == 0;
}

bool is_leap_year(int year) {
    return ((year >= 1700) && (year <= 1917) && is_leap_year_julian(year)) ||
           ((year >= 1919) && is_leap_year_gregorian(year));
}

pair<int, int> get_date_month(int year, int day) {
    std::vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year))
        days[1] = 29;

    int month = 0; --day;
    while (day >= days[month]) {
        day -= days[month], ++month;
        if ((year == 1918) && (month == 1))
            day += 13;
    }
    ++month, ++day;
    return pair<int, int>(day, month);
}

int main() {
    int day, month, year;
    cin >> year;
    tie(day, month) = get_date_month(year, 256);
    cout << setw(2) << setfill('0') << day << "." << setw(2) << setfill('0') << month << "." << year << endl;
    return 0;
}