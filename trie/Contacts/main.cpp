#include <iostream>
#include <string>

#define ALPHA ('z' - 'a' + 1)

typedef struct Node {
    Node* children[ALPHA];
    bool has_word;
    int total_words;

public:
    Node() {
        for (int i = 0; i < ALPHA; ++i)
            children[i] = nullptr;
        has_word = false;
        total_words = 0;
    }
} Node;

void insert_trie(Node *root, std::string &str) {
    for (int pos = 0; pos != str.length(); ++pos) {
        root->total_words += 1;
        if (root->children[str[pos] - 'a'] == nullptr)
            root->children[str[pos] - 'a'] = new Node();
        root = root->children[str[pos] - 'a'];
    }
    root->total_words += 1;
}

int count_trie(Node *root, std::string &str) {
    for (int pos = 0; pos != str.length() && root != nullptr; ++pos)
        root = root->children[str[pos] - 'a'];
    return (root == nullptr) ? 0 : root->total_words;
}

int main() {
    int n;
    std::string op, name;
    std::cin >> n;

    auto root = new Node();

    while (n--) {
        std::cin >> op >> name;
        if (op == "add")
            insert_trie(root, name);
        else if (op == "find")
            std::cout << count_trie(root, name) << std::endl;
    }
    return 0;
}