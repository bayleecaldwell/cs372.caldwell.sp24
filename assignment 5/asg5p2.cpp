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
    void display(std::shared_ptr<TreeNode<T>>& node) {
            if (!node) return;
            display(node->left);
            std::cout << node->data << " ";
            display(node->right);
        }

public:
    BinaryTree() : root(nullptr) {}

    void insert(T value) {
        insert(root, value);
    }

    void display() {
        display(root);
        std::cout << std::endl;
    }
};

int main() {

    BinaryTree<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    std::cout << "Binary Tree: ";
    tree.display();

    return 0;
}
