#include <iostream>

template <typename T>
class Vector {
public:
    Vector();
    ~Vector();
    void push_back(T data);
    T at(int index) const;
    int size() const;
    void traverse() const;

private:
    T* arr;
    int vCapacity;
    int length;

    void expand(int newCapacity);
};

template <typename T>
Vector<T>::Vector() {
    arr = new T[1];
    vCapacity = 1;
    length = 0;
}

template <typename T>
Vector<T>::~Vector() {
    delete[] arr;
    arr = nullptr;
}

template <typename T>
void Vector<T>::push_back(T data) {
    if (length == vCapacity) {
        expand(2 * vCapacity);
    }
    arr[length] = data;
    length++;
}

template <typename T>
T Vector<T>::at(int index) const {
    if (index < 0 || index >= length) {
        std::cerr << "Vector: index out of bounds on access" << std::endl;
        exit(1);
    } else {
        return arr[index];
    }
}

template <typename T>
int Vector<T>::size() const {
    return length;
}

template <typename T>
void Vector<T>::traverse() const {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Vector<T>::expand(int newCapacity) {
    if (newCapacity > vCapacity) {
        T* temp = new T[newCapacity];
        for (int i = 0; i < length; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        vCapacity = newCapacity;
        arr = temp;
    } else {
        std::cerr << "Vector::expand: new capacity is less than equal to current\n";
    }
}

int main() {
    Vector<int> v1, v2, v3;
    v1.push_back(10);
    v1.push_back(20);

    std::cout << "v1 = ";
    v1.traverse();

    std::cout << "v1[0] = " << v1.at(0) << ", v1[1] = " << v1.at(1) << std::endl;

    return 0;
}
