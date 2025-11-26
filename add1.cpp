#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
    if (root == nullptr) return 0;
    
    if (root->left == nullptr && root->right == nullptr && isLeft) {
        return root->data;
    }
    
    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << "Sum of left leaves: " << sumOfLeftLeaves(root) << endl;
    
    return 0;
}
