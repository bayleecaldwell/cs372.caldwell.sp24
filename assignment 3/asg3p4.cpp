#include <iostream>

template <typename T>
struct PriorityNode {
    T data;
    int priority;
};

template <typename T>
class List {
private:
    class Node {
    public:
        T data;
        Node* prev;
        Node* next;
    };
    Node* head;
    Node* tail;

public:
    List();
    List(T newData);
    List(const List& rhs);
    ~List();
    void insert(Node* insertPoint, T data);
    bool empty();
    void push_front(T data);
    void push_back(T data);
    void pop_back();
    void pop_front();
    void traverse(void (*doIt)(T data));
};

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr) {}

template <typename T>
List<T>::List(T newData) : head(new Node{newData, nullptr, nullptr}), tail(head) {}

template <typename T>
List<T>::List(const List& rhs) {
    head = nullptr;
    tail = nullptr;
    Node* current = rhs.head;
    while (current != nullptr) {
        push_back(current->data);
        current = current->next;
    }
}

template <typename T>
List<T>::~List() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
void List<T>::insert(Node* insertPoint, T data) {
    if (insertPoint == nullptr) {
        push_back(data);
        return;
    }

    Node* newNode = new Node{data, insertPoint->prev, insertPoint};
    if (insertPoint->prev != nullptr) {
        insertPoint->prev->next = newNode;
    } else {
        head = newNode;
    }
    insertPoint->prev = newNode;
}

template <typename T>
bool List<T>::empty() {
    return head == nullptr;
}

template <typename T>
void List<T>::push_front(T data) {
    insert(head, data);
}

template <typename T>
void List<T>::push_back(T data) {
    insert(nullptr, data);
}

template <typename T>
void List<T>::pop_back() {
    if (!empty()) {
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }
}

template <typename T>
void List<T>::pop_front() {
    if (!empty()) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }
}

template <typename T>
void List<T>::traverse(void (*doIt)(T data)) {
    Node* current = head;
    while (current != nullptr) {
        doIt(current->data);
        current = current->next;
    }
}

template <typename T>
class PriorityList {
private:
    List<PriorityNode<T>> list;

public:
    PriorityList();
    void insert(T data, int priority);
    void traverse(void (*doIt)(T data));
};

template <typename T>
PriorityList<T>::PriorityList() {}

template <typename T>
void PriorityList<T>::insert(T data, int priority) {
    typename List<PriorityNode<T>>::Node* insertPoint = list.head;
    while (insertPoint != nullptr && insertPoint->data.priority <= priority) {
        insertPoint = insertPoint->next;
    }

    list.insert(insertPoint, PriorityNode<T>{data, priority});
}

template <typename T>
void PriorityList<T>::traverse(void (*doIt)(T data)) {
    list.traverse([doIt](PriorityNode<T> node) { doIt(node.data); });
}

int main() {
    PriorityList<std::string> priorityList;

    priorityList.insert("Item1", 2);
    priorityList.insert("Item2", 1);
    priorityList.insert("Item3", 3);

    std::cout << "Priority List: ";
    priorityList.traverse([](std::string data) { std::cout << data << " "; });
    std::cout << std::endl;

    return 0;
}
