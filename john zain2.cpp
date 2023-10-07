#include <iostream>
using namespace std;
class student
{
private:
    int pos;
    char gender;
    student *next;
    student *previous;

public:
    student(int, char);

    void setnext(student *);
    student *getnext();

    void setprevious(student *);
    student *getprevious();

    char getgender();

    int getposition();
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
    void addnode(int, char);
    void joseph();
    void show_all();
    void show_remaining();
    ~list();
};

student::student(int p, char g)
{
    pos = p;
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

int student::getposition()
{
    return pos;
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

    int n;
    char gen;
    cout << "Enter number of students you want in list ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int randomnum = rand() % 2;
        gen = (randomnum == 0) ? 'M' : 'F';
        addnode(i, gen);
    }
}
void list::addnode(int p, char g)
{
    student *ptr = new student(p, g);
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
        current = ptr;
    }
    size++;
}
void list::show_all()
{
    cout<<"Boys and their positions "<<endl;
    student *ptr = head_boy;
    for (int i = 1; i <= size; i++)
    {
        if (ptr->getgender() == 'M')
        {
            cout << "BOY : "<< ptr->getposition() << endl;
        }
        ptr = ptr->getnext();
    }

    cout<<"Girls and their positions "<<endl;
    ptr=head_girl;
    for (int i = 1; i <= size; i++)
    {
       if (ptr->getgender() == 'F')
    {

        cout << "GIRL : " << ptr->getposition() << endl;
    }
        ptr = ptr->getnext();
    }
    cout<<"---------------------------------------------"<<endl;

    
}
void list::show_remaining()
{
    student *ptr = head_boy;
    cout << "CR : " << ptr->getposition() << endl;
    ptr=head_girl;
    cout << "GR : " << ptr->getposition() << endl;
 
}
void list::joseph()
{
    student *ptr = current = head_boy;
    while (boy_count > 1)
    {
        ptr = current;
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
    while (girl_count > 1)
    {
        ptr = current;
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
    l1.show_all();
    l1.joseph();
    l1.show_remaining();
    return 0;
}