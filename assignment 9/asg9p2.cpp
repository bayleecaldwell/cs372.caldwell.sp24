#include <iostream>
#include <functional>

const int TABLE_SIZE = 11;

struct RecordType {
    int key;
};

class Table {
private:
    RecordType *table;
    int numElements;

public:
    Table() {
        table = new RecordType[TABLE_SIZE];
        numElements = 0;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i].key = -1;
        }
    }

    ~Table() {
        delete[] table;
    }

    void linearProbe(int key, bool &found, RecordType &result) {
        std::size_t index = key % TABLE_SIZE;
        while (table[index].key != -1) {
            if (table[index].key == key) {
                result = table[index];
                found = true;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        }
        found = false;
    }

    void quadraticProbe(int key, bool &found, RecordType &result) {
        std::size_t index = key % TABLE_SIZE;
        int i = 0;
        while (table[index].key != -1) {
            if (table[index].key == key) {
                result = table[index];
                found = true;
                return;
            }
            i++;
            index = (index + i * i) % TABLE_SIZE;
        }
        found = false;
    }

    void secondHash(int key, bool &found, RecordType &result) {
        std::size_t index = key % TABLE_SIZE;
        std::size_t h2 = 7 - (key % 7);
        while (table[index].key != -1) {
            if (table[index].key == key) {
                result = table[index];
                found = true;
                return;
            }
            index = (index + h2) % TABLE_SIZE;
        }
        found = false;
    }

    void find(int key, bool &found, RecordType &result, void (Table::*hashingFunction)(int, bool &, RecordType &) = &Table::linearProbe) {
        (this->*hashingFunction)(key, found, result);
    }

    void insert(int key, const RecordType &record) {
        bool found;
        RecordType result;
        find(key, found, result);
        if (!found) {
            table[key % TABLE_SIZE] = record;
            numElements++;
        }
    }
};

int main() {
    Table table;
    RecordType record1 = {10};
    RecordType record2 = {22};
    RecordType record3 = {33};
    RecordType result;
    bool found;

    table.insert(10, record1);
    table.find(10, found, result);
    std::cout << "Linear Probing - Found: " << found << ", Key: " << result.key << std::endl;

    table.insert(22, record2);
    table.find(22, found, result, &Table::quadraticProbe);
    std::cout << "Quadratic Probing - Found: " << found << ", Key: " << result.key << std::endl;

    table.insert(33, record3);
    table.find(33, found, result, &Table::secondHash);
    std::cout << "Second Hash Probing - Found: " << found << ", Key: " << result.key << std::endl;

    return 0;
}
