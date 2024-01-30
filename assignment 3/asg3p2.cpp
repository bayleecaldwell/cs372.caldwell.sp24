#pragma once
#include <iostream>

template <typename Thing>
class ReceiptBag {
private:
    template <typename T>
    class Node {
    public:
        T data;
        int receipt;
        Node* next;
    };

    List<Node<Thing>> items;
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
   
}

template <typename Thing>
int ReceiptBag<Thing>::insert(Thing aThing) {
    int receipt = nextReceipt++;
    Node<Thing> newNode{aThing, receipt, nullptr};
    items.push_back(newNode);
    return receipt;
}

template <typename Thing>
Thing& ReceiptBag<Thing>::pop(int receipt) {
    Node<Thing>* current = items.front();

    while (current != nullptr && current->receipt != receipt) {
        current = current->next;
    }

    if (current != nullptr) {
        Thing& removedItem = current->data;
        items.pop_front();
        return removedItem;
    } else {
        throw std::runtime_error("Receipt not found");
    }
}

template <typename Thing>
int ReceiptBag<Thing>::size() {
    return items.size();
}

template <typename Thing>
int ReceiptBag<Thing>::count() {
    return size(); 
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