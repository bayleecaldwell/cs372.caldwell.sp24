#include <iostream>
#include <list>

using namespace std;

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 f, T2 s) : first(f), second(s) {}
};

template <typename KeyType, typename ValueType>
class TreeNode {
public:
    Pair<KeyType, ValueType> data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(KeyType key, ValueType value) : data(key, value), left(nullptr), right(nullptr) {}
};

template <typename KeyType, typename ValueType>
class Dictionary {
private:
    TreeNode<KeyType, ValueType>* root;

    void insertNode(TreeNode<KeyType, ValueType>* &node, KeyType key, ValueType value) {
        if (node == nullptr) {
            node = new TreeNode<KeyType, ValueType>(key, value);
            return;
        }

        if (key < node->data.first) {
            insertNode(node->left, key, value);
        } else if (key > node->data.first) {
            insertNode(node->right, key, value);
        } else {
            node->data.second = value;
        }
    }