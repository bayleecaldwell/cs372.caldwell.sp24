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

    