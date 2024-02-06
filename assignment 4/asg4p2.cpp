#include <iostream>
#include <stdexcept>

template<typename T>
class SequentialContainer {
protected:
    T* data;
    int size;
public:
    SequentialContainer() : data(nullptr), size(0) {}
    virtual ~SequentialContainer() {
        delete[] data;
    }

    int getSize() const {
        return size;
    }

    virtual void push(const T& value) = 0;
    virtual T pop() = 0;
    virtual T& operator[](int index) = 0;
};