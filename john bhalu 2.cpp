#include <iostream>
#include "john bhalu.cpp"
using namespace std;

static int noOfMales = 3;
static int noOfFemales = 2;

class node
{
private:
    data d;
    string status;
    node *next;

public:
    node(data);
    void setData(data);
    data getData();
    
    void setNext(node *);
    node* getNext();
    void showData();
};

node::node(data da)
{
    setData(da);
    next = NULL;
}

void node::setData(data da)
{
    d = da;
}

data node::getData()
{
    return d;
}

void node::setNext(node* ptr)
{
    next = ptr;
}

node* node::getNext()
{
    return next;
}

void node::showData()
{
    cout << "Name: " << d.getname() << "  Course: " << d.getcode() << "   Gender: " << d.getgender() << "    Status: " << d.getstatus() << endl;
}

class list
{
public:
    list();
    void add(data );
    void showList();
    void remove();
    void next();
    void start();
    int length(); 
    int countGender(string gender);
    int countStatus(string status);
    void setStatus(string gender, string status);

private:
    node *head;
    node *current;
    int size;
    int siz;
};

list::list()
{
    head = NULL;
    current = NULL;
    size = 0;
    siz = 0;
}

void list::add(data da)
{
    node *ptr = new node(da);
    if (size == 0)
    {
        head = ptr;
        current = ptr;
        current->setNext(head);
    }
    else
    {
        ptr->setNext(current->getNext());
        current->setNext(ptr);
        current = ptr;
    }
    size++;
}

void list::showList()
{
    if (size == 0)
    {
        cout << "List is empty" << endl;
        return;
    }

    node *ptr = head;
    do
    {
        data d = ptr->getData();
        string status = d.getgender();
        if (status == "m")
            status = "CR";
        else if (status == "f")
            status = "GR";

        cout << "Name: " << d.getname() << "  Course: " << d.getcode() << "   Gender: " << d.getgender() << "    Status: " << status << endl;

        ptr = ptr->getNext();
    } while (ptr != head);

    cout << endl;
}


int list::length()
{
    siz = 0;
    if (size == 0)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        node *ptr = head;
        do
        {
            ptr = ptr->getNext();
            siz++;
        } while (ptr != head);
    }
    return siz;
}

void list::remove()
{
    if (size == 0)
    {
        cout << "Empty list" << endl;
        return;
    }
    if (current == head)
    {
        head = head->getNext();
    }

    node* temp = current;
    node* ptr = head;

    do
    {
        if (ptr->getNext() == current)
        {
            break;
        }
        ptr = ptr->getNext();
    } while (ptr != head);

    ptr->setNext(current->getNext());
    current = current->getNext();
    delete temp;
    size--;

    // Update the counts based on gender
    if (temp->getData().getgender() == "m" && noOfMales > 0)
        noOfMales--;
    else if (temp->getData().getgender() == "f" && noOfFemales > 0)
        noOfFemales--;
}

void list::next()
{
    if (current != NULL)
        current = current->getNext();
}

void list::start()
{
    current = head;
}

int list::countGender(string gender)
{
    int count = 0;
    node* ptr = head;
    do
    {
        if (ptr->getData().getgender() == gender)
        {
            count++;
        }
        ptr = ptr->getNext();
    } while (ptr != head);

    return count;
}

int list::countStatus(string status)
{
    int count = 0;
    node* ptr = head;
    do
    {
        if (ptr->getData().getstatus() == status)
        {
            count++;
        }
        ptr = ptr->getNext();
    } while (ptr != head);

    return count;
}

void list::setStatus(string gender, string status)
{
    node* ptr = head;
    do
    {
        if (ptr->getData().getgender() == gender)
        {
            ptr->getData().setstatus(status);
        }
        ptr = ptr->getNext();
    } while (ptr != head);
}

int main()
{
    list l;
    int i, N = 5, M = 3;
    data d;

    string n, id, g;
    for (int i = 1; i <= N; i++) {
        cout << "Enter Name : ID : Gender : " << endl;
        cin >> n >> id >> g;
        l.add(data(n, id, g));
    }

    l.start();
    while (true)
    {
        for (i = 1; i <= M; i++)
            l.next();
        
        if (noOfMales == 1 && noOfFemales == 1)
            break;
        
        l.remove();
        l.showList();
    }

    l.setStatus("m", "CR");
    l.setStatus("f", "GR");

    cout << "Leaders:" << endl;
    l.showList();

    return 0;
}