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
