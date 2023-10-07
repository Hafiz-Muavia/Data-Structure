#include <iostream>
#include <fstream>
#include <cstdlib>
#include "LogIN.h"
#include "DOB.h"
#include "CGPA.h"
#include "LIST.h"
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
	result Mavi[4];//object creation, memory allocation and constructor calls
	for(int i=1;i<4;i++){//loop for input 3 semesters
		Mavi[i].in(i);
	}
	for(int i=1;i<4;i++){
		//Calling member functions
		Mavi[i].gpa1();
		Mavi[i].GradePoints();
		Mavi[i].GPA();
	}
	for(int i=1;i<4;i++){//loop for individual output per semester
		Mavi[i].out(i);
	}
	Mavi[0]=Mavi[1]+Mavi[2]+Mavi[3];// overloading to add 3 gpa
	Mavi[0]/3;//overloading to divide addition by 3
		int y;
	Insertion://insertion process
	cout<<"Enter the semester in which you want to insert. Input 0 for no insertion.";
	cin>>y;
	switch(y){//for semesters
		case 0:
			cout<<"No insertion."<<endl;
			break;
		case 1:
			Mavi[1].insert();
			Mavi[1].gpa1();
		    Mavi[1].GradePoints();
		    Mavi[1].GPA();
			break;
		case 2:
			Mavi[2].insert();
			Mavi[2].gpa1();
		    Mavi[2].GradePoints();
		    Mavi[2].GPA();
			break;
		case 3:
			Mavi[3].insert();
			Mavi[3].gpa1();
		    Mavi[3].GradePoints();
		    Mavi[3].GPA();
			break;
		default:
			cout<<"Invalid Input. Try again."<<endl;
			goto Insertion;
			break;
	}
	if(y!=0){//if any insertion occurs
		cout<<"If you want more insertion, Type 1.";//more insertion
	    cin>>y;
	    if(y==1){
		    goto Insertion;
	    }
	    cout<<"Output after Insertion"<<endl;
	    for(int i=1;i<4;i++){
		Mavi[i].out(i);
	    }
	    Mavi[0]=Mavi[1]+Mavi[2]+Mavi[3];
	    Mavi[0]/3;
	}
	Deletion://deletion process
	cout<<"Enter the semester in which you want to delete subject. Input 0 for no deletion.";
	cin>>y;
	switch(y){//for semesters
		case 0:
			cout<<"No deletion."<<endl;
			break;
		case 1:
			Mavi[1].deleted();
			Mavi[1].gpa1();
		    Mavi[1].GradePoints();
		    Mavi[1].GPA();
			break;
		case 2:
			Mavi[2].deleted();
			Mavi[2].gpa1();
		    Mavi[2].GradePoints();
		    Mavi[2].GPA();
			break;
		case 3:
			Mavi[3].deleted();
			Mavi[3].gpa1();
		    Mavi[3].GradePoints();
		    Mavi[3].GPA();
			break;
		default:
			cout<<"Invalid Input. Try again."<<endl;
			goto Deletion;
			break;
	}
	if(y!=0){//if any deletion occurs
		cout<<"If you want more deletion, Type 1.";
	    cin>>y;
	    if(y==1){
		    goto Deletion;
	    }
	    cout<<"Output after Deletion"<<endl;
	    for(int i=1;i<4;i++){
		Mavi[i].out(i);
	    }
	    Mavi[0]=Mavi[1]+Mavi[2]+Mavi[3];
	    Mavi[0]/3;
	}
	Updation://updation process
	cout<<"Enter the semester in which you want to update subject. Input 0 for no updation.";
	cin>>y;
	switch(y){//for semesters
		case 0:
			cout<<"No updation."<<endl;
			break;
		case 1:
			Mavi[1].update();
			Mavi[1].gpa1();
		    Mavi[1].GradePoints();
		    Mavi[1].GPA();
			break;
		case 2:
			Mavi[2].update();
			Mavi[2].gpa1();
		    Mavi[2].GradePoints();
		    Mavi[2].GPA();
			break;
		case 3:
			Mavi[3].update();
			Mavi[3].gpa1();
		    Mavi[3].GradePoints();
		    Mavi[3].GPA();
			break;
		default:
			cout<<"Invalid Input. Try again."<<endl;
			goto Updation;
			break;
	}
	if(y!=0){//if any updation occurs
		cout<<"If you want more updation, Type 1.";
	    cin>>y;
	    if(y==1){
		    goto Updation;
	    }
	    cout<<"Output after Updation"<<endl;
	    for(int i=1;i<4;i++){
		Mavi[i].out(i);
	    }
	    Mavi[0]=Mavi[1]+Mavi[2]+Mavi[3];
	    Mavi[0]/3;
}
	system("start notepad.exe Student.txt");
	ofstream file("Student.txt");
    if(file.is_open()){
    	string nm,idd;
    	int ageee;
    	nm=s1.getname();
    	ageee=age.getyear();
    	idd=s1.outID();
	    Mavi[0].operatorr(Mavi[1],Mavi[2],Mavi[3],3,nm,ageee,idd);
	}
	file.close();
    cout<<"Enter any character for further program: ";
    cin>>hui;
	cout<<"CGPA program has been completed.\nNow we will work with dynamic array aka list."<<endl;
    int d;
	list l1(3);
	l1.print();
	l1.add(55);
	l1.start();
	l1.back();
	l1.add(20);
	l1.add(20);
	l1.next();
	l1.add(45);
	l1.next();
	l1.add(40);
	l1.next();
	l1.next();
	l1.add(69);
	cout<<"Enter any character for further program: ";
    cin>>hui;
	l1.print();
	list l2(1);
	l2.copylist(l1);
	cout<<"Enter any character for further program: ";
    cin>>hui;
	cout<<"List l2:-"<<endl;
	l2.print();
	cout<<"Enter any character for further program: ";
    cin>>hui;
	list l3(l1);
	cout<<"List l3:-"<<endl;
	l3.print();
	cout<<"Enter any character for further program: ";
    cin>>hui;
	cout<<"Length of l1 is: "<<l1.len()<<endl;
	JKL:
	cout<<"Enter position you want to get: ";
	int v;
	cin>>v;
	if(v<1||v>l1.len()){
		cout<<"Invalid. "<<endl;
		goto JKL;
	}
	l1.pos(v);
	cout<<"Enter value you want to search: ";
	cin>>v;
	l1.search(v);
	KKK:
	cout<<"Enter index at which you want to insert: ";
	cin>>v;
	if(v<1||v>l1.len()){
		cout<<"Invalid. "<<endl;
		goto KKK;
	}
	cout<<"Enter value you want to insert: ";
	cin>>d;
	l1.insertL(v,d);
	cout<<"After inserting"<<endl;
	l1.print();
    Jk:
	cout<<"Enter the index you want to delete: ";
	cin>>v;
	if(v<1||v>l1.len()){
		cout<<"Invalid. "<<endl;
		goto Jk;
	}
	l1.del(v);
	cout<<"After deleting"<<endl;
	l1.print();
	JL:
	cout<<"At which index you want to update: ";
	cin>>v;
	if(v<1||v>l1.len()){
		cout<<"Invalid. "<<endl;
		goto JL;
	}
	cout<<"Enter updated value: ";
	cin>>d;
	l1.updateL(v,d);
	cout<<"After updating"<<endl;
	l1.print();
	l1.clear();
	cout<<"After clearing"<<endl;
	l1.print();	
	return 0;
}