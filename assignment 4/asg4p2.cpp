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
template<typename T>
class Vector : public SequentialContainer<T> {
public:
    Vector() : SequentialContainer<T>() {}
    ~Vector() {}

    void push(const T& value) override {
        T* newData = new T[this->size + 1];
        for (int i = 0; i < this->size; ++i)
            newData[i] = this->data[i];
        newData[this->size++] = value;
        delete[] this->data;
        this->data = newData;
    }