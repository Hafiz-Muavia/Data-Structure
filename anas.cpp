#include <iostream>
#include <tuple>
#include <iomanip>
#include "age headerhui.h"
#include "cgpa123.h"
#include "time.h"
#include "listhui.h"
#include "loginh.h"

using namespace std;
int m=0;
class EXAM {
private:
    int bir_d, bir_m, bir_y;
    int c_day, c_mon, c_year;
    string name, roll_no,cname;
    int mpin,ccode;
    float temp;
   

public:
    EXAM() {
        tie(c_day, c_mon, c_year) = getTime();
    }

    void date();
    void login();
    void age_();
    void cgpa_();
    void list(int);
};

void EXAM::date() {
    cout << "PRESENT DATE ----- " << c_day << "/" << c_mon << "/" << c_year << endl;
}

void EXAM::login() {
    m++;
    retake:
    cout << "ENTER CLASS NAME : ";
    cin >> cname;
	cout << "ENTER CLASS CODE : ";
    cin >> ccode;	
    cout << "ENTER STUDENT NAME: ";
    getline(cin >> ws, name);

    cout << "ENTER STUDENT ROLL NO: ";
    getline(cin >> ws, roll_no);

    cout << "ENTER STUDENT MPIN: ";
    cin >> mpin;

    if ((ccode ==S_ccode[m]) &&(cname == S_cname[m]) &&(name == S_name[m]) && (roll_no == S_roll_no[m]) && (mpin == S_pin[m])) {
        cout << "-------------- DETAILS CONFIRMED OF Student: " << m << "--------------\n\n";
    } else {
        cout << "LOGIN Error! in Student: " << m << " data --------------\n\n" << endl;
        cout<<"\t\tPLEASE ! ENTER CORRECT DETAILS TO MOVE FORWARD ."<<endl;
        goto retake;
    }
}

void EXAM::age_() {
    cout << "ENTER BIRTH DAY: ";
    cin >> bir_d;
    cout << "ENTER BIRTH MONTH: ";
    cin >> bir_m;
    cout << "ENTER BIRTH YEAR: ";
    cin >> bir_y;

    setbirth_data(bir_d, bir_m, bir_y);
    setcur_data(c_day, c_mon, c_year);
    check_birthdata();
    check_curdata();
    display();
}

void EXAM::cgpa_() {

    for (int sem = 1; sem <= 3; sem++) {
        total_sub();
        subject_set();
        display_marks();
        cout << "\n\n---------------GPA OF " << sem << " SEMESTER = " << fixed << setprecision(2) << GPA() << endl;}
    
    show_CGPA();
}
void EXAM :: list(int s){
	
		float up_cgpa,st_cgpa;
		int S_num,s_num_cgpa;
		int st_num,rem_s_num;
		int ch_new,ch_del;
	set_student(s);
	for(int i=1;i<=s;i++)
	{
	temp=cgpa_arr[i];	
		add(temp);
		
		
	}
	
	
	
		cout<<"ENTER STUDENT NUM TO SEE HIS CGPA : ";
	cin>>S_num;
	getcgpa(S_num);
	
	
		cout<<"ENTER STUDENT NUM TO UPDATE HIS CGPA : ";
	cin>>s_num_cgpa;
     cout<<"ENTER UPDATED CGPA OF THAT STUDENT : ";
	cin>>up_cgpa;

	updatecgpa(s_num_cgpa,up_cgpa);
	
	cout<<"PRESS 1 TO ADD NEW STUDENT ";
	cin>>ch_new;
	if(ch_new==1){
	
		cout<<"ENTER STUDENT NUM YOU WANT TO ADD : ";
	cin>>st_num;

	cout<<"ENTER CGPA OF THAT STUDENT : ";
	cin>>st_cgpa;

	
	insertt(st_num,st_cgpa);
}
		cout<<"PRESS 1 TO REMOVE A STUDENT ";
	cin>>ch_del;
	
	if(ch_del==1){
	
	
		cout<<"ENTER STUDENT NUM YOU WANT TO REMOVE : ";
	cin>>rem_s_num;
	remove(rem_s_num);}
	
	cout<<"<<<<<<-------------------------------------------PRINTING FINAL DATA ------------------------------------------------------>>>>>>"<<endl;
		print();
}
int main() {
	int s;
    EXAM obj;
    obj.date();
    cout<<"ENTER NUM OF STUDENTS UNDER 5 : ";
    cin>>s;
if(s<=5){

    EXAM student[s];

    for (int i = 1; i <=s; i++) {
        cout << "---------------------------------------------------------------------STUDENT <" << i << ">--------------------------------------------------------------" << endl;
        student[i].login();
        student[i].age_();
        student[i].cgpa_();
       
    }
    
    obj.list(s);
}
else
{
	cout<<"TOTAL NO OF STUDENTS LIMIT IS 5 "<<endl;
	exit(1);
}
    
    
    

    return 0;
}