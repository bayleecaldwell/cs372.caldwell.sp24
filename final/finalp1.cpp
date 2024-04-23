#include <iostream>
#include <queue>


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int countNodes(TreeNode* root) {
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countInternalNodes(TreeNode* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return 0;
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

void computeExternalPathLength(TreeNode* root, int depth, int& sum) {
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr) {
        sum += depth;
        return;
    }
    computeExternalPathLength(root->left, depth + 1, sum);
    computeExternalPathLength(root->right, depth + 1, sum);
}

int externalPathLength(TreeNode* root) {
    int sum = 0;
    computeExternalPathLength(root, 0, sum);
    return sum;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "Number of nodes in the tree: " << countNodes(root) << std::endl;
    std::cout << "Number of internal nodes in the tree: " << countInternalNodes(root) << std::endl;
    std::cout << "External path length of the tree: " << externalPathLength(root) << std::endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
