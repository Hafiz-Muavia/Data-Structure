
#include <iostream>
#include <cstring>
#include <cmath>
#define Max 100
char infix[Max], postfix[Max];
using namespace std;
class Node
{
    int data;
    Node *next;

public:
    Node() {}
    Node(int data)
    {
        setdata(data);
        next = NULL;
    }
    void setdata(int data)
    {
        this->data = data;
    }
    void setnext(Node *ptr)
    {
        next = ptr;
    }
    int getdata()
    {
        return data;
    }
    Node *getnext()
    {
        return next;
    }
};
class Stack
{
    Node *top;
    Node *current;
    int size;

public:
    Stack()
    {
        top = current = NULL;
        size = 0;
    }
    ~Stack()
    {
        current = top;
        Node *temp;
        while (current != NULL)
        {
            temp = current;
            delete temp;
            temp = nullptr;
            current = current->getnext();
        }
        delete current;
        delete top;
    }
    bool IsEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
    bool IsFull(Node *ptr)
    {
        if (ptr != NULL)
            return true;
        else
            return false;
    }
    void Push(char character)
    {
        Node *ptr = new Node(character);
        // if(IsFull(ptr)){
        //     cout<<"Stack Overflow";
        //     exit(1);
        // }
        if (top == NULL)
        {
            top = current = ptr;
        }
        else
        {
            ptr->setnext(current);
            top = current = ptr;
        }
        size++;
    }
    char pop()
    {
        if (IsEmpty())
        {
            cout << "Stack Underflow";
            exit(1);
        }
        Node *ptr;
        ptr = top;
        top = top->getnext();
        char val = ptr->getdata();
        delete ptr;
        ptr = nullptr;
        return val;
    }
    char peek()
    {
        if (IsEmpty())
        {
            cout << "Stack Underflow";
            exit(1);
        }
        return top->getdata();
    }
    double Eveluate(char postfix[], Stack &S2)
    {
        int i = 0, j = 0;
        char ch;
        int A, B;
        for (int i = 0; i < strlen(postfix); i++)
        {
            if (postfix[i] >= '0' && postfix[i] <= '9')
                S2.Push(postfix[i] - '0');
            else
            {
                A = S2.pop();
                B = S2.pop();
                switch (postfix[i])
                {
                case '+':
                    S2.Push(B + A);
                    break;
                case '*':
                    S2.Push(B * A);
                    break;
                case '/':
                    S2.Push(B / A);
                    break;
                case '-':
                    S2.Push(B - A);
                    break;
                case '^':
                    S2.Push(pow(B, A));
                    break;
                }
            }
        }

        return S2.pop();
    }
};
bool Space(char c)
{
    if (c == '\t' || c == ' ')
        return true;
    else
        return false;
}
int Precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
        break;
    case '/':
    case '*':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;

    default:
        return 0;
        break;
    }
}
void Infix_TO_PostFix()
{
    Stack Stack1;
    int m = 0;
    char current_chr, next;
    for (int i = 0; i < strlen(infix); i++)
    {
        current_chr = infix[i];
        if (!Space(current_chr))
        {
            switch (current_chr)
            {
            case '(':
                Stack1.Push(current_chr);
                break;
            case ')':
                while ((next = Stack1.pop()) != '(')
                {
                    postfix[m++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!Stack1.IsEmpty() && Precedence(Stack1.peek()) >= Precedence(current_chr))
                {
                    postfix[m++] = Stack1.pop();
                }
                Stack1.Push(current_chr);
                break;
            default:
                postfix[m++] = current_chr;
                break;
            }
        }
    }
    while (!Stack1.IsEmpty())
    {
        postfix[m++] = Stack1.pop();
    }
    postfix[m] = '\0';
}
void printpostfix()
{
    int i = 0;
    cout << "\nPostFix Expression" << endl;
    while (postfix[i] != '\0')
    {
        cout << postfix[i];
        i++;
    }
}
int main()

{
    double result;
    Stack S1, S2;
    cout << "Enter your infix Expression:";
    cin.getline(infix, Max);
    Infix_TO_PostFix();
    printpostfix();
    result = S1.Eveluate(postfix, S2);
    cout << "\nAns will be " << result;
    return 0;
}