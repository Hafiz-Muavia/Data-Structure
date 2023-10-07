#include <iostream>

using namespace std;
class Node{
int data;
  Node* link;
   public:
   void setdata(int);
   int getdata();
   void setnext(Node*);
   Node* getnext();
}*top = NULL;
void Node::setdata(int data){
    this->data=data;
}
int Node::getdata(){
    return data;
}
void Node:: setnext(Node* ptr){
    link=ptr;
}
Node* Node::getnext(){
    return link;
}
class Stack{
   public:
  bool IsEmpty();
  bool IsFull();
   void push(int );
   int pop();
   void print();
   int Top();
   } ;

bool Stack::IsEmpty(){
    if(top==NULL)
    return 1;
    else return 0;
}
bool Stack:: IsFull(){
Node* ptr=new Node;
      if (ptr->getnext() == NULL)
    
        return 1;
    else return 0;
}
void Stack::push(int data)
{
    Node* ptr=new Node;
    if (IsFull())
    {
        cout << "Stack Overflow Occurs";
        exit(1);
    }
    ptr->setdata(data);
    ptr->setnext(top);
    top = ptr;
}
int Stack:: pop()
{
     Node* temp=new Node;
    if (IsEmpty())
    {
        cout << "\nStack Underflow Occurs";
        return 0;
    }
    Node* ptr=new Node;
    temp = top;
    top = top->getnext();
    return temp->getdata();
}
void Stack:: print()
{
     Node* temp=new Node;
    if(IsEmpty()){
        cout<<"Stack is Empty"<<endl;
        return ;
    }
    Node* ptr=new Node;
    temp = top;
    while (temp != NULL)
    {
        cout << temp->getdata() << " ";
        temp = temp->getnext();
    }
}
int Stack:: Top(){
    if(IsEmpty()){
        cout<<"Stack is Empty"<<endl;
        return 0;
    }
    return top->getdata();
}
int main()

{

Stack S1;
    int choice, data,value;
   
    while (1)
    {
         cout << "\n1) PUSH " << endl;
    cout << "\n2) POP "  << endl;
    cout << "\n3) PRINT "  << endl;
    cout << "\n4) Top "  << endl;
    cout << "\n5) EXIT"  << endl;
        cout << "\nEnter your Choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter data for Push:";
            cin >> data;
            S1.push(data);
            break;
        case 2:
            value = S1.pop();
            cout << "\nDel value is:" << value;
            break;
        case 3:
            cout << "\nValues are: ";
            S1.print();
            break;
        case 4:
            cout << "Peek or top most element in Stack is: "<< S1.Top();

            break;
        case 5:

            exit(1);
            break;
        default:
            cout << "invalid choice";
            break;
        }
    }

   
    return 0;
}