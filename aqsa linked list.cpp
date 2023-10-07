#include <iostream>

using namespace std;
// NODE CLASS FOR EACH NODE
class Node
{
public:
    int data;
    Node *link;
    // DEFAULT CONSTRUCTOR
    Node()
    {
        data = 0;
        link = NULL;
    }
    // PARAMETRISED CONSTRUCTOR TO STORE DATA IN A NEW NODE
    Node(int);
};
Node::Node(int data)
{
    this->data = data;
    this->link = NULL;
}
// LINKEDLIT CLASS
class LinkedList
{
    Node *head;

public:
    // defaut constructor
    LinkedList();
    // OR INSIDE CLASS
    // LinkedList()
    // {
    //     head = NULL;
    // }
    void InsertNode(int);
    void DelNode(int);
    // TO PRINT LINKED LIST ELEMENTS
    void print();
    void Search(int);
    void update(int, int);
    int IsEmpty();
};
void LinkedList::update(int data, int pos)
{
    if (IsEmpty())
    {
        cout << "List is already empty" << endl;
        return;
    }
    else
    {
        Node *NewNode = new Node(data);

        int size = 0;
        Node *ptr = head;
        while (ptr != NULL)
        {

            ptr = ptr->link;
            size++;
        }
        if (pos == 1)
        {

           head->data=data;
        }
        if (size < pos)
        {
            cout << "Index not available" << endl;
            return;
        }

        else
        {
            ptr = head;

            while (pos != 1)
            {

                ptr = ptr->link;
                pos--;
            }
            ptr->data = data;
        }
    }
}
int LinkedList::IsEmpty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}
LinkedList::LinkedList()
{
    head = NULL;
}
void LinkedList::InsertNode(int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
    }
    // NEED TO TRAVERSE THE LIST TO INSERTAT LAST
    else
    {
        Node *ptr = head;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = newNode;
    }
}
void LinkedList::print()
{
    if (IsEmpty())
    {
        cout << "list is already Empty" << endl;
        return;
    }
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->link;
    }
}
void LinkedList::DelNode(int pos)
{
    if (IsEmpty())
    {
        cout << "List is Already Empty" << endl;
        return;
    }
    if (pos == 1)
    {
        Node *temp = head;
        head = head->link;
        delete temp;
        return;
    }
    else
    {
        int length = 0;
        // TRAVERSEL IS NEEDED
        Node *ptr = head;
        while (ptr != NULL)
        {

            ptr = ptr->link;
            length++;
        }
        Node *temp = head;
        if (length < pos)
        {
            cout << "Index is not available" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            Node *temp2;
            while (pos != 1)
            {
                temp2 = temp;
                temp = temp->link;
                pos--;
            }
            temp2->link = temp->link;
            delete temp;
        }
    }
}
void LinkedList::Search(int data)
{
    int count = 0;
    if (IsEmpty())
    {
        cout << "No data in the List" << endl;
        return;
    }
    else
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == data)
                count++;
            ptr = ptr->link;
        }
        cout << "data find " << count << " times" << endl;
    }
}
int main()

{
    LinkedList list;
    int data, choice, pos;
    while (1)
    {
        cout << "\n1)INSERT" << endl;
        cout << "2)DELETE" << endl;
        cout << "3)PRINT" << endl;
        cout << "4)Search" << endl;
        cout << "5)UPDATE" << endl;
        cout << "Enter your Choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data to insert:" << endl;
            cin >> data;
            list.InsertNode(data);
            break;
        case 2:
            cout << "Enterposition to del:" << endl;
            cin >> pos;
            list.DelNode(pos);
            break;
        case 3:

            list.print();
            break;
        case 4:
            cout << "Enter data to search:" << endl;
            cin >> data;
            list.Search(data);
            break;
        case 5:
            cout << "Enter data to update:" << endl;
            cin >> data;
            cout << "Enter Pos to update:" << endl;
            cin >> pos;
            list.update(data, pos);
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }


}
