#include <iostream>
#include <list>

template<typename T>
void partitionList(const T& splittingValue, const std::list<T>& originalList,
                   std::list<T>* lessThanList, std::list<T>* greaterThanList) {
    if (lessThanList == nullptr || greaterThanList == nullptr)
        return;

    typename std::list<T>::const_iterator it;
    for (it = originalList.begin(); it != originalList.end(); ++it) {
        if (*it < splittingValue)
            lessThanList->push_back(*it);
        else
            greaterThanList->push_back(*it);
    }
}

template<typename T>
std::list<T>* quicksort(const std::list<T>& originalList) {
    if (originalList.size() <= 1) {
        return new std::list<T>(originalList);
    }

    T splittingValue = originalList.front();
    std::list<T> lessThanList, greaterThanList;

    partitionList(splittingValue, originalList, &lessThanList, &greaterThanList);

    std::list<T>* sortedLess = quicksort(lessThanList);
    std::list<T>* sortedGreater = quicksort(greaterThanList);

    sortedLess->insert(sortedLess->end(), sortedGreater->begin(), sortedGreater->end());

    delete sortedGreater;

    return sortedLess;
}

int main() {
    std::list<int> myList;
    myList.push_back(5);
    myList.push_back(2);
    myList.push_back(8);
    myList.push_back(1);
    myList.push_back(6);
    myList.push_back(3);
    myList.push_back(9);
    myList.push_back(4);
    myList.push_back(7);

    std::list<int>* sortedList = quicksort(myList);

    std::cout << "Sorted List: ";
    if (sortedList != nullptr) {
        for (typename std::list<int>::iterator it = sortedList->begin(); it != sortedList->end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        delete sortedList;
    } else {
        std::cout << "Sorting failed!" << std::endl;
    }

    return 0;
}
