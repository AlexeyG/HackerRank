#include <iostream>
#include <vector>
#include <stack>
#include <string>

typedef struct action {
    int op;
    std::string str;

    action(int op_type, const std::string &op_str)
            : op(op_type),
              str(op_str)
    {};

} ActionT;

std::stack<ActionT> undo;
std::vector<char> str;

ActionT append_string(std::vector<char> &str, const std::string &append_str) {
    str.insert(str.end(), append_str.begin(), append_str.end());
    return std::move(ActionT(1, append_str));
}

ActionT remove_characters(std::vector<char> &str, int n) {
    std::string append_str(str.end() - n, str.end());
    str.erase(str.end() - n, str.end());
    return std::move(ActionT(2, append_str));
}

void print_string() {
    std::cout << "! ";
    for (auto ch : str)
        std::cout << ch;
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int op;
        std::cin >> op;
        switch (op) {
            case 1 : {
                std::string append_str;
                std::cin >> append_str;
                undo.push(append_string(str, append_str));
                break;
            }
            case 2 : {
                int n;
                std::cin >> n;
                undo.push(remove_characters(str, n));
                break;
            }
            case 3 : {
                int n;
                std::cin >> n;
                std::cout << str[n - 1] << std::endl;
                break;
            }
            case 4 : {
                ActionT last_action = undo.top();
                undo.pop();
                switch (last_action.op) {
                    case 1 : {
                        remove_characters(str, last_action.str.length());
                        break;
                    }
                    case 2 : {
                        append_string(str, last_action.str);
                        break;
                    }
                }
                break;
            }
        }
        //std::cout << "! op = " << op << std::endl;
        //print_string();
    }
    return 0;
}