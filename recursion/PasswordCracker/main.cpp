#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

#define CMax (26)

typedef struct Node {
    Node* children[CMax];
    bool is_word;

    Node() {
        is_word = false;
        for (int i=0; i<CMax; ++i)
            children[i] = nullptr;
    }

} Node;

Node* build_trei(Node* cur, const string& word, int pos=0) {
    if (pos > word.length())
        return cur;
    if (cur == nullptr)
        cur = new Node();
    if (pos == word.length()) {
        cur->is_word = true;
        return cur;
    }
    char next_char = word[pos] - 'a';
    cur->children[next_char] = build_trei(cur->children[next_char], word, pos + 1);
    return cur;
}

void print_path(vector<char> &path) {
    for (auto ch : path)
        cout << ch;
    cout << endl;
}

bool find_path(Node* cur, Node* root, const string &attempt, vector<char> &path, unordered_map<int, bool> &mem, int pos) {
    //print_path(path);
    if (cur == root) {
        auto it = mem.find(pos);
        if (it != mem.end())
            if (!it->second)
                return false;
    }
    if (cur == nullptr)
        return false;
    if (pos == attempt.length())
        return cur->is_word;
    char cur_char = attempt[pos];
    if (cur->children[cur_char - 'a'] == nullptr) { // can't continue matching the string
        if (cur->is_word && cur != root) {          // but luckily we are at the end of a word!
            path.push_back(' ');
            bool res = find_path(root, root, attempt, path, mem, pos);
            if (!res) {
                path.pop_back();
                if (cur == root)
                    mem[pos] = false;
            }
            return res;
        }
        if (cur == root)
            mem[pos] = false;
        return false;
    } else {                               // can continue matching
        if (cur->is_word && cur != root) { // but let's break the word here because we can
            path.push_back(' ');
            bool res = find_path(root, root, attempt, path, mem, pos);
            if (res)
                return res;
            path.pop_back();
        }
        // also try matching further
        path.push_back(cur_char);
        bool res = find_path(cur->children[cur_char - 'a'], root, attempt, path, mem, pos + 1);
        if (!res) {
            path.pop_back();
            if (cur == root)
                mem[pos] = false;
        }
        return res;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> words(n);
        for (int i = 0; i < n; ++i)
            cin >> words[i];
        string attempt;
        cin >> attempt;

        Node* root = nullptr;
        for (auto word : words)
            root = build_trei(root, word);

        vector<char> path;
        unordered_map<int, bool> mem;
        if (find_path(root, root, attempt, path, mem, 0)) {
            stringstream ss;
            for (auto ch : path)
                ss << ch;
            cout << ss.str() << endl;
        } else
            cout << "WRONG PASSWORD" << endl;

    }
    return 0;
}