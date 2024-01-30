#include <iostream>

template <typename T>
class CircularList : public List<T> {
private:
    using Node = typename List<T>::Node;

public:
    CircularList();
    CircularList(T newData);
    CircularList(const CircularList& rhs);
    ~CircularList() override;
    void push_front(T data) override;
    void push_back(T data) override;
    void pop_back() override;
    void pop_front() override;
    void circle(void (*doIt)(T data), int startPos);
};

template <typename T>
CircularList<T>::CircularList() : List<T>() {}

template <typename T>
CircularList<T>::CircularList(T newData) : List<T>(newData) {}

template <typename T>
CircularList<T>::CircularList(const CircularList& rhs) : List<T>(rhs) {}

template <typename T>
CircularList<T>::~CircularList() {}

template <typename T>
void CircularList<T>::push_front(T data) {
    List<T>::push_front(data);
    List<T>::tail->next = List<T>::head;
}

template <typename T>
void CircularList<T>::push_back(T data) {
    List<T>::push_back(data);
    List<T>::tail->next = List<T>::head;
}

template <typename T>
void CircularList<T>::pop_back() {
    List<T>::pop_back();
    List<T>::tail->next = List<T>::head;
}

template <typename T>
void CircularList<T>::pop_front() {
    List<T>::pop_front();
    List<T>::tail->next = List<T>::head;
}

template <typename T>
void CircularList<T>::circle(void (*doIt)(T data), int startPos) {
    Node* current = List<T>::head;
    for (int i = 0; i < startPos; ++i) {
        if (current != nullptr) {
            current = current->next;
        } else {
            throw std::out_of_range("Invalid starting position");
        }
    }

    Node* startNode = current;

    do {
        doIt(current->data);
        current = current->next;
    } while (current != startNode);
}