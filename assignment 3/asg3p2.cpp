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