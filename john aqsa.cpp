#include <iostream>

using namespace std;
class Node
{
    string name;
    char ch;
    Node *next;

public:
    Node() {}
    Node(string, char);
    void setnext(Node *);
    Node *getnext();
    void setname(string);
    string getname();
    void setgender(char);
    char getgender();
};
Node::Node(string name, char ch)
{
    setname(name);
    setgender(ch);
    next = NULL;
}
void Node::setnext(Node *ptr)
{
    next = ptr;
}
Node *Node::getnext()
{
    return next;
}
void Node::setname(string name)
{
    this->name = name;
}
string Node::getname()
{
    return name;
}
void Node::setgender(char ch)
{
    this->ch = ch;
}
char Node::getgender()
{
    return ch;
}
class linkedList
{
    Node *head;
    Node *current;
    int size = 0;

public:
    linkedList();
    void add(string, char);
    void display();
    void jusphus(int);
    void Delete();
};
linkedList::linkedList()
{
    head = current = NULL;
    size = 0;
}
void linkedList::add(string name, char ch)
{

    Node *ptr = new Node(name, ch);
    ptr->setnext(NULL);
    if (head == NULL)
    {
        head = ptr;
        head->setnext(head);
        current = head;
    }
    else
    {
        ptr->setnext(current->getnext());
        current->setnext(ptr);
        current = ptr;
        head = ptr;
    }
    size++;
}
void linkedList::jusphus(int k)
{
    Node *ptr = new Node;
    ptr = NULL;
    int size_jusphus = size;
    current = head->getnext();
    ptr = head->getnext();
    while (size_jusphus > 1)
    {

        for (int i = 1; i <= k; i++)
        {
            ptr = current;
            current = current->getnext();
        }
        ptr->setnext(current->getnext());
        delete current;
        current->setnext(NULL);
        size_jusphus--;
        current = ptr->getnext();
    }
    head=ptr;
}
void linkedList::display()
{
    current = head->getnext();
  do
    {
        cout << current->getname() << " "<<current->getgender()<<" ";
        cout<<endl;
        current = current->getnext();
    }  while (current != head->getnext());
  
}
int main()

{
    int num;
    int k = 1;
    string name;
    char ch;
    linkedList list1, list2;

    cout << "\nEnter no of students";
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        cout << "\nEnter name:";
        cin >> name;
    again:
        cout << "\nEnter gender M for(male), F for(Female):";
        cin >> ch;
        if (ch == 'M' || ch == 'm')
            list1.add(name, ch);
        else if (ch == 'f' || ch == 'F')
        {
            list2.add(name, ch);
        }
        else
        {
            cout << "Invalid enter gender again" << endl;
            goto again;
        }
    }
cout<<"\n====== Male Students ======"<<endl;
    list1.display();
    list1.jusphus(k);
    cout << endl;
    cout<<"------ CR -------"<<endl;
      list1.display();
    cout<<"\n===== Female Students ====="<<endl;
       list2.display();
       list2.jusphus(k);
         cout<<"------ GR -----"<<endl;
         list2.display();
    return 0;
}