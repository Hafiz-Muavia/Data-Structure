#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size) : top(-1), capacity(size)
    {
        arr = new int[size];
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int value)
    {
        if (top < capacity - 1)
        {
            arr[++top] = value;
        }
        else
        {
            cout << "Stack Overflow!" << endl;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return -1; // Error value
        }
        return arr[top--];
    }

    int peek() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1; // Error value
        }
        return arr[top];
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    int getPrecedence(char op)
    {
        if (op == '^')
            return 3;
        else if (op == '*' || op == '/')
            return 2;
        else if (op == '+' || op == '-')
            return 1;
        else
            return 0;
    }

    void infixEvaluation(const string &s);
};

int evaluatePostfix(const string &exp)
{
    Stack stack(exp.length());
    string operand;

    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];

        if (c == ' ' || c == '\t')
        {
            if (!operand.empty())
            {
                stack.push(stoi(operand));
                operand.clear();
            }
        }
        else if (c >= '0' && c <= '9')
        {
            operand += c;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            if (!operand.empty())
            {
                stack.push(stoi(operand));
                operand.clear();
            }

            if (stack.isEmpty())
            {
                cout << "Insufficient operands for operator: " << c << endl;
                return -1;
            }

            int operand2 = stack.pop();

            if (stack.isEmpty())
            {
                cout << "Insufficient operands for operator: " << c << endl;
                return -1;
            }

            int operand1 = stack.pop();

            int result;
            switch (c)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0)
                {
                    cout << "Division by zero error." << endl;
                    return -1;
                }
                result = operand1 / operand2;
                break;
            case '^':
                result = pow(operand1, operand2);
                break;
            default:
                cout << "Invalid operator: " << c << endl;
                return -1;
            }
            stack.push(result);
        }
        else
        {
            cout << "Invalid character: " << c << endl;
            return -1;
        }
    }

    if (!operand.empty())
    {
        stack.push(stoi(operand));
    }

    if (stack.isEmpty())
    {
        cout << "Invalid postfix expression." << endl;
        return -1;
    }

    int result = stack.pop();
    if (!stack.isEmpty())
    {
        cout << "Invalid postfix expression." << endl;
        return -1;
    }

    return result;
}

void Stack::infixEvaluation(const string &s)
{
    Stack operatorStack(s.length());
    string postfix;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c == ' ' || c == '\t')
        {
            continue;
        }
        else if (c >= '0' && c <= '9')
        {
            string number;
            while (i < s.length() && ((s[i] >= '0' && s[i] <= '9') || s[i] == '.'))
            {
                number += s[i];
                i++;
            }
            i--;

            postfix += number + ' ';
        }
        else if (c == '(')
        {
            operatorStack.push(c);
        }
        else if (c == ')')
        {
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(')
            {
                char op = operatorStack.pop();
                postfix += op;
                postfix += ' ';
            }
            if (!operatorStack.isEmpty() && operatorStack.peek() == '(')
            {
                operatorStack.pop();
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(' &&
                   getPrecedence(c) <= getPrecedence(operatorStack.peek()))
            {
                char op = operatorStack.pop();
                postfix += op;
                postfix += ' ';
            }
            operatorStack.push(c);
        }
        else
        {
            cout << "Invalid character in infix expression: " << c << endl;
            return;
        }
    }

    while (!operatorStack.isEmpty())
    {
        char op = operatorStack.pop();
        postfix += op;
        postfix += ' ';
    }

    cout << "Postfix Expression is: " << postfix << endl;
    int result = evaluatePostfix(postfix);
    if (result != -1)
    {
        cout << "Result: " << result << endl;
    }
}

int evaluatePrefix(const string &exp)
{
    Stack stack(exp.length());
    string operand;

    for (int i = exp.length() - 1; i >= 0; i--)
    {
        char c = exp[i];

        if (c == ' ' || c == '\t')
        {
            if (!operand.empty())
            {
                stack.push(stoi(operand));
                operand.clear();
            }
        }
        else if (c >= '0' && c <= '9')
        {
            operand += c;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            if (!operand.empty())
            {
                stack.push(stoi(operand));
                operand.clear();
            }

            if (stack.isEmpty())
            {
                cout << "Insufficient operands for operator: " << c << endl;
                return -1;
            }

            int operand1 = stack.pop();

            if (stack.isEmpty())
            {
                cout << "Insufficient operands for operator: " << c << endl;
                return -1;
            }

            int operand2 = stack.pop();

            int result;
            switch (c)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0)
                {
                    cout << "Division by zero error." << endl;
                    return -1;
                }
                result = operand1 / operand2;
                break;
            case '^':
                result = pow(operand1, operand2);
                break;
            default:
                cout << "Invalid operator: " << c << endl;
                return -1;
            }
            stack.push(result);
        }
        else
        {
            cout << "Invalid character: " << c << endl;
            return -1;
        }
    }

    if (!operand.empty())
    {
        stack.push(stoi(operand));
    }

    if (stack.isEmpty())
    {
        cout << "Invalid prefix expression." << endl;
        return -1;
    }

    int result = stack.pop();
    if (!stack.isEmpty())
    {
        cout << "Invalid prefix expression." << endl;
        return -1;
    }

    return result;
}

int main()
{
    cout << "Choose expression type (1 for postfix, 2 for prefix, 3 for infix): ";
    int choice;
    cin >> choice;
    cin.ignore();
    string expression;

    if (choice == 1)
    {
        cout << "Enter a postfix expression: ";
        getline(cin, expression);
        int result = evaluatePostfix(expression);
        if (result != -1)
        {
            cout << "Result: " << result << endl;
        }
    }
    else if (choice == 2)
    {
        cout << "Enter a prefix expression: ";
        getline(cin, expression);
        int result = evaluatePrefix(expression);
        if (result != -1)
        {
            cout << "Result: " << result << endl;
        }
    }
    else if (choice == 3)
    {
        cout << "Enter an infix expression: ";
        getline(cin, expression);
        Stack stack(expression.length());
        stack.infixEvaluation(expression);
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}