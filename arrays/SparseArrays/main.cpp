#include <iostream>
#include <string>

#define NMax (256)

struct TrieNode {
    TrieNode() {
        n_words = 0;
        for (int i = 0; i < NMax; ++i)
            child[i] = nullptr;
    };

    int n_words;
    struct TrieNode *child[NMax];

} root;

void add_to_trie(TrieNode &node, const std::string& str, int pos) {
    int len = str.length();
    if (pos == len) {
        ++node.n_words;
        //std::cout << "inc!" << std::endl;
    }
    else {
        char ch = str[pos];
        if (node.child[ch] == nullptr)
            node.child[ch] = new TrieNode();
        add_to_trie(*node.child[ch], str, pos + 1);
    }
}

int get_count(TrieNode &node, const std::string& str, int pos) {
    int len = str.length();
    if (pos == len) {
        //std::cout << "hit node " << node.n_words << std::endl;
        return node.n_words;
    }
    else {
        char ch = str[pos];
        if (node.child[ch] == nullptr)
            return 0;
        return get_count(*node.child[ch], str, pos + 1);
    }
}

int main() {
    int n, q;
    std::string str;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> str;
        add_to_trie(root, str, 0);
    }
    std::cin >> q;
    while (q--) {
        std::cin >> str;
        std::cout << get_count(root, str, 0) << std::endl;
    }
    return 0;
}