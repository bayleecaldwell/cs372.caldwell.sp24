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

    ValueType& getNodeValue(TreeNode<KeyType, ValueType>* node, KeyType key) const {
        if (node == nullptr) {
            throw out_of_range("Key not found in dictionary.");
        }

        if (key < node->data.first) {
            return getNodeValue(node->left, key);
        } else if (key > node->data.first) {
            return getNodeValue(node->right, key);
        } else {
            return node->data.second;
        }
    }

    void getKeysHelper(TreeNode<KeyType, ValueType>* node, list<KeyType>& keys) const {
        if (node == nullptr) {
            return;
        }

        getKeysHelper(node->left, keys);
        keys.push_back(node->data.first);
        getKeysHelper(node->right, keys);
    }

    void getValuesHelper(TreeNode<KeyType, ValueType>* node, list<ValueType>& values) const {
        if (node == nullptr) {
            return;
        }

        getValuesHelper(node->left, values);
        values.push_back(node->data.second);
        getValuesHelper(node->right, values);
    }

    public:
    Dictionary() : root(nullptr) {}

    ValueType& get(KeyType key) const {
        return getNodeValue(root, key);
    }

void set(KeyType key, ValueType value) {
        insertNode(root, key, value);
    }

    list<KeyType> getKeys() const {
        list<KeyType> keys;
        getKeysHelper(root, keys);
        return keys;
    }

     list<ValueType> getValues() const {
        list<ValueType> values;
        getValuesHelper(root, values);
        return values;
    }

    ValueType& operator[](const KeyType& key) const {
        return getNodeValue(root, key);
    }
};

int main() {
    Dictionary<string, int> dict;
    dict.set("grape", 5);
    dict.set("banana", 10);
    dict.set("orange", 15);

    cout << "Value of grape: " << dict.get("grape") << endl;
    cout << "Value of banana: " << dict.get("banana") << endl;
    cout << "Value of orange: " << dict.get("orange") << endl;

    cout << "Keys in the dictionary:" << endl;
    for (const auto& key : dict.getKeys()) {
        cout << key << endl;
    }

    cout << "Values in the dictionary:" << endl;
    for (const auto& value : dict.getValues()) {
        cout << value << endl;
    }

    cout << "Using operator[]: " << dict["banana"] << endl;

    return 0;
}
