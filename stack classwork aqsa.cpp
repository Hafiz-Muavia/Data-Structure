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
    Node *top;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }
    ~Stack()
    {
        delete top;
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
    size++;
}
int Stack::pop()
{
    Node *temp = new Node;
    if (IsEmpty())
    {
        cout << "\nStack Underflow Occurs";
        return 0;
    }
    Node *ptr = new Node;
    temp = top;
    top = top->getnext();
    return temp->getdata();
    size--;
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
void add(Stack &S1, Stack &S2)
{
    int num1, num2, element;
start:
again:
    cout << "\nEnter no of element for Stack1:";
    cin >> num1;
    if (num1 > 5 || num1 <= 0)
        goto again;
        again2:
    cout << "\nEnter no of element for STack2: ";
    cin >> num2;
    if (num2 > 5 || num2 <= 0)
        goto again2;
        if(num1!=num2){
            cout<<"Both Stacks should have Same no. of Elements";
            cout<<"\nEnter again";
            goto start;
        }
        cout<<"\nNow Enter values for Stack1"<<endl;
    for (int i = 1; i <= num1; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> element;
        S1.push(element);
    }

   cout<<"\nNow Enter values for Stack2"<<endl;
    for (int i = 1; i <= num2; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> element;
        S2.push(element);
    }
}
void reverse(Stack &S3)
{
    Stack S1, S2;
    while (!S3.IsEmpty())
    {
        S2.push(S3.pop());
    }

    while (!S2.IsEmpty())
    {
        S1.push(S2.pop());
    }

    while (!S1.IsEmpty())
    {
        S3.push(S1.pop());
    }
}
void multiply(Stack s1, Stack s2, Stack &S3)
{
    Stack S1 = s1;
    Stack S2 = s2;

    int value;

    while (!S1.IsEmpty() && !S2.IsEmpty())
    {
        S3.push(S1.pop() * S2.pop());
    }
}
int main()

{

    Stack S1, S2, S3;
    add(S1, S2);
    cout << "\nValues in Sack1 " << endl;
    S1.print();

    cout << "\nValues in Sack2 " << endl;
    S2.print();
    multiply(S1, S2, S3);
    reverse(S3);
    cout << "\nValues in Sack3 " << endl;

    S3.print();
    return 0;
}