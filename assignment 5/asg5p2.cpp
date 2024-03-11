#include <memory>
#include <iostream>

template<typename T>
class TreeNode {
public:
    T data;
    std::shared_ptr<TreeNode<T>> left;
    std::shared_ptr<TreeNode<T>> right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree {
private:
    std::shared_ptr<TreeNode<T>> root;

    void insert(std::shared_ptr<TreeNode<T>>& node, T value) {
        if (!node) {
            node = std::make_shared<TreeNode<T>>(value);
            return;
        }
        if (value < node->data) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }
