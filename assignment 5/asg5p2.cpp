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
