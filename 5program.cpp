#include <iostream>

class Node
 {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack
{
private:
    Node* top;

public:
    Stack() : top(nullptr) {}


    void push(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;    
    }

    
    void pop()
     {
        if (top == nullptr) {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }

        Node* temp = top;
        top = top->next; 
        delete temp;    
    }


    int peek() const 
    {
        if (top == nullptr) 
        {
            std::cerr << "Stack is empty!" << std::endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() const 
    {
        return top == nullptr;
    }

    
    void printStack() const 
    {
        if (top == nullptr) 
        {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }

        Node* temp = top;
        while (temp != nullptr) 
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    
    ~Stack() 
    {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main()
 {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Stack elements: ";
    stack.printStack(); 

    std::cout << "Top element: " << stack.peek() << std::endl; 

    stack.pop();
    std::cout << "Stack after popping: ";
    stack.printStack(); 

    return 0;
}
