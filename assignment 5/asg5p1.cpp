#include <memory>

template<typename T>
class ListNode {
public:
    T data;
    std::shared_ptr<ListNode<T>> next;

    ListNode(T value) : data(value), next(nullptr) {}
};

template<typename T>
class List {
private:
    std::shared_ptr<ListNode<T>> head;
public:
    List() : head(nullptr) {}

    void insert(T value) {
        auto newNode = std::make_shared<ListNode<T>>(value);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        auto current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
