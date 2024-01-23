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

template <typename T, size_t Size>
Array<T, Size>::Array() {
}

template <typename T, size_t Size>
Array<T, Size>::~Array() {
}

template <typename T, size_t Size>
T& Array<T, Size>::operator[](size_t index) {
    if (index >= Size) {
        std::cerr << "Array: index out of bounds on access" << std::endl;
        exit(1);
    } else {
        return arr[index];
    }
}

template <typename T, size_t Size>
size_t Array<T, Size>::size() const {
    return Size;
}

template <typename T, size_t Size>
void Array<T, Size>::traverse() const {
    for (size_t i = 0; i < Size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    Array<int, 3> arr;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    std::cout << "Array size: " << arr.size() << std::endl;
    std::cout << "Array elements: ";
    arr.traverse();

    return 0;
}
