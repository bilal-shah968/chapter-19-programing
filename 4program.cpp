#include <iostream>
#include <stdexcept> 

class Stack 
{
private:
    int* arr;      
    int top;       
    int capacity;   

public:
    
    Stack(int size) : capacity(size), top(-1)
     {
        arr = new int[capacity];
    }


    void push(int value) 
    {
        if (top == capacity - 1) 
        {
            throw std::out_of_range("Stack overflow");
        }
        arr[++top] = value;
    }

    
    int pop() {
        if (top == -1) {
            throw std::out_of_range("Stack underflow");
        }
        return arr[top--];
    }


    int peek() const 
    {
        if (top == -1) {
            throw std::out_of_range("Stack is empty");
        }
        return arr[top];
    }


    bool isEmpty() const
     {
        return top == -1;
    }


    bool isFull() const 
    {
        return top == capacity - 1;
    }


    ~Stack() {
        delete[] arr;
    }
};

int main()
 {
    try
     {
        
        Stack s(5); 
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);

        std::cout << "Top element is: " << s.peek() << std::endl;

        std::cout << "Popped element: " << s.pop() << std::endl; 
        std::cout << "Popped element: " << s.pop() << std::endl; 

        std::cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << std::endl; 
        std::cout << "Is stack full? " << (s.isFull() ? "Yes" : "No") << std::endl; 

    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
