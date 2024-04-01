#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
void insert(TreeNode<T>*& root, T value) {
    if (root == nullptr) {
        root = new TreeNode<T>(value);
    } else if (value < root->data) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

template <typename T>
bool search(TreeNode<T>* root, T value) {
    if (root == nullptr) {
        return false;
    } else if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100000);

    vector<int> arraySizes = {1000, 2500, 5000, 10000, 50000};
    vector<double> arraySearchTimes;
    vector<double> treeSearchTimes;

    for (int size : arraySizes) {
        vector<int> arr;
        for (int i = 0; i < size; ++i) {
            arr.push_back(dist(gen));
        }

        sort(arr.begin(), arr.end());

        TreeNode<int>* root = nullptr;
        for (int num : arr) {
            insert(root, num);
        }

        double arrayTotalTime = 0.0;
        double treeTotalTime = 0.0;

        for (int i = 0; i < 100; ++i) {
            int target = dist(gen);

            auto startArray = high_resolution_clock::now();
            int index = binarySearch(arr, target);
            auto stopArray = high_resolution_clock::now();

            if (index != -1) {
                arrayTotalTime += duration<double>(stopArray - startArray).count();
            }

            auto startTree = high_resolution_clock::now();
            bool found = search(root, target);
            auto stopTree = high_resolution_clock::now();

            if (found) {
                treeTotalTime += duration<double>(stopTree - startTree).count();
            }
        }

        arraySearchTimes.push_back(arrayTotalTime / 100.0);
        treeSearchTimes.push_back(treeTotalTime / 100.0);

        delete root;
    }

    cout << "Array Size\tAverage Array Search Time\tAverage Tree Search Time" << endl;
    for (size_t i = 0; i < arraySizes.size(); ++i) {
        cout << arraySizes[i] << "\t\t" << arraySearchTimes[i] << " seconds\t\t" << treeSearchTimes[i] << " seconds" << endl;
    }

    return 0;
}
