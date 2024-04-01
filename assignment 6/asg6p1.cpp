#include <iostream>
#include <vector>

using namespace std;

template <typename T>
bool binarySearch(vector<T> aSortedVector, T itemToBeFound, bool printDebugData = false) {
    int left = 0;
    int right = aSortedVector.size() - 1;
    int comparisons = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (printDebugData) {
            cout << "Comparing with item at index " << mid << endl;
            comparisons++;
        }

        if (aSortedVector[mid] == itemToBeFound) {
            if (printDebugData) {
                cout << "Number of comparisons: " << comparisons << endl;
            }
            return true;
        } else if (aSortedVector[mid] < itemToBeFound) {
            left = mid + 1;
        } else {
            right = mid - 1;  
        }
    }

    if (printDebugData) {
        cout << "Number of comparisons: " << comparisons << endl;
    }
    return false;
}

int main() {
    vector<int> sortedVec = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int key = 11;

    bool found = binarySearch(sortedVec, key);
    if (found) {
        cout << "Key " << key << " found!" << endl;
    } else {
        cout << "Key " << key << " not found!" << endl;
    }

    found = binarySearch(sortedVec, key, true);
    if (found) {
        cout << "Key " << key << " found!" << endl;
    } else {
        cout << "Key " << key << " not found!" << endl;
    }

    return 0;
}
