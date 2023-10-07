#include <iostream>
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
    void showdata();
};
class list
{
private:
    node *head;
    node *current;
    int size;

public:
    list();
    void addnode(int);
    void update(int, int);
    void start();
    void tail();
    void next();
    void back();
    void find(int);
    void get(int);
    void totalLength();
    void showlist();
};

node::node(int d)
{
    setdata(d);

    next = NULL;
}
void node::setdata(int d)
{
    data = d;
}
int node::getdata()
{
    return data;
}

void list :: find(int d)
{
    node* ptr=head;
    bool y=false;
    for(int i=1;i<=size;i++)
    {
        if(ptr->getdata()==d)
        {
            cout<<"Value is present in the list "<<endl;
            y=true;
            break;
        }
        ptr=ptr->getnext();
    }

    if(y==false)
    {
        cout<<"Value not found in array "<<endl;
    }
}
void node::setnext(node *ptr)
{
    next = ptr;
}
node *node::getnext()
{
    return next;
}
void node::showdata()
{
    cout << "data is:" << data << endl;
}

list::list()
{
    head = NULL;
    current = NULL;
    size = 0;
}
void list ::next()
{
    if (current->getnext() != NULL)
    {
        node *ptr = current;
        ptr = ptr->getnext();
        current = ptr;
    }
}
void list ::back()
{
    if (current != head)
    {
        node *ptr = head;
        while (ptr->getnext() != current)
        {
            ptr = ptr->getnext();
        }
        current = ptr;
        current->showdata();
    
    }
    else
    {
        cout<<"Invalid operation "<<endl;
    }
}
    void list ::start()
    {
        current = head;
    }
    void list ::tail()
    {
        node *ptr = head;
        for (int i = 1; i < size; i++)
        {
            ptr = ptr->getnext();
        }
        current = ptr;
    }
    void list:: totalLength()
    {
        cout<<"Total length of list is "<<size<<endl;
    }
    void list::addnode(int d)
    {
        node *ptr = new node(d); // new element d is in ptr
        if (size == 0)
        {
            head = ptr;
            current = ptr;
        }
        else
        {
            ptr->setnext(current->getnext()); // giving value of next to new element assigned to ptr
            current->setnext(ptr);            // giving address of new node to previous element of list
            current = ptr;                    // changing current to ptr
        }
        size++;
    }
    void list ::update(int pos, int val)
    {
        node *ptr = head;
        if (pos > 0 && pos <= size)
        {
            for (int i = 1; i < pos; i++)
            {
                ptr = ptr->getnext();
            }
            ptr->setdata(val);
        }
        else
        {
            cout << "Invalid positon " << endl;
        }
    }
    void list :: get(int pos)
    {
        node* ptr=head;
        if(pos>0 && pos<=size)
        {
            for(int i=1;i<pos;i++)
            {
                ptr=ptr->getnext();
            }
            cout<<"The value at the given position in the list is "<<ptr->getdata();
        }
        else
        {
            cout<<"Invalid position "<<endl;
        }
    }
    void list::showlist()
    {
        node *ptr = head;
        while (ptr != NULL)
        {
            ptr->showdata();
            ptr = ptr->getnext(); // assigning address of next element
        }
    }

    int main()
    {
        list l1;
        l1.addnode(5);
        l1.addnode(7);
        l1.addnode(9);
        l1.update(1,10);
        l1.showlist();
l1.get(2);

        return 0;
    }