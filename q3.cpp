#include <iostream>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// (a) Insert element
BSTNode* insert(BSTNode* root, int key) {
    if (root == nullptr) return new BSTNode(key);
    
    if (key < root->data) 
        root->left = insert(root->left, key);
    else if (key > root->data) 
        root->right = insert(root->right, key);
    
    return root;
}

// (b) Delete element
BSTNode* deleteNode(BSTNode* root, int key) {
    if (root == nullptr) return root;
    
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }
        
        BSTNode* temp = root->right;
        while (temp->left != nullptr) temp = temp->left;
        
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// (c) Maximum depth
int maxDepth(BSTNode* root) {
    if (root == nullptr) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// (d) Minimum depth
int minDepth(BSTNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr) return minDepth(root->right) + 1;
    if (root->right == nullptr) return minDepth(root->left) + 1;
    
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    return (leftDepth < rightDepth ? leftDepth : rightDepth) + 1;
}

void inorder(BSTNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    BSTNode* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    
    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;
    
    root = deleteNode(root, 50);
    cout << "After deleting 50, Inorder: ";
    inorder(root);
    cout << endl;
    
    return 0;
}
