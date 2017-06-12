// https://www.hackerrank.com/challenges/recursive-digit-sum

#include <iostream>
#include <string>

unsigned long long get_digit_sum(const std::string &str) {
    unsigned long long acc = 0;
    for (auto it = str.begin(); it != str.end(); ++it)
        acc += *it - '0';
    return acc;
}

int reduce(unsigned long long num) {
    if (num < 10)
        return num;
    int acc = 0;
    while (num > 0)
        acc += num % 10, num /= 10;
    return (acc < 10) ? acc : reduce(acc);
}

int main() {
    std::string n;
    int k;
    std::cin >> n >> k;
    unsigned long long num = get_digit_sum(n);
    std::cout << reduce(num * k) << std::endl;
    return 0;
}