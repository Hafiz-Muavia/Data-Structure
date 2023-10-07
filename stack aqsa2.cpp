#include <iostream>

using namespace std;
class Stack{
int data;
   Stack* link;
   
   public:
  bool IsEmpty();
  bool IsFull();
   void push(int );
   int pop();
   void print();
   int Top();} *top = NULL;

bool Stack::IsEmpty(){
    if(top==NULL)
    return 1;
    else return 0;
}
bool Stack:: IsFull(){
  Stack* ptr=new Stack;
      if (ptr->link == NULL)
    
        return 1;
    else return 0;
}
void Stack::push(int data)
{
    Stack* ptr=new Stack;
    if (IsFull())
    {
        cout << "Stack Overflow Occurs";
        exit(1);
    }
    ptr->data = data;
    ptr->link= top;
    top = ptr;
}
int Stack:: pop()
{
     Stack* temp=new Stack;
    if (IsEmpty())
    {
        cout << "\nStack Underflow Occurs";
        return 0;
    }
    Stack* ptr=new Stack;
    temp = top;
    top = top->link;
    return temp->data;
}
void Stack:: print()
{
     Stack* temp=new Stack;
    if(IsEmpty()){
        cout<<"Stack is Empty"<<endl;
        return ;
    }
    Stack* ptr=new Stack;
    temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
}
int Stack:: Top(){
    if(IsEmpty()){
        cout<<"Stack is Empty"<<endl;
        return 0;
    }
    return top->data;
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
