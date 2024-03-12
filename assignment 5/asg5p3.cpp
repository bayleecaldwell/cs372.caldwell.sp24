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
                auto minRight = node->right;
                while (minRight->left) {
                    minRight = minRight->left;
                }
                node->data = minRight->data;
                deleteNode(node->right, minRight->data);
            }
            return true;
        }
    }
