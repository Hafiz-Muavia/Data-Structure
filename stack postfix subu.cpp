#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(char val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cerr << "Stack is empty." << endl;
            return '\0';
        }
        char val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    char peek() {
        if (isEmpty()) {
            cerr << "Stack is empty." << endl;
            return '\0';
        }
        return top->data;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(string infix) {
    string postfix = "";
    Stack stack;

    for (char c : infix) {
        if (isalnum(c))
            postfix += c;
        else if (c == '(')
            stack.push(c);
        else if (c == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop(); // Pop the '('
        }
        else {
            while (!stack.isEmpty() && precedence(c) <= precedence(stack.peek())) {
                postfix += stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

string infixToPrefix(string infix) {
    string reverseInfix = "";
    for (int i = infix.length() - 1; i >= 0; i--) {
        if (infix[i] == '(')
            reverseInfix += ')';
        else if (infix[i] == ')')
            reverseInfix += '(';
        else
            reverseInfix += infix[i];
    }

    string reversedPostfix = infixToPostfix(reverseInfix);

    string prefix = "";
    for (int i = reversedPostfix.length() - 1; i >= 0; i--) {
        prefix += reversedPostfix[i];
    }

    return prefix;
}

int evaluatePostfix(string postfix) {
    stack<int> operandStack;

    for (char c : postfix) {
        if (isdigit(c)) {
            operandStack.push(c - '0'); // Convert char to int
        } else {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            switch (c) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '^':
                	operandStack.push(operand1 ^ operand2);
                    break;
                case '/':
                    if (operand2 != 0)
                        operandStack.push(operand1 / operand2);
                    else {
                        cerr << "Division by zero error." << endl;
                        return INT_MIN;
                    }
                    break;
                default:
                    cerr << "Invalid operator: " << c << endl;
                    return INT_MIN;
            }
        }
    }

    if (!operandStack.empty()) {
        return operandStack.top();
    } else {
        cerr << "Invalid expression." << endl;
        return INT_MIN;
    }
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << prefix << endl;

    int result = evaluatePostfix(postfix);
    if (result != INT_MIN) {
        cout << "Result of postfix expression: " << result << endl;
    } else {
        cout << "Cannot evaluate postfix expression." << endl;
    }

    return 0;
}