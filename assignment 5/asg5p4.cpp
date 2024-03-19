#include <iostream>

using namespace std;

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
TreeNode<T>* cloneWithoutLeaves(TreeNode<T>* root) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return nullptr;
    }

    TreeNode<T>* newLeft = cloneWithoutLeaves(root->left);
    TreeNode<T>* newRight = cloneWithoutLeaves(root->right);

    TreeNode<T>* newNode = new TreeNode<T>(root->data);
    newNode->left = newLeft;
    newNode->right = newRight;

    return newNode;
}

template <typename T>
void inorderTraversal(TreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    cout << "Original tree (inorder traversal): ";
    inorderTraversal(root);
    cout << endl;

    TreeNode<int>* clonedTree = cloneWithoutLeaves(root);

    cout << "Cloned tree without leaves (inorder traversal): ";
    inorderTraversal(clonedTree);
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    delete clonedTree->left;
    delete clonedTree->right;
    delete clonedTree;

    return 0;
}
