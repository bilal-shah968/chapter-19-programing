#include <iostream>

class Node
 {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList 
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Add a new node at the end
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }


    void printListForward() const
    {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    
    void printListBackward() const
     {
        Node* temp = tail;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }


    ~DoublyLinkedList() 
    {
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
    }
};

int main() {
    DoublyLinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    std::cout << "Doubly Linked List (Forward): ";
    list.printListForward();

    std::cout << "Doubly Linked List (Backward): ";
    list.printListBackward();

    return 0;
}
