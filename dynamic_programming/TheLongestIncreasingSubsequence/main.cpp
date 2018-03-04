#include <iostream>
#include <vector>
#include <limits>

#define RMax ((int)1e5 + 1)
#define INF  (numeric_limits<int>::max())
#define NINF (0)

using namespace std;

int solve(const vector<int> &nums) {
    int overall_max = 0, n = nums.size();
    vector<int> dp(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        int a = nums[i - 1];
        int l = 0, r = overall_max + 1;
        //cout << "at " << i << endl;
        while (r - l > 1) {
            int m = (r + l) / 2;
            //cout << "   l = " << l << " r = " << r << " m = " << m << endl;
            if (dp[m] >= a)
                r = m;
            else
                l = m;
        }
        int j = l;
        //cout << "   j = " << j << "  dp[j] = " << dp[j] << " dp[j + 1] = " << dp[j + 1] << endl;
        if (dp[j + 1] > a || dp[j + 1] == -1)
            dp[j + 1] = a;
        overall_max = max(overall_max, j + 1);
    }
    return overall_max;
}

typedef struct Node {
    Node *left, *right;
    int start, end;
    int ans;

    Node(int start, int end, int ans = 0) : start(start), end(end), ans(0), left(nullptr), right(nullptr) {}
} Node;

int get_node_ans(Node *node) {
    if (node == nullptr)
        return NINF;
    return node->ans;
}

Node *construct_st(Node *root, int qs, int qe, const vector<int> &nums) {
    if (qs >= qe)
        return nullptr;

    if (root == nullptr)
        root = new Node(qs, qe);

    if (qe == qs + 1)
        root->ans = nums[qs];
    else {
        int mid = (qs + qe) / 2;
        root->left = construct_st(root->left, qs, mid, nums);
        root->right = construct_st(root->right, mid, qe, nums);
        root->ans = max(get_node_ans(root->left), get_node_ans(root->right));
    }

    return root;
}

bool segment_contains(int a, int b, int c) {
    return a <= c && c <= b && a <= b;
}

int query_st(Node *root, int qs, int qe) {
    if (root == nullptr)
        return NINF;

    int ans = NINF;
    if (qs <= root->start && root->end <= qe)      // node inside [qs, qe)
        ans = root->ans;
    else if (segment_contains(root->start, root->end, qs) || segment_contains(root->start, root->end, qe)) {
        ans = max(ans, query_st(root->left, qs, qe));
        ans = max(ans, query_st(root->right, qs, qe));
    }
    return ans;
}

void update_st(Node *root, int pos, int val) {
    if (root == nullptr)
        return;
    if (pos < root->start || pos >= root->end)
        return;

    if (pos == root->start && root->end == pos + 1)
        root->ans = val;
    else {
        update_st(root->left, pos, val);
        update_st(root->right, pos, val);
        root->ans = max(get_node_ans(root->left), get_node_ans(root->right));
    }
}

void test_st(int n, int m, int mod = 10) {
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % mod;
    Node *root = construct_st(nullptr, 0, RMax, arr);

    for (int i = 0; i < m; ++i) {
        int l = rand() % n, r = rand() % n;
        if (l > r)
            l ^= r, r ^= l, l ^= r;
        ++r;
        int q_ans = query_st(root, l, r);
        int bf_ans = -1;
        for (int k = l; k < r; ++k)
            bf_ans = max(bf_ans, arr[k]);
        if (bf_ans != q_ans) {
            cout << "!!!! BUG" << endl;
            cout << "l = " << l << " r = " << r << endl;
            cout << "q_ans = " << q_ans << " bf_ans = " << bf_ans << endl;
            for (int k = 0; k < n; ++k)
                cout << arr[k] << " ";
            cout << endl;
        }

        int j = rand() % n;
        arr[j] = rand() % mod;
        update_st(root, j, arr[j]);
    }
}

int solve_st(const vector<int> &nums) {
    vector<int> arr(RMax, NINF);
    Node *root = construct_st(nullptr, 0, RMax, arr);

    int overall_max = 1;
    update_st(root, nums[0], 1);
    for (int i = 1; i < nums.size(); ++i) {
        //cout << "at i = " << i << " nums[i] = " << nums[i] << " query = " << query_st(root, 0, nums[i]) << endl;
        int cur = query_st(root, 0, nums[i]) + 1;
        if (cur > overall_max)
            overall_max = cur;
        if (query_st(root, nums[i], nums[i] + 1) < cur)
            update_st(root, nums[i], cur);
    }
    return overall_max;
}

int main() {
    //test_st(500, 10000, 100000);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    //cout << solve(nums) << endl;
    cout << solve_st(nums) << endl;
    return 0;
}