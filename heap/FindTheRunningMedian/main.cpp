#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>

typedef std::priority_queue<int, std::vector<int>, std::less<int>> MaxHeap;
typedef std::priority_queue<int, std::vector<int>, std::greater<int>> MinHeap;

double get_median(const MaxHeap &less, const MinHeap &greater) {
    int n = less.size() + greater.size();
    if (n == 0)
        return -1;
    if (n % 2 == 0)
        return (less.top() + greater.top()) / 2.0;
    else if (greater.size() > less.size())
        return greater.top();
    else if (less.size() > greater.size())
        return less.top();
    else
        return -10;
}

template<class T>
std::string get_elems(T q) {
    std::vector<int> mem;
    std::stringstream ss;
    while(!q.empty()) {
        ss << q.top() << " ";
        mem.push_back(q.top());
        q.pop();
    }

    for (auto x : mem)
        q.push(x);

    return ss.str();
}

int main() {
    int n, cur;
    std::cin >> n;

    MaxHeap less;
    MinHeap greater;

    while (n--) {
        std::cin >> cur;
        if (less.size() + greater.size() == 0)
            less.push(cur);
        else {
            double before = get_median(less, greater);
            if (cur < before)
                less.push(cur);
            else
                greater.push(cur);

            int diff = less.size() - greater.size();
            if (diff > 0 && less.size() > 0) {
                greater.push(less.top());
                less.pop();
            } else if (diff < 0 && greater.size() > 0) {
                less.push(greater.top());
                greater.pop();
            }

            //std:: cout << "less = " << less.size() << " (" << get_elems(less) << ")" << " greater = " << greater.size() << " (" << get_elems(greater) << ")"  << std::endl;

        }
        std::cout << std::setprecision(1) << std::fixed << get_median(less, greater) << std::endl;
    }
    return 0;
}
