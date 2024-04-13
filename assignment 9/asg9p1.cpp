#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

struct KeyValuePair {
    string key;
    int value;
};

class HashTable {
private:
    vector<list<KeyValuePair>> table;
    int size;

    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % table.size();
    }

public:
    HashTable(int initialSize = 10) : size(initialSize) {
        table.resize(size);
    }

    void insert(const string& key, int value) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.key == key) {
                pair.value = value;
                return;
            }
        }
        table[index].push_back({key, value});
    }

    int get(const string& key) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.key == key) {
                return pair.value;
            }
        }
        return -1;
    }
};

int main() {
    HashTable hashTable;

    hashTable.insert("apple", 10);
    hashTable.insert("banana", 20);
    hashTable.insert("orange", 30);
    hashTable.insert("grape", 40);

    cout << "Value of apple: " << hashTable.get("apple") << endl;
    cout << "Value of banana: " << hashTable.get("banana") << endl;
    cout << "Value of orange: " << hashTable.get("orange") << endl;
    cout << "Value of grape: " << hashTable.get("grape") << endl;

    hashTable.insert("lemon", 50);

    for (int i = 0; i < 10; ++i) {
        hashTable.insert("key" + to_string(i), i);
    }

    return 0;
}
