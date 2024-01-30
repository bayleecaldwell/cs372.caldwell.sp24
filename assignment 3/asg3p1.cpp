#include <iostream>

template <typename T>
class List {
private:
    class Node {
    public:
        T data;
        Node* prev;
        Node* next;
    };
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    List() : head(nullptr), tail(nullptr) {}

    List(T newData) {
        head = new Node{newData, nullptr, nullptr};
        tail = head;
    }

    // Copy constructor
    List(const List& rhs) {
        head = nullptr;
        tail = nullptr;
        Node* current = rhs.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }

    ~List() {
        while (!empty()) {
            pop_front();
        }
    }

    bool empty() {
        return head == nullptr;
    }

    void push_front(T data) {
        Node* newNode = new Node{data, nullptr, head};
        if (empty()) {
            tail = newNode;
        } else {
            head->prev = newNode;
        }
        head = newNode;
    }

    void push_back(T data) {
        Node* newNode = new Node{data, tail, nullptr};
        if (empty()) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    T front() {
        if (!empty()) {
            return head->data;
        }
        throw std::out_of_range("List is empty");
    }

    T back() {
        if (!empty()) {
            return tail->data;
        }
        throw std::out_of_range("List is empty");
    }

    void pop_back() {
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

    void pop_front() {
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

    void traverse(void (*doIt)(T data)) {
        Node* current = head;
        while (current != nullptr) {
            doIt(current->data);
            current = current->next;
        }
    }
};

// Test code
void printData(int data) {
    std::cout << data << " ";
}

int main() {
    List<int> myList;

    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    std::cout << "Original List: ";
    myList.traverse(printData);

    List<int> copiedList(myList);
    std::cout << "\nCopied List: ";
    copiedList.traverse(printData);

    std::cout << "\n";

    return 0;
}
