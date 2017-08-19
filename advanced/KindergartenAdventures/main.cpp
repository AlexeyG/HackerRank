#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

struct Node {
    bool isStart = false;
    int time = 0;
    int index = 0;

    Node(int _time, bool _isStart, int _index)
            : isStart(_isStart), time(_time), index(_index)
    {}

    bool operator< (const Node &other) const {
        return  (time < other.time) ||
                ((time == other.time) && (isStart < other.isStart)) ||
                ((time == other.time) && (isStart == other.isStart) && (index > other.index));
    }
};

int solve(const std::set<Node> &tree) {
    int max_depth = -1, max_depth_index = -1;
    int depth = 0;
    for (auto node : tree) {
        if (node.isStart)
        {
            ++depth;
            if (depth > max_depth) {
                max_depth = depth;
                max_depth_index = node.time;
            }
        } else
            --depth;
        //std::cout << "index = " << node.index << " isStart = " << node.isStart << " time = " << node.time << " depth = " << depth << std::endl;
    }
    return max_depth_index;
}

int main() {
    int n;
    std::cin >> n;
    std::set<Node> tree;
    for (int i = 0; i < n; ++i) {
        int t, low, high;
        std::cin >> t;
        //std::cout << "i = " << i << " t = " << t << std::endl;
        if (t > 0) {
            if (i >= t) {
                low = 0, high = i - t + 1;
                //std::cout << "    low = " << low << " high = " << high << std::endl;
                tree.emplace(low, true, i);
                tree.emplace(high, false, i);
            }
            // [(i + 1) .. (n - x)]
            if (i < n) {
                low = i + 1;
                high = (i >= t) ? n : (i - t + n + 1);
                //std::cout << "    low = " << low << " high = " << high << std::endl;
                tree.emplace(low, true, i);
                tree.emplace(high, false, i);
            }
        } else {
            //std::cout << "    low = " << 0 << " high = " << n << std::endl;
            tree.emplace(0, true, i);
            tree.emplace(n, false, i);
        }
    }

    std::cout << (solve(tree) + 1) << std::endl;

    return 0;
}