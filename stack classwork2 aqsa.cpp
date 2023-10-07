#include <iostream>

using namespace std;
class Node
{
    int data;
    Node *link;

public:
    void setdata(int);
    int getdata();
    void setnext(Node *);
    Node *getnext();
} *top = NULL;
void Node::setdata(int data)
{
    this->data = data;
}
int Node::getdata()
{
    return data;
}
void Node::setnext(Node *ptr)
{
    link = ptr;
}
Node *Node::getnext()
{
    return link;
}
class Stack
{
    Node *top = NULL;

public:
    Stack()
    {
        top = NULL;
    }
    bool IsEmpty();
    bool IsFull();
    void push(int);
    int pop();
    void print();
    int Top();
};

bool Stack::IsEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
bool Stack::IsFull()
{
    Node *ptr = new Node;
    if (ptr == NULL)

        return 1;
    else
        return 0;
}
void Stack::push(int data)
{
    Node *ptr = new Node;
    if (IsFull())
    {
        cout << "Stack Overflow Occurs";
        exit(1);
    }
    ptr->setdata(data);
    ptr->setnext(top);
    top = ptr;
}
int Stack::pop()
{
    int value;
    Node *temp = new Node;
    if (IsEmpty())
    {
        cout << "\nStack Underflow Occurs";
        return 0;
    }
    Node *ptr = new Node;
    temp = top;
    top = top->getnext();
    value = temp->getdata();
    delete temp;
    temp = nullptr;

    return value;
}
void Stack::print()
{
    Node *temp = new Node;
    if (IsEmpty())
    {
        cout << "Stack is Empty" << endl;
        return;
    }
    Node *ptr = new Node;
    temp = top;
    while (temp != NULL)
    {
        cout << temp->getdata() << " ";
        temp = temp->getnext();
    }
}
int Stack::Top()
{
    if (IsEmpty())
    {
        cout << "Stack is Empty" << endl;
        return 0;
    }
    return top->getdata();
}
void reverse(Stack &S1, Stack &S2, Stack &S3)
{

    while (!S1.IsEmpty())
    {
        S2.push(S1.pop());
    }

    while (!S2.IsEmpty())
    {
        S3.push(S2.pop());
    }

    while (!S3.IsEmpty())
    {
        S1.push(S3.pop());
    }
}
void add(Stack &S1)
{
    int num, element;
    cout << "Enter no tof element to insert into Stack: ";
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        cout << "\nEneter element " << i << ": ";
        cin >> element;
        S1.push(element);
    }
}
int main()

{
    int value;
    Stack S1, S2, S3;
    add(S1);
    cout << "Orignal Stack Before Reverse: " << endl;
    S1.print();
    reverse(S1, S2, S3);
    cout << "\nOrignal Stack After Reverse: " << endl;
    S1.print();
    return 0;
}