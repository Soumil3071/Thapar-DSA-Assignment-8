#include <iostream>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// (a) Search - Recursive
BSTNode* searchRecursive(BSTNode* root, int key) {
    if (root == nullptr || root->data == key) return root;
    
    if (key < root->data) 
        return searchRecursive(root->left, key);
    else 
        return searchRecursive(root->right, key);
}

// (a) Search - Non-Recursive
BSTNode* searchIterative(BSTNode* root, int key) {
    BSTNode* current = root;
    while (current != nullptr) {
        if (current->data == key) return current;
        else if (key < current->data) current = current->left;
        else current = current->right;
    }
    return nullptr;
}

// (b) Maximum element
BSTNode* findMax(BSTNode* root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr) root = root->right;
    return root;
}

// (c) Minimum element
BSTNode* findMin(BSTNode* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) root = root->left;
    return root;
}

// (d) In-order successor
BSTNode* inorderSuccessor(BSTNode* root, BSTNode* node) {
    if (node->right != nullptr) return findMin(node->right);
    
    BSTNode* successor = nullptr;
    BSTNode* current = root;
    
    while (current != nullptr) {
        if (node->data < current->data) {
            successor = current;
            current = current->left;
        } else if (node->data > current->data) {
            current = current->right;
        } else {
            break;
        }
    }
    return successor;
}

// (e) In-order predecessor
BSTNode* inorderPredecessor(BSTNode* root, BSTNode* node) {
    if (node->left != nullptr) return findMax(node->left);
    
    BSTNode* predecessor = nullptr;
    BSTNode* current = root;
    
    while (current != nullptr) {
        if (node->data > current->data) {
            predecessor = current;
            current = current->right;
        } else if (node->data < current->data) {
            current = current->left;
        } else {
            break;
        }
    }
    return predecessor;
}

int main() {
    BSTNode* root = new BSTNode(50);
    root->left = new BSTNode(30);
    root->right = new BSTNode(70);
    root->left->left = new BSTNode(20);
    root->left->right = new BSTNode(40);
    root->right->left = new BSTNode(60);
    root->right->right = new BSTNode(80);
    
    cout << "Min: " << findMin(root)->data << endl;
    cout << "Max: " << findMax(root)->data << endl;
    
    BSTNode* node = searchRecursive(root, 40);
    if (node) {
        BSTNode* succ = inorderSuccessor(root, node);
        BSTNode* pred = inorderPredecessor(root, node);
        cout << "Node 40 - Successor: " << (succ ? succ->data : -1) 
             << ", Predecessor: " << (pred ? pred->data : -1) << endl;
    }
    
    return 0;
}
