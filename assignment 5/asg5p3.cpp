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

    bool deleteNode(std::shared_ptr<TreeNode<T>>& node, const T& value) {
        if (!node) {
            return false;
        }
        
        if (value < node->data) {
            return deleteNode(node->left, value);
        } else if (value > node->data) {
            return deleteNode(node->right, value);
        } else {
            if (!node->left) {
                node = node->right;
            } else if (!node->right) {
                node = node->left;
            } else {
                auto successor = node->right;
                while (successor->left) {
                    successor = successor->left;
                }
                node->data = successor->data;
                deleteNode(node->right, successor->data);
            }
            return true;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(const T& value) {
        insert(root, value);
    }

    void display() {
        display(root);
        std::cout << std::endl;
    }

    bool deleteValue(const T& value) {
        return deleteNode(root, value);
    }

private:
    void insert(std::shared_ptr<TreeNode<T>>& node, const T& value) {
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

    std::cout << "Before deletion: ";
    tree.display();

    int valueToDelete = 3;
    if (tree.deleteValue(valueToDelete)) {
        std::cout << "Node with value " << valueToDelete << " deleted successfully." << std::endl;
    } else {
        std::cout << "Node with value " << valueToDelete << " not found." << std::endl;
    }

    std::cout << "After deletion: ";
    tree.display();

    return 0;
}
