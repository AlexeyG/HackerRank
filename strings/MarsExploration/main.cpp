#include <iostream>
#include <string>

int main() {
    std::string str, goal("SOS");
    std::cin >> str;
    int diff = 0;
    for (int i = 0; i < str.length(); ++i)
        if (str[i] != goal[i % 3])
            ++diff;
    std::cout << diff << std::endl;
    return 0;
}