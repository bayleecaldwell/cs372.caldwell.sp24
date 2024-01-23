#include <iostream>

template <typename T, size_t Size>
class Array {
public:
    Array();
    ~Array();
    T& operator[](size_t index);
    size_t size() const;
    void traverse() const;

private:
    T arr[Size];
};

