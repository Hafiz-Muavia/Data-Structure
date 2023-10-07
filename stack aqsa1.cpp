#include <iostream>
#define Max 5
using namespace std;


class Stack{
int top ;

int stack_Arr[Max];
public:
Stack(){
int top = -1;

}
int isFull();
int isEmpty();
int Top();
void push(int );
int pop();
void print();
};

int Stack:: isFull()
{
    if (top == Max - 1)
        return 1;
    else
        return 0;
}
int Stack::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int Stack:: Top(){
    if(isEmpty()){
        cout<<"Stack is Empty";
        exit(1);
    }
    return stack_Arr[top];
}

void Stack::push(int data)
{
    if (isFull())
    {
        cout << "\nStack Overflow Occurs this will not added ";
        return;
        // exit(1);
    }

    top++;
    stack_Arr[top] = data;
}
int Stack::pop()
{
    if (isEmpty())
    {
        cout << "\nStack Underflow Occurs";
        // return 0;
        exit(1);
    }
    int value;
    value = stack_Arr[top];
    top--;

    return value;
}
void Stack:: print()
{
    if (top == -1)
    {
        cout << "\nStack is Empty";
        exit(1);
    }
    for (int i = top; i >= 0; i--)
    {
        cout << " " << stack_Arr[i] << " ";
    }
}

int main()

{
    int choice, value;
    int data;
   Stack S1;
    while (1)
    {
         cout << "\n1) PUSH" << endl;
    cout << "2) POP" << endl;
    cout << "3) PRINT" << endl;
    cout << "4) TOP" << endl;
    cout << "5) EXIT" << endl;
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
            cout<<"Peek or top most element is: "<<S1.Top();

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
