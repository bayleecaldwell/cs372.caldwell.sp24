template <class RecordType>
class Table {
public:
  static const std::size_t CAPACITY = 811;
  table();
  void insert(const ReacordType &entry){
    bool alreadPresent;
    std::size_t index;
    assert(entry.key >= 0);
    findIndex(entry.key, alreadyPresent, index);
    if (!alreadyPresent) {
      assert(size() < CAPACITY);
      index = hash(entry.key);
      while (!isVacant(index)) {
        index = nextIndex(index);
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
  std::size_t size() const {return used; }
private:
  static const int NEVERUSED = -1;
  static const int PREVIOUSLYUSED = -2;
  RecordType data[CAPACITY];
  std::size_t used;
  std::size_t hash(int key) const;
  std::size_t nextIndex(std::size_t index) const;
  void findIndex(int key, bool &found, std::size_t &index) const {
    std::size_t count;
    count = 0;
    i = hash(key);
    while ((count < CAPACITY) && (!never_used(i)) && (data[i].key != key)) {
      ++count;
      i = nextIndex(i);

    }
    found = (data[i].key == key);
  }
  bool neverUsed(std::size_t index) const { return (index == NEVERUSED); }
  bool isVacant(std::size_t index) const {return (index == PREVIOUSLYUSED); }
};
