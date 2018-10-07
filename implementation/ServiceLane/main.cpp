#include <iostream>
#include <vector>
#include <limits>

#define INF (numeric_limits<int>::max())

using namespace std;

typedef struct Node {
    int min;
    Node *left,  *right;
    int left_ind, right_ind;

public:
    Node(int min, Node *left, Node *right, int left_ind, int right_ind)
        : min(min), left(left), right(right), left_ind(left_ind), right_ind(right_ind)
    {}
} Node;

int min_or_inf(Node *node) {
    if (node == nullptr)
        return INF;
    return node->min;
}

Node *build_rmq(const vector<int> &nums, int l, int r) {
    if (l == r)
        return new Node(nums[l], nullptr, nullptr, l, r);
    if (l > r)
        return nullptr;
    int mid = (l + r ) / 2;
    Node *left = build_rmq(nums, l, mid), *right = build_rmq(nums, mid + 1, r);
    int value = min(min_or_inf(left), min_or_inf(right));
    return new Node(value, left, right, l, r);
}

bool in_range(int c, int a, int b) {
    return c >= a && c <= b;
}

bool intersect(int a, int b, int c, int d) {
    // [a ...... b]
    //       [c ...... d]

    //            [a ...... b]
    //       [c ...... d]
    return in_range(c, a, b) || in_range(a, c, d);
}



int rmq(Node *root, int l, int r) {
    if (root == nullptr)
        return INF;
    if (!intersect(l, r, root->left_ind, root->right_ind))
        return INF;
    if (root->left_ind >= l && root->right_ind <= r)
        return root->min;
    int q_left = rmq(root->left, l, r);
    int q_right = rmq(root->right, l, r);
    //cout << "l=" << root->left_ind << " r=" << root->right_ind << " rmq=" << min(q_left, q_right) << endl;
    return min(q_left, q_right);
}

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    Node* root = build_rmq(nums, 0, n - 1);
    while (t--) {
        int l, r;
        cin >> l >> r;
        //cout << "query " << l << " " << r << endl;
        cout << rmq(root, l, r) << endl;
    }
    return 0;
}