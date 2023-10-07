#include <iostream>
#include <fstream>
#include <cstdlib>
#include "LogIN.h"
#include "DOB.h"
#include "CGPALinkedList.h"
#include "Linked_list.h"
using namespace std;
class Student{
	private:
		string id;
		string name;
		int dd,mm;
		int age;
	public:
		Student();
		void nameee(string);
		string getname();
		void setdob(int,int,int);
		void inID(string);
		string outID();
};
Student::Student(){
	id='\0';
	age=dd=mm=0;
	name='\0';
}
void Student::nameee(string abc){
	name=abc;
}
string Student::getname(){
	return name;
}
void Student::setdob(int v,int w,int s){
	dd=v;
	mm=w;
	age=s;
}
void Student:: inID(string s){
	this->id=s;
}
string Student::outID (){
	return id;
}
int main(){
	char hui;
	Student s1;
	DOB cur_date,dob,age;//object creation memory allocation and constructor calls
	int aa,vv,w,s;
	aa=LogIN();
	if(aa==1){
		s1.nameee("Hafiz Muavia");
		cout<<"Your name is "<<s1.getname()<<endl;
		dob.set(30,4,2002);//dob data
		cur_date.set(19,6,2023);//current data
		cout<<"Your age is: ";
	    age=cur_date-dob;//overloading - operator
	    age.get();//actual age
	    vv=age.getday();
	    w=age.getmonth();
	    s=age.getyear();
	    s1.setdob(vv,w,s);
	    s1.inID("BCS21001");
	    cout<<"Your student ID is: "<<s1.outID()<<endl;
	}
	else if(aa==2){
		s1.nameee("Soban Farooq");
		cout<<"Your name is "<<s1.getname()<<endl;
		dob.set(28,10,2003);//dob data
		cur_date.set(19,6,2023);//current data
		cout<<"Your age is: ";
	    age=cur_date-dob;//overloading - operator
	    age.get();//actual age
	    vv=age.getday();
	    w=age.getmonth();
	    s=age.getyear();
	    s1.setdob(vv,w,s);
	    s1.inID("BCS21051");
	    cout<<"Your student ID is: "<<s1.outID()<<endl;
	}
		else if(aa==3){
			s1.nameee("Abdul Subhan");
		cout<<"Your name is "<<s1.getname()<<endl;
		dob.set(11,11,2002);//dob data
		cur_date.set(19,6,2023);//current data
		cout<<"Your age is: ";
	    age=cur_date-dob;//overloading - operator
	    age.get();//actual age
	    vv=age.getday();
	    w=age.getmonth();
	    s=age.getyear();
	    s1.setdob(vv,w,s);
	    s1.inID("BCS21029");
	    cout<<"Your student ID is: "<<s1.outID()<<endl;
	}
	int x,sem=1;
	list l1,l2,l3;
	l1.newsem();
	cout<<"How many subjects in semester "<<sem<<": ";
	cin>>x;
	for(int i=1;i<=x;i++){
		l1.in();
	}
	float y=l1.gpapersem();
	l1.showlist();
	cout<<"GPA of semester "<<sem<<" is: "<<y<<endl;
	l1.cgpa(y);
	sem++;
	l2.newsem();
	cout<<"How many subjects in semester "<<sem<<": ";
	cin>>x;
	for(int i=1;i<=x;i++){
		l2.in();
	}
	l2.showlist();
	y=l2.gpapersem();
	cout<<"GPA of semester "<<sem<<" is: "<<y<<endl;
	l2.cgpa(y);
	sem++;
	l3.newsem();
	cout<<"How many subjects in semester "<<sem<<": ";
	cin>>x;
	for(int i=1;i<=x;i++){
		l3.in();
	}
	y=l3.gpapersem();
	l3.showlist();
	cout<<"GPA of semester "<<sem<<" is: "<<y<<endl;
	l3.cgpa(y);
	sem++;
	while(1){
		int a, marks, cred_hrs;
		string cname, ccode;
		float gpa, grade_points;
		cout<<"Enter choice: "<<endl;
		cout<<"1 for insertion\n2 for deletion\n3 for updation\n4 for find\n5 for get\n0 for exit"<<endl;
		cin>>x;
		int z;
		if(x==1){
		cout<<"in which semester you want to insert: ";
		cin>>z;
		cout<<"At which index you want to insert: ";
				cin>>a;
				
		switch(z){
			case 1:
			if(a<1&&a>l1.siz()){
					cout<<"Invalid index"<<endl;
					continue;
				}
				cout<<"Enter marks for subject: ";
	            cin>>marks;
	            cout<<"Enter subject name: ";
	            cin.ignore();
	            getline(cin,cname);
	            cout<<"Enter credit hours: ";
	            cin>>cred_hrs;
	            cout<<"Enter course code: ";
	            cin>>ccode;
				gpa=l1.calc_gpa(marks);
	            grade_points=l1.calc_GP(gpa,cred_hrs);
				l1.insert(a,marks,cred_hrs,cname,ccode,gpa,grade_points);
				break;
				l1.showlist();
			case 2:
				if(a<1&&a>l2.siz()){
					cout<<"Invalid index"<<endl;
					continue;
				}
				cout<<"Enter marks for subject: ";
	            cin>>marks;
	            cout<<"Enter subject name: ";
	            cin.ignore();
	            getline(cin,cname);
	            cout<<"Enter credit hours: ";
	            cin>>cred_hrs;
	            cout<<"Enter course code: ";
	            cin>>ccode;
				gpa=l2.calc_gpa(marks);
	            grade_points=l2.calc_GP(gpa,cred_hrs);
				l2.insert(a,marks,cred_hrs,cname,ccode,gpa,grade_points);
				l2.showlist();
				break;
			case 3: 
			if(a<1&&a>l3.siz()){
					cout<<"Invalid index"<<endl;
					continue;
				}
				cout<<"Enter marks for subject: ";
	            cin>>marks;
	            cout<<"Enter subject name: ";
	            cin.ignore();
	            getline(cin,cname);
	            cout<<"Enter credit hours: ";
	            cin>>cred_hrs;
	            cout<<"Enter course code: ";
	            cin>>ccode;
			    gpa=l3.calc_gpa(marks);
	            grade_points=l3.calc_GP(gpa,cred_hrs);
			    l3.insert(a,marks,cred_hrs,cname,ccode,gpa,grade_points);
			    l3.showlist();
			    break;
			default:
				cout<<"Invalid semester."<<endl;
		}
		
		}
		else if(x==2){
			cout<<"in which semester you want to update: ";
		cin>>z;
		cout<<"At which index you want to update: ";
				cin>>a;
				
	            

		switch(z){
			case 1:
				if(a<1&&a>l1.siz()){
					cout<<"Invalid index"<<endl;
					continue;
				}
				cout<<"Enter marks for subject: ";
	            cin>>marks;
	            cout<<"Enter subject name: ";
	            cin.ignore();
	            getline(cin,cname);
	            cout<<"Enter credit hours: ";
	            cin>>cred_hrs;
	            cout<<"Enter course code: ";
	            cin>>ccode;
				gpa=l1.calc_gpa(marks);
	            grade_points=l1.calc_GP(gpa,cred_hrs);
				l1.update(a,marks,cred_hrs,cname,ccode,gpa,grade_points);
				l1.showlist();
				break;
			case 2:
				if(a<1&&a>l2.siz()){
					cout<<"Invalid index"<<endl;
					continue;
				}
				cout<<"Enter marks for subject: ";
	            cin>>marks;
	            cout<<"Enter subject name: ";
	            cin.ignore();
	            getline(cin,cname);
	            cout<<"Enter credit hours: ";
	            cin>>cred_hrs;
	            cout<<"Enter course code: ";
	            cin>>ccode;
				gpa=l2.calc_gpa(marks);
	            grade_points=l2.calc_GP(gpa,cred_hrs);
				l2.update(a,marks,cred_hrs,cname,ccode,gpa,grade_points);
				l2.showlist();
				break;
			case 3: 
			if(a<1&&a>l3.siz()){
					cout<<"Invalid index"<<endl;
					continue;
				}
				cout<<"Enter marks for subject: ";
	            cin>>marks;
	            cout<<"Enter subject name: ";
	            cin.ignore();
	            getline(cin,cname);
	            cout<<"Enter credit hours: ";
	            cin>>cred_hrs;
	            cout<<"Enter course code: ";
	            cin>>ccode;
			    gpa=l3.calc_gpa(marks);
	            grade_points=l3.calc_GP(gpa,cred_hrs);
			    l3.update(a,marks,cred_hrs,cname,ccode,gpa,grade_points);
			    l3.showlist();
			    break;
			default:
				cout<<"Invalid semester."<<endl;
		}
		}
		else if(x==3){
			cout<<"in which semester you want to delete: ";
		cin>>z;
		cout<<"At which index you want to delete: ";
				cin>>a;
				switch(z){
					case 1:
					if(a<1&&a>l1.siz()){
					cout<<"Invalid index"<<endl;
					continue;
				}
						l1.remove(a);
						l1.showlist();
					    break;
					case 2:
						if(a<1&&a>l2.siz()){
					cout<<"Invalid index"<<endl;
					continue;
				}
						l2.remove(a);
						l2.showlist();
						
					    break;
					case 3:
						if(a<1&&a>l3.siz()){
					cout<<"Invalid index"<<endl;
					continue;
				}
						l3.remove(a);
						l3.showlist();
					    break;
					default:
				cout<<"Invalid semester."<<endl;
				}
		}
		else if(x==4){
			cout<<"in which semester you want to find: ";
		cin>>z;
		cout<<"Enter marks you want to find: ";
				cin>>a;
				switch(z){
					case 1:
						l1.find(a);
					    break;
					case 2:
						l2.find(a);
					    break;
					case 3:
						l3.find(a);
					    break;
					default:
				cout<<"Invalid semester."<<endl;
				}
		}
		else if(x==5){
			cout<<"in which semester you want to get: ";
		cin>>z;
		cout<<"At which index you want to get: ";
				cin>>a;
				switch(z){
					case 1:
						if(a<1&&a>l1.siz()){
					cout<<"Invalid index"<<endl;
					continue;
				}
						l1.get(a);
					    break;
					case 2:
						if(a<1&&a>l2.siz()){
					cout<<"Invalid index"<<endl;
					continue;
				}
						l2.get(a);
					    break;
					case 3:
						if(a<1&&a>l3.siz()){
					cout<<"Invalid index"<<endl;
					continue;
				}
						l3.get(a);
					    break;
					default:
				cout<<"Invalid semester."<<endl;
				}
		}
		else if(x==0){
			break;
		}
}
	l1.notepad(l2,l3);
    cout<<"Enter any character for further program: ";
    cin>>hui;
	cout<<"CGPA program has been completed.\nNow we will work with linkeed list."<<endl;
    list1 l;
	int a,b;
	l.addnode1(5);
	l.addnode1(7);
	l.addnode1(8);
	l.showlist1();
	//size of linked list
	cout<<"Length of list is: "<<l.siz1()<<endl;
	//particular index value
	cout<<"Enter the index you want to get: ";
	sizeee:
	cin>>a;
	if(a>0 && a<=l.siz1()){
		l.get1(a);
	}
	else{
		cout<<"Invalid index. Enter again."<<endl;
		goto sizeee;	
	}
	//updation
	cout<<"Enter the index you want to update: ";
	sizeee2:
	cin>>a;
	if(a>0 && a<=l.siz1()){
		cout<<"Enter the updated value: ";
		cin>>b;
		l.update1(a,b);
	}
	else{
		cout<<"Invalid index. Enter again."<<endl;
		goto sizeee2;	
	}
	cout<<"List after updation:"<<endl;
	l.showlist1();
	//searching
	cout<<"Enter the value you want to find: ";
	cin>>b;
	l.find1(b);
}