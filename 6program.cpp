#include <iostream>
#include <stdexcept>

class Queue {
private:
    int* arr;       
    int front;       
    int rear;    
    int capacity;    
    int size;       

public:
    
    Queue(int cap) : capacity(cap), size(0), front(0), rear(cap - 1)
     {
        arr = new int[capacity];
    }
    ~Queue() {
        delete[] arr;
    }


    void enqueue(int element) {
        if (size == capacity) {
            throw std::overflow_error("Queue is full");
        }
        rear = (rear + 1) % capacity;
        arr[rear] = element;
        ++size;
    }

    
    int dequeue() {
        if (size == 0) {
            throw std::underflow_error("Queue is empty");
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        --size;
        return item;
    }

    
    int peek() const {
        if (size == 0) {
            throw std::underflow_error("Queue is empty");
        }
        return arr[front];
    }


    bool isEmpty() const {
        return size == 0;
    }
    bool isFull() const {
        return size == capacity;
    }


    void printQueue() const {
        if (size == 0) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        int current = front;
        for (int i = 0; i < size; ++i) {
            std::cout << arr[current] << " ";
            current = (current + 1) % capacity;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue q(5); 

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.printQueue(); 

    std::cout << "Front element: " << q.peek() << std::endl;

    q.dequeue();
    q.dequeue();

    q.printQueue(); 

    q.enqueue(60);
    q.enqueue(70);

    q.printQueue(); 

    return 0;
}
