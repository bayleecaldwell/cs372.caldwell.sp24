#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

template<typename T>
int partition(vector<T>& arr, int low, int high);

template<typename T>
void quickSort(vector<T>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

template<typename T>
int partition(vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int main() {
    vector<int> sizes = {100, 500, 1000, 5000, 10000};

    random_device rd;
    mt19937 gen(rd());

    for (int size : sizes) {
        vector<int> data(size);
        uniform_int_distribution<> dis(1, 1000);
        for (int i = 0; i < size; i++) {
            data[i] = dis(gen);
        }

        auto start = chrono::high_resolution_clock::now();
        quickSort(data, 0, size - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> timeTaken = end - start;
        cout << "Quicksort time for " << size << " elements: " << timeTaken.count() << " seconds" << endl;

        start = chrono::high_resolution_clock::now();
        sort(data.begin(), data.end());
        end = chrono::high_resolution_clock::now();
        timeTaken = end - start;
        cout << "std::sort() time for " << size << " elements: " << timeTaken.count() << " seconds" << endl;
    }

    return 0;
}
