#include <iostream>

class Node
 {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList
 {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Add a new node at the end
    void append(int value)
     {
        Node* newNode = new Node(value);
        if (head == nullptr) 
        {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
             {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Print the list
    void printList() const 
    {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Delete the entire list
    ~SinglyLinkedList()
     {
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
};

int main()
 {
    SinglyLinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    std::cout << "Singly Linked List: ";
    list.printList();

    return 0;
}
