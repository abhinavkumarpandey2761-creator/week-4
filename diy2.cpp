#include <iostream>
#include <stdexcept>

class Stack {
private:
    int* buffer;       
    int capacity;      
    int topIndex;     

    
    void resize() {
        capacity *= 2;
        int* newBuffer = new int[capacity];
        for (int i = 0; i <= topIndex; ++i) {
            newBuffer[i] = buffer[i];
        }
        delete[] buffer;
        buffer = newBuffer;
    }

public:
  
    Stack(int initialCapacity = 4) {
        if (initialCapacity <= 0) {
            throw std::invalid_argument("Capacity must be greater than zero.");
        }
        capacity = initialCapacity;
        buffer = new int[capacity];
        topIndex = -1; 
    }

   
    ~Stack() {
        delete[] buffer;
        std::cout << "Stack destructor called: Memory released.\n";
    }

   
    void push(int value) {
        if (topIndex == capacity - 1) {
            resize(); 
        }
        buffer[++topIndex] = value;
    }

    int pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow: Cannot pop from an empty stack.");
        }
        return buffer[topIndex--];
    }

   
    int peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty.");
        }
        return buffer[topIndex];
    }

 
    bool isEmpty() const {
        return topIndex == -1;
    }

    
    int size() const {
        return topIndex + 1;
    }
};

int main() {
   
    {
        Stack myStack(2); 

        myStack.push(10);
        myStack.push(20);
        myStack.push(30); 

        std::cout << "Top element: " << myStack.peek() << "\n";
        std::cout << "Popped: " << myStack.pop() << "\n";
        std::cout << "Popped: " << myStack.pop() << "\n";
    }

    return 0;
}
