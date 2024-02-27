#include <iostream>

template <typename T>
class List {
protected:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };
    
    Node* head;
    
public:
    List() : head(nullptr) {}
    ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void insert(const T& item) {
        Node* newNode = new Node(item);
        newNode->next = head;
        head = newNode;
    }
    
    void display() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

template <typename T>
class SelfAdjustingList : public List<T> {
public:
    using List<T>::head;
    using typename List<T>::Node; // Fix here
    
    T* find(const T& itemToFind) {
        Node* prev = nullptr;
        Node* current = head;
        
        while (current) {
            if (current->data == itemToFind) {
                if (prev) {
                    prev->next = current->next;
                    current->next = head;
                    head = current;
                }
                return &head->data;
            }
            prev = current;
            current = current->next;
        }
        
        return nullptr;
    }
};

int main() {
    SelfAdjustingList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    
    std::cout << "Original list: ";
    list.display();
    
    int* found = list.find(3);
    if (found) {
        std::cout << "Found item: " << *found << std::endl;
        std::cout << "Adjusted list: ";
        list.display();
    } else {
        std::cout << "Item not found" << std::endl;
    }
    
    return 0;
}
