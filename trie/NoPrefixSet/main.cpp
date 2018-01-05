#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#define ALPHA (10)

typedef struct Node {
    int n_words;
    bool has_children;
    Node* child[ALPHA];

    Node() {
        n_words = 0;
        has_children = false;
        memset(child, 0, sizeof(Node*) * ALPHA);
    };
} Node;

void add_word(Node *root, const string &word, int pos) {
    //cout << word << " " << pos << " (" << root << ")" << endl;
    if (pos > word.length())
        return;
    if (pos == word.length()) {
        ++root->n_words;
        return;
    }
    char ch = word[pos] - 'a';
    if (root->child[ch] == NULL) {
        root->child[ch] = new Node();
        root->has_children = true;
    }
    add_word(root->child[ch], word, pos + 1);
};

bool check_has_no_prefix(Node *root, const string &word, int pos) {
    if (root == NULL)
        return true;
    if (pos > word.length())
        return true;
    if (pos == word.length() && root->n_words > 0)
        return false;
    if (pos < word.length() && root->n_words > 0)
        return false;
    return check_has_no_prefix(root->child[word[pos] - 'a'], word, pos + 1);
};

bool check_is_not_prefix(Node *root, const string &word, int pos) {
    if (root == NULL)
        return true;
    if (pos > word.length())
        return true;
    if (pos == word.length() && root->has_children > 0)
        return false;
    return check_is_not_prefix(root->child[word[pos] - 'a'], word, pos + 1);
};

bool check(Node *root, const string &word, int pos) {
    return check_is_not_prefix(root, word, pos) && check_has_no_prefix(root, word, pos);
}

int main() {
    int n;
    cin >> n;
    string word;
    Node *root = new Node();
    for (int i = 0; i < n; ++i) {
        cin >> word;
        if (!check(root, word, 0))  {
            cout << "BAD SET" << endl << word << endl;
            return 0;
        }
        add_word(root, word, 0);
    }
    cout << "GOOD SET" << endl;

    return 0;
}