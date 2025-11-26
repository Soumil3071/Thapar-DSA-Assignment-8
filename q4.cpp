#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(TreeNode* root, int minVal, int maxVal) {
    if (root == nullptr) return true;
    
    if (root->data < minVal || root->data > maxVal) return false;
    
    return isBSTUtil(root->left, minVal, root->data - 1) && 
           isBSTUtil(root->right, root->data + 1, maxVal);
}

bool isBST(TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    TreeNode* bstRoot = new TreeNode(4);
    bstRoot->left = new TreeNode(2);
    bstRoot->right = new TreeNode(5);
    bstRoot->left->left = new TreeNode(1);
    bstRoot->left->right = new TreeNode(3);
    
    TreeNode* nonBSTRoot = new TreeNode(3);
    nonBSTRoot->left = new TreeNode(2);
    nonBSTRoot->right = new TreeNode(5);
    nonBSTRoot->left->left = new TreeNode(1);
    nonBSTRoot->left->right = new TreeNode(4);
    
    cout << "Tree 1 is BST: " << (isBST(bstRoot) ? "Yes" : "No") << endl;
    cout << "Tree 2 is BST: " << (isBST(nonBSTRoot) ? "Yes" : "No") << endl;
    
    return 0;
}
