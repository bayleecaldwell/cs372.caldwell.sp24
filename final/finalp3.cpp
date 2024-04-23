#include <cassert>

template <class RecordType>
class Table {
public:
    static const std::size_t CAPACITY = 811;
    Table() : used(0) {}
    void insert(const RecordType &entry) {
        bool alreadyPresent;
        std::size_t index;
        assert(entry.key >= 0);
        findIndex(entry.key, alreadyPresent, index);
        if (!alreadyPresent) {
            assert(size() < CAPACITY);
            index = hash(entry.key);
            while (!isVacant(index)) {
                index = quadProbe(index);
            }
            ++used;
        }
        data[index] = entry;
    }
    void remove(int key) {
        bool found;
        std::size_t index;
        assert(key >= 0);
        findIndex(key, found, index);
        if (found) {
            data[index].key = PREVIOUSLYUSED;
            --used;
        }
    }
    bool isPresent(int key) const;
    void find(int key, bool &found, RecordType &result) const;
    std::size_t size() const { return used; }
private:
    static const int NEVERUSED = -1;
    static const int PREVIOUSLYUSED = -2;
    RecordType data[CAPACITY];
    std::size_t used;
    std::size_t hash(int key) const { return key % CAPACITY; }
    std::size_t nextIndex(std::size_t index) const { return (index + 1) % CAPACITY; }
    std::size_t quadProbe(std::size_t index) const {
        std::size_t i = 2;
        while (!isVacant((index + i*i) % CAPACITY)) {
            i++;
        }
        return (index + i*i) % CAPACITY;
    }
    void findIndex(int key, bool &found, std::size_t &index) const {
        std::size_t count = 0;
        index = hash(key);
        while ((count < CAPACITY) && (!neverUsed(index)) && (data[index].key != key)) {
            ++count;
            index = quadProbe(index);
        }
        found = (data[index].key == key);
    }
    bool neverUsed(std::size_t index) const { return (index == NEVERUSED); }
    bool isVacant(std::size_t index) const { return (index == PREVIOUSLYUSED); }
};

