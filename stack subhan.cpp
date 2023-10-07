#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
    	data=value; 
		next=NULL; 
	} 
	
	};

class StackLinkedList {
private:
    Node* topNode;

public:
    StackLinkedList() {
	topNode=NULL;
	
	}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop() {
        if (topNode != NULL) {
            int topValue = topNode->data;
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
            return topValue;
        } else {
            cerr << "Stack is empty." << endl;
            return -1; 
        }
    }

    int topElement() {
        if (topNode != nullptr) {
            return topNode->data;
        } else {
            cerr << "Stack is empty." << endl;
            return -1; // Return a default value or throw an exception
        }
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    int size() {
        int count = 0;
        Node* current = topNode;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    StackLinkedList stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.topElement() << endl;

    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;

    cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Stack size: " << stack.size() << endl;

    return 0;
}
