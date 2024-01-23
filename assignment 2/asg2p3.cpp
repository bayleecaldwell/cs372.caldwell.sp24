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

