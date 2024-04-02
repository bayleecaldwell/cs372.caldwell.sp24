#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct DataStructure {
    size_t size;
    vector<int>* vec;
    TreeNode* tree;

    DataStructure(size_t s) : size(s), vec(new vector<int>(s)), tree(nullptr) {}

    ~DataStructure() {
        delete vec;
        deleteTree(tree);
    }

private:
    void deleteTree(TreeNode* root) {
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

TreeNode* constructBSTFromSortedVector(const vector<int>& vec, int left, int right);

DataStructure* createDataStructure(size_t itemCount) {
    DataStructure* data = new DataStructure(itemCount);

    for (size_t i = 0; i < itemCount; ++i) {
        (*data->vec)[i] = rand() % 100;
    }

    sort(data->vec->begin(), data->vec->end());

    data->tree = constructBSTFromSortedVector(*data->vec, 0, itemCount - 1);

    return data;
}

TreeNode* constructBSTFromSortedVector(const vector<int>& vec, int left, int right) {
    if (left > right) return nullptr;

    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(vec[mid]);

    root->left = constructBSTFromSortedVector(vec, left, mid - 1);
    root->right = constructBSTFromSortedVector(vec, mid + 1, right);

    return root;
}

int main() {
    size_t itemCount = 10;
    DataStructure* data = createDataStructure(itemCount);

    cout << "Sorted vector:" << endl;
    for (size_t i = 0; i < itemCount; ++i) {
        cout << (*data->vec)[i] << " ";
    }
    cout << endl;

    delete data;

    return 0;
}
