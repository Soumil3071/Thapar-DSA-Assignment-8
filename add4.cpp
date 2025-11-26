#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void rightViewUtil(TreeNode* root, int level, int& maxLevel) {
    if (root == nullptr) return;
    
    if (level > maxLevel) {
        cout << root->data << " ";
        maxLevel = level;
    }
    
    rightViewUtil(root->right, level + 1, maxLevel);
    rightViewUtil(root->left, level + 1, maxLevel);
}

void rightView(TreeNode* root) {
    int maxLevel = 0;
    rightViewUtil(root, 1, maxLevel);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    
    cout << "Right view: ";
    rightView(root);
    cout << endl;
    
    return 0;
}
