#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

class node
{
private:
    int data;
    node *next;

public:
    node(int);
    void setdata(int);
    int getdata();

    void setnext(node *);
    node *getnext();
};
node ::node(int n)
{
    setdata(n);
    next = NULL;
}
void node::setdata(int n)
{
    data = n;
}
int node::getdata()
{
    return data;
}
void node::setnext(node *ptr)
{
    next = ptr;
}
node *node::getnext()
{
    return next;
}
class Stack
{
private:
    node *top;
    int size;

public:
    Stack();
    void push(int);
    int pop();
    int gettop();
    void postfix_evaluation(string);
    void prefix_evaluation(string);
    void infix_evaluation(string);
};

Stack::Stack()
{
    top = NULL;
    size = 0;
}

void Stack::push(int data)
{
    node *ptr = new node(data);
    if (ptr == nullptr)
    {
        cout << "Out of memory! Stack is full." << endl;
        return;
    }
    ptr->setnext(top);
    top = ptr;
    size++;
}

int Stack::gettop()
{
    if (top == NULL)
    {
        cout << "Stack is Empty.";
        return 0;
    }
    else
    {
        return top->getdata();
    }
}

int Stack::pop()
{
    if (top == NULL)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        int val;
        val = top->getdata();
        node *ptr = top;
        top = top->getnext();
        delete ptr;
        size--;
        return val;
    }
}

void Stack::postfix_evaluation(string s)
{
    int op1, op2;
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) >= '0' && s.at(i) <= '9')
        {
            push(s.at(i) - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();
            switch (s.at(i))
            {
            case '+':
                push(op1 + op2);
                break;

            case '-':
                push(op1 - op2);
                break;

            case '*':
                push(op1 * op2);
                break;

            case '/':
                push(op1 / op2);
                break;

            case '^':
                push(pow(op1, op2));
                break;
            default:
                cout << "Invalid Operator " << endl;
            }
        }
    }
    cout << "Result of Postfix is : " << gettop() << endl;
}
void Stack::prefix_evaluation(string s)
{
    int op1, op2;
    stack<char> ch;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s.at(i) >= '0' && s.at(i) <= '9')
        {
            push(s.at(i) - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();
            switch (s.at(i))
            {
            case '+':
                push(op1 + op2);
                break;

            case '-':
                push(op1 - op2);
                break;

            case '*':
                push(op1 * op2);
                break;

            case '/':
                push(op1 / op2);
                break;

            case '^':
                push(pow(op1, op2));
                break;
            default:
                cout << "Invalid Operator " << endl;
            }
        }
    }
    cout << "Result of infix is : " << gettop() << endl;
}

void Stack::infix_evaluation(string s)
{
    string postfix;
     for (int i =0 ; i < s.length(); i++)
    {
        if(s.at(i)>='0'&&s.at(i)<='9')
        {
            postfix+=s.at(i);
        }
        else if(s.at(i)=='+'||s.at(i)=='-'||s.at(i)=='*'||s.at(i)=='/'||s.at(i)=='^')
        {
            push(s.at(i));
        }
        else if (s.at(i)==')')
        {
           while(top!=NULL)
           {
            postfix+=pop();
           }
    
        }   
    }
    while(top!=NULL)
    {
        postfix+=pop();
    }
    cout<<"PostFix Expression"<<postfix<<endl;
    postfix_evaluation(postfix);
}

int main()
{
    Stack s1;
    // s1.postfix_evaluation("623+-382/+*2^3+");
    s1.infix_evaluation("(((6-(2+3))*(3+8/2)^2)+3)");
    return 0;
}