#include <iostream>

class Node 
{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList 
{
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() : head(nullptr), tail(nullptr) {}
    void append(int value) 
    {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head; 
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; 
        }
    }


    void printList() {
        if (head == nullptr) return;

        Node* temp = head;
        do 
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }

    ~CircularLinkedList()
     {
        if (head == nullptr) return;

        Node* current = head;
        Node* nextNode;

        do
         {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
        
        head = nullptr;
        tail = nullptr;
    }
};

int main()
 {
    CircularLinkedList cll;
    cll.append(10);
    cll.append(20);
    cll.append(30);
    cll.printList(); 
    return 0;
}
