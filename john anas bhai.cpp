#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int unique_id = 0;
class node
{
private:
    int id;
    char gender;
    node *next;
    node *prev;

public:
    node();
    void setid();
    int getid();
    char setgender();
    char getgender();
    void setnext(node *);
    node *getnext();
};
node ::node()
{
    setid();
    setgender();
    next = nullptr;
}
void node::setid()
{
    ++unique_id;
    id = unique_id;
}
int node ::getid()
{
    return id;
}
char node ::setgender()
{
int randomnum = rand() % 2;
    gender = (randomnum == 0) ? 'M' : 'F';
    return gender;
}
char node ::getgender()
{

    return gender;
}
void node ::setnext(node *ptr)
{
    next = ptr;
}
node *node ::getnext()
{
    return next;
}
class list
{
private:
    node *head;
    node *current;
    int total_stud;

public:
    list();
    void addstudent();
    void eliminatestudent();
    void displayStudents();
};
list ::list()
{
    head = nullptr;
    current = nullptr;
    total_stud = 0;
}
void list ::addstudent()
{
    node *ptr = new node(); // new element d is in ptr
    if (total_stud == 0)
    {
        head = ptr;
        current = ptr;
        head->setnext(head);
    }
    else
    {
        ptr->setnext(head);    // giving value of next to new element assigned to ptr
        current->setnext(ptr); // giving address of new node to previous element of list
        current = ptr;         // changing current to ptr
    }

    ++total_stud;
};
void list ::eliminatestudent()
{
    int total_fem = 0, total_male = 0;

    int crid;
    int grid;
    char crgender;
    char grgender;
    node *temp = head;
    node *ptr = current = head;
    while (total_stud > 2)
    {
        ptr = ptr->getnext();
        current->setnext(ptr->getnext());
        node *search = head;
        if (ptr->getgender() == 'F')
        {grid = ptr->getid();
        grgender=ptr->getgender();
        }
        else if(ptr->getgender()=='M'){
        crid=ptr->getid();
        crgender=ptr->getgender();
        }
        delete ptr;
            current = current->getnext();
            ptr = current;
            total_stud--;
        
    }
    total_stud=2;
    
    cout << "CR WILL BE: " << crid <<" " <<crgender<< endl;
    cout << "GR WILL BE: " << grid <<" " <<grgender<< endl;
}
;
void list::displayStudents()
{
    node *temp = head;
    cout << "Students in the circle: ";
    for (int i = 0; i < total_stud; ++i)
    {
        cout << temp->getid() << " " << temp->getgender() << endl;
        temp = temp->getnext();
    }
    cout << endl;
}
int main()
{
    srand(time(nullptr));
    list studentsList;
    for (int i = 0; i < 5; ++i)
    {
        studentsList.addstudent();
    }
    studentsList.displayStudents();

    // Eliminating students
    studentsList.eliminatestudent();
    
    return 0;
}