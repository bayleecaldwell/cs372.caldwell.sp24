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
    T pop() override {
        if (this->size == 0)
            throw std::out_of_range("Vector is empty");
        return this->data[--this->size];
    }

    T& operator[](int index) override {
        if (index < 0 || index >= this->size)
            throw std::out_of_range("Index out of bounds");
        return this->data[index];
    }
};

template<typename T, int N>
class Array : public SequentialContainer<T> {
public:
    Array() : SequentialContainer<T>() {
        this->data = new T[N];
        this->size = N;
    }
    ~Array() {}

    void push(const T& value) override {
        throw std::runtime_error("Cannot push to a fixed-size array");
    }

    T pop() override {
        throw std::runtime_error("Cannot pop from a fixed-size array");
    }

    T& operator[](int index) override {
        if (index < 0 || index >= this->size)
            throw std::out_of_range("Index out of bounds");
        return this->data[index];
    }
};
