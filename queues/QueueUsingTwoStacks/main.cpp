#include <iostream>
#include <stack>

std::stack<int> s1, s2;

void move() {
    if (s2.empty())
        while (!s1.empty())
            s2.push((int &&) s1.top()), s1.pop();
}

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int x;
            std::cin >> x;
            s1.push(x);
        } else if (type == 2) {
            move();
            s2.pop();
        }
        else if (type == 3) {
            move();
            std::cout << s2.top() << std::endl;
        }
    }
    return 0;
}