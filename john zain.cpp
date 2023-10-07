#include <iostream>
using namespace std;
class student
{
private:
    string name;
    char gender;
    student *next;
    student *previous;

public:
    student(string, char);

    void setnext(student *);
    student *getnext();

    void setprevious(student *);
    student *getprevious();

    char getgender();

    string getname();
};

class list
{
private:
    student *head;
    student *head_boy;
    student *head_girl;
    student *current;
    int boy_count;
    int girl_count;
    int size;

public:
    list();
    void addnode(string, char);
    void joseph();
    void showlist();
    ~list();
};

student::student(string n, char g)
{
    name = n;
    gender = g;
}
void student::setnext(student *ptr)
{
    next = ptr;
}
student *student::getnext()
{
    return next;
}

void student::setprevious(student *ptr)
{
    previous = ptr;
}
student *student::getprevious()
{
    return previous;
}

string student::getname()
{
    return name;
}
char student::getgender()
{
    return gender;
}

list::list()
{
    head = NULL;
    current = NULL;
    boy_count = 0;
    girl_count = 0;
    size = 0;

    addnode("John", 'M');
    addnode("Alice", 'F');
    addnode("Bob", 'M');
    addnode("Eve", 'F');
    addnode("Charlie", 'M');
    addnode("Olivia", 'F');
    addnode("David", 'M');
    addnode("Sophia", 'F');
    addnode("Frank", 'M');
    addnode("Emma", 'F');
    addnode("George", 'M');
    addnode("Lily", 'F');
    addnode("Henry", 'M');
    addnode("Ava", 'F');
    addnode("Jack", 'M');
    addnode("Mia", 'F');
    addnode("William", 'M');
    addnode("Ella", 'F');
    addnode("Daniel", 'M');
    addnode("Grace", 'F');
    addnode("Michael", 'M');
    addnode("Sophie", 'F');
    addnode("James", 'M');
    addnode("Lucy", 'F');
    addnode("Sam", 'M');
    addnode("Chloe", 'F');
    addnode("Andrew", 'M');
    addnode("Aria", 'F');
    addnode("Joseph", 'M');
    addnode("Zoe", 'F');
    addnode("Robert", 'M');
    addnode("Hannah", 'F');
    addnode("Benjamin", 'M');
    addnode("Victoria", 'F');
    addnode("Matthew", 'M');
    addnode("Madison", 'F');
    addnode("John", 'M');
    addnode("Emily", 'F');
    addnode("William", 'M');
    addnode("Lily", 'F');
    addnode("Michael", 'M');
    addnode("Grace", 'F');
    addnode("James", 'M');
    addnode("Sophie", 'F');
    addnode("Daniel", 'M');
    addnode("Olivia", 'F');
    addnode("Ethan", 'M');
    addnode("Ava", 'F');
    addnode("Christopher", 'M');
    addnode("Isabella", 'F');
    addnode("Andrew", 'M');
    addnode("Abigail", 'F');
    addnode("Joseph", 'M');
    addnode("Ella", 'F');
    addnode("Matthew", 'M');
    addnode("Chloe", 'F');
    addnode("Benjamin", 'M');
    addnode("Hannah", 'F');
    addnode("David", 'M');
    addnode("Zoe", 'F');
}
void list::addnode(string n, char g)
{
    student *ptr = new student(n, g);
    if (g == 'M')
    {
        if (boy_count == 0)
        {
            head_boy = ptr;
            boy_count++;
        }
        else
        {
            boy_count++;
        }
    }
    else
    {
        if (girl_count == 0)
        {
            head_girl = ptr;
            girl_count++;
        }
        else
        {
            girl_count++;
        }
    }

    if (size == 0)
    {
        head = ptr;
        current = ptr;
        current->setnext(head);
        current->setprevious(head);
    }
    else
    {
        head->setprevious(ptr);
        ptr->setnext(head);
        ptr->setprevious(current);
        current->setnext(ptr);
        current=ptr;
    }
    size++;
}
void list::showlist()
{
    student *ptr = head_boy;
    cout<<"CR : "<<ptr->getname()<<endl;
    ptr = head_girl;
    cout<<"GR : "<<ptr->getname()<<endl;


}

void list::joseph()
{
    student *ptr = current = head_boy;
    while (boy_count >1)
    {
        ptr=current;
        ptr = ptr->getnext();
        while (ptr->getgender() != 'M')
        {
            ptr = ptr->getnext();
        }
        current = ptr->getprevious();
        current->setnext(ptr->getnext());
        delete ptr;
        size--;
        boy_count--;
        ptr = current->getnext();

        ptr->setprevious(current);
        current = ptr;
        while (current->getgender() != 'M')
        {
            current = current->getnext();
        }
        head_boy = current;
    }

    ptr = current = head_girl;
    while (girl_count >1)
    {
        ptr=current;
        ptr = ptr->getnext();
        while (ptr->getgender() != 'F')
        {
            ptr = ptr->getnext();
        }
        current = ptr->getprevious();
        current->setnext(ptr->getnext());
        delete ptr;
        size--;
        girl_count--;
        ptr = current->getnext();

        ptr->setprevious(current);
        current = ptr;
        while (current->getgender() != 'F')
        {
            current = current->getnext();
        }
        head_girl = current;
    }
}
list::~list()
{
    current = head_boy;
    delete current;
    current = head_girl;
    delete current;
}
int main()
{
    list l1;
     l1.joseph();
    l1.showlist();
    return 0;
}