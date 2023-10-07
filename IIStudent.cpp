#include <iostream>
#include <cstdlib>
#include <fstream>
#include "IIdate.h"
#include "IIList.h"

using namespace std;

class Student{
	private:
	string id;
	string name ;
	public:
		void set(){
			cout << "Enter Student Id : ";
			cin>> id;
			cin.ignore();
			cout << "Enter Student name : ";
			cin.ignore();
			cin >> name;
			cin.ignore();
	}
	void get(){
		    cout << endl;
			cout << "Student Id is: " << id << endl;
			cout << "Student name is: " << name << endl;
	}
};
int main(){
	


	string name = "fajar";
	string password = "abc12" ;
	input:
    string username;
	string pas;
	cout << "Enter Username ";
	cin>> username;
	cin.ignore();
	cout << "Enter password ";
	cin >> pas;
	cin.ignore();

		if (username == name && pas == password){
		cout << "Login done" << endl;
		goto continuee;
		}
		else
		{
		cout << "Incorrect username or password" << endl;
		goto input;
		}

continuee:
	Student st1;
	st1.set();
	st1.get();
	DATE current, birth, agee;
    birth.setAge(27, 11, 2004);
    current.setAge(8, 6, 2023);
    cout << "----Date of birth--- " << endl;
    birth.showAge();
    cout << "---Your age is--- " << endl;
    agee = current - birth;
    agee.showAge();
    
    
    	float cgpa= 0.0;
	int s_no;
	cout << "How many semester's data you want to calculate?? ";
	cin >> s_no;
	for(int i=1; i<=s_no; i++){
	cout << "\t  SEMESTER " << i << " : " <<endl;
	
    int choice, num;
    linklist sem;

    while (true) {
        int marks;
        string courseCode, courseName;

        cout << "Enter marks for the course: ";
        cin >> marks;

        cout << "Enter course code: ";
        cin >> courseCode;

        cout << "Enter course name: ";
        cin.ignore(); // Ignore the newline character left in the input buffer
        getline(cin, courseName);

        sem.addnode(marks, courseCode, courseName);

        cout << "Do you want to add another course? (1 for yes, 0 for no): ";
        cin >> choice;

        if (choice == 0) {
            break;
        }
    }

    
    repeat:
		cout << "Choose the function you want to run: ";
		cout <<"(Enter 1 for updating value, 2 for finding value, 3 for getting a value, 4 for removing a value, 0 to exit) : ";
		cin>> num;
		if(num==0){
			goto calculation;
		}
		else{
		
		switch(num){
		
			case 1:
				int p,v;
				cout <<"Position to update:";
				cin>>p;
				cout <<"Value to update : ";
				cin>>v;
				sem.update(p,v);
				break;
			case 2:
				int m;
				cout <<"Enter marks you want to find: ";
				cin>>m;
				sem.find(m);
				break;
			case 3:
				int g;
				cout <<"Enter position from which you want to get value: ";
				cin>>g;
				sem.get(g);
				break;
			case 4:
				int r;
				cout <<"Enter position from which you want to remove value: ";
				cin>>r;
				sem.remove(r);
				break;
		}
	goto repeat;
}
calculation:
    // Display the GPA for semester 1
    float semesterGPA = sem.gpa_cal();
    cout << "Semester" <<i <<" GPA: " << semesterGPA << endl;

      cgpa += semesterGPA;
}

 cout << "Total CGPA is : " <<cgpa/s_no;
    return 0;
}
    
