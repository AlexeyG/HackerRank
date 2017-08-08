/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

bool ok_node(Node *root, int bound_down, int bound_up) {
    if (root == nullptr)
        return true;
    if (root->data <= bound_down || root->data >= bound_up)
        return false;
    return ok_node(root->left, bound_down, std::min(bound_up, root->data)) &&
           ok_node(root->right, std::max(bound_down, root->data), bound_up);
}

bool checkBST(Node* root) {
    return ok_node(root, -100000, 100000);
}
