#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Maximum size of the stack

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1; // Initialize top to -1 to indicate an empty stack
    }

    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack overflow! Cannot push more elements.\n";
            return;
        }
     else{
        arr[++top] = value;
        cout << "Pushed " << value << " onto the stack.\n";
    }
}
    void pop() {
        if (top < 0) {
            cout << "Stack underflow! Cannot pop from an empty stack.\n";
            return;
        }

        cout << "Popped " << arr[top--] << " from the stack.\n";
    }

    int topValue() {
        if (top < 0) {
            cout << "Stack is empty. There is no top element.\n";
            return -1; // Return a default value indicating an empty stack
        }

        return arr[top];
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top element: " << myStack.topValue() << endl;

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop(); // Trying to pop from an empty stack

    cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
