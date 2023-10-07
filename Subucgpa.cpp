#include <iostream>
#include <cstdlib>
#include "dobsubu.h"
#include "cgpasubu.h"
#include "Listsubu.h"
using namespace std;

class Student //class name
{
	private:
		//data members
		string id;
		string name;
	public:
		//member functions
		void set()
		{
		cout<<"Enter student ID: ";
		cin>>id;
		cout<<"Enter student name: ";
		cin>>name;
		}
		void get()
		{
		cout<<"Student ID is: "<<id<<endl;
		cout<<"Student name is: "<<name<<endl;
		}
};
int main()
{
	system("start Notepad.exe Student.txt");
	string name = "Subhan";
	string password = "12345";
	string user_name;
	string pass;
	
	Input:
	cout<<"Enter username: ";
	cin>>user_name;
	cout<<"Enter your password: ";
	cin>>pass;
	
	if(user_name==name && pass == password)		//condition to login
	{
		cout<<"You have logined. ";
		cout<<endl;
	}
	else
	{
		cout<<"Access denied. "<<endl;
		goto Input;
	}
	
	Student Stu1;
	Stu1.set();
	Stu1.get();
	
    DATE current, birth, total;
    birth.setAge(31, 8, 2003);
    current.setAge(20, 6, 2023);
    cout << " Birth Date " << endl;
    birth.showAge();
    cout << " Current Date " << endl;
    current.showAge();
    cout << " Your age is " << endl;
    total = current - birth;
    total.showAge();
    
	Data sem1,sem2,sem3;
	cout<<"Marks of sem1  "<<endl;
	sem1.setvalues(5);
	cout<<"Marks of sem2  "<<endl;
	sem2.setvalues(6);
	cout<<"Marks of sem3  "<<endl;
	sem3.setvalues(6); 
	
	cout << "::Displaying the gpa of each semester:: " << endl;
	cout<<"GPA of Semester 1 is : ";
	sem1.calc_gpa();
	sem1.showgpa();
	cout << endl;
	cout<<"GPA of Semester 2 is : ";
	sem2.calc_gpa();
	sem2.showgpa();
	cout << endl;
	cout<<"GPA of Semester 3 is : ";
	sem3.calc_gpa();
	sem3.showgpa();
	cout << endl;
	
	float c1,c2,c3,cgpa;
	c1= sem1.calc_gpa();
	c2= sem2.calc_gpa();
	c3= sem3.calc_gpa();
	cgpa =(c1+c2+c3)/3.0;
	cout<<"Cgpa of three semesters is  "<<cgpa<<endl;
	
	int num;
	int a,b,c,d,e;
	cout<<"Enter a number for semester for updation/deletion/insertion.  "; 
	//As 1 is for sem1 and 2 for sem2 and 3 for sem3
	cin>>num;
	if(num==1)
	{
		cout<<"Enter the position at which you want to insert: ";
		cin>>a;
		cout<<"Enter the inserted value: ";
		cin>>b;
		sem1.insert(a,b);
		sem1.get();
		cout<<endl;
		cout<<"Enter the position at which you want to update value: ";
		cin>>c;
		cout<<"Enter the updated value: ";
		cin>>d;
		sem1.update(c,d);
		sem1.get();
		cout<<endl;
		cout<<"Enter the value you want to delete: ";
		cin>>e;
		sem1.remove(e);
		sem1.get();
		cout<<endl;
	}
	else if(num==2)
	{
		cout<<"Enter the position at which you want to insert: ";
		cin>>a;
		cout<<"Enter the inserted value: ";
		cin>>b;
		sem2.insert(a,b);
		sem2.get();
		cout<<endl;
		cout<<"Enter the position at which you want to update value: ";
		cin>>c;
		cout<<"Enter the updated value: ";
		cin>>d;
		sem2.update(c,d);
		sem2.get();
		cout<<endl;
		cout<<"Enter the value you want to delete: ";
		cin>>e;
		sem2.remove(e);
		sem2.get();
		cout<<endl;	
	}
	else if(num==3)
	{
		cout<<"Enter the position at which you want to insert: ";
		cin>>a;
		cout<<"Enter the inserted value: ";
		cin>>b;
		sem3.insert(a,b);
		sem3.get();
		cout<<endl;
		cout<<"Enter the position at which you want to update value: ";
		cin>>c;
		cout<<"Enter the updated value: ";
		cin>>d;
		sem3.update(c,d);
		sem3.get();
		cout<<endl;
		cout<<"Enter the value you want to delete: ";
		cin>>e;
		sem3.remove(e);
		sem3.get();
		cout<<endl;
	}
	else 
		cout<<"You have entered invalid number...";

    list l1(3);
	l1.add(20);
	l1.next();
    l1.add(30);
    l1.back();
    l1.add(40);
    
	return 0;
}