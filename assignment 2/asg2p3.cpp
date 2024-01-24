#pragma once
#include <vector>
#include <iostream>

template <typename Thing>
class ReceiptBag {
private:
    std::vector<Thing> items;
    std::vector<int> receipts;
    int nextReceipt;

public:
    ReceiptBag();
    int insert(Thing aThing);
    Thing& pop(int receipt);
    int size();
    int count();
};

template <typename Thing>
ReceiptBag<Thing>::ReceiptBag() : nextReceipt(1) {
    // Constructor
}

template <typename Thing>
int ReceiptBag<Thing>::insert(Thing aThing) {
    int receipt = nextReceipt++;
    items.push_back(aThing);
    receipts.push_back(receipt);
    return receipt;
}

template <typename Thing>
Thing& ReceiptBag<Thing>::pop(int receipt) {
    auto it = receipts.begin();
    while (it != receipts.end() && *it != receipt) {
        ++it;
    }

    if (it != receipts.end()) {
        size_t index = std::distance(receipts.begin(), it);
        Thing& removedItem = items[index];

        items.erase(items.begin() + index);
        receipts.erase(it);

        return removedItem;
    } else {
        throw std::runtime_error("Receipt not found");
    }

    return items[0];
}

template <typename Thing>
int ReceiptBag<Thing>::size() {
    return items.size();
}

template <typename Thing>
int ReceiptBag<Thing>::count() {
    return receipts.size();
}

int main() {
    ReceiptBag<std::string> bag;

    int receipt1 = bag.insert("Item1");
    int receipt2 = bag.insert("Item2");
    int receipt3 = bag.insert("Item3");

    std::cout << "Initial items in the bag:" << std::endl;
    std::cout << "Size: " << bag.size() << ", Count: " << bag.count() << std::endl;

    int removedReceipt = receipt2;
    std::string removedItem = bag.pop(removedReceipt);
    std::cout << "Removed item with receipt " << removedReceipt << ": " << removedItem << std::endl;

    std::cout << "Items in the bag after removal:" << std::endl;
    std::cout << "Size: " << bag.size() << ", Count: " << bag.count() << std::endl;

    return 0;
}
