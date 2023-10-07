#include<iostream>
#include "HUI.h"
#include<string.h>
#include<iomanip>
int j=0;
int k=0;
using namespace std;
class RESULT
{
		string name;
	string roll_no;
	int age,mpin;
	
float cgpa=0;
int total_credit_hours ;
 float total_grade_point ;
 float  grade_point ;	
 float gpa;
int n;
int *marks;
int *cr_hour;

 string subjects[11]={"\0","DATABASE","OOP","PF","MATHS","ISLAMIAT","S.ST","ENGLISH","ASSEMBLY","ECONOMY","PHYSICS"};
public:
void check_s_data();
	void total_sub();
void subject_set();
void insert();
void del();
void update();
void search();
void display_marks();
void calc_gradepoints();
float GPA();
void show_CGPA();
 RESULT operator +(RESULT obj);
};
void RESULT::check_s_data(){
	k=0;
	j++;
	cout<<"ENTER STUDENT NAME : ";
	getline(cin>>ws,name);
	
	cout<<"ENTER STUDENT ROLL NO : ";
	getline(cin>>ws,roll_no);
	
	cout<<"ENTER STUDENT AGE : ";
	cin>>age;
	
	cout<<"ENTER STUDENT MPIN : ";
	cin>>mpin;
	
	if((name==S_name[j])&&(roll_no==S_roll_no[j])&&(age==S_age[j])&&(mpin==S_pin[j]))
		cout<<"--------------LOGIN CONFIRMED OF Student : "<<j<<"--------------\n\n";
	else
	{
	cout<<"LOGIN Error ! in Student : "<<j<<" data --------------\n\n"<<endl;
	exit(1);}
	
	
	
	
	
}

void RESULT :: total_sub(){
	k++;
cout<<"\n\n----------------------ENTER SEMESTER <"<<k<<"> DATA --------------------"<<endl;
	do{
		cout<<"\nENTER TOTAL NO SUBJECT : ";
		cin>>n;
		
		if(n>=11)
		{
		cout<<"ERROR ! TOTAL NO OF SUBJECTS LIMIT IS 10 "<<endl;
cout<<"------PLEASE ENTER NO OF SUBJECTS UNDER LIMIT --------"<<endl;
	}
	else
	{	
break;
}
}
	while(n>=11);

	
}




void RESULT::subject_set(){

marks= new int[n+1];
cr_hour= new int[n+1];

    marks[0]=0;
     cr_hour[0]=0;
    cout<<"-------------ENTERING SUBJECTS MARKS & CREDIT HOURS-----------"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<") ENTER  "<<subjects[i]<<" marks : ";
        cin>>marks[i];
        if(marks[i]<0 || marks[i]>100)
       {
		 cout<<"ERROR ! OBTAINED MARKS CANNOT BE NEGATIVE OR INCREASE BY 100 "<<endl;
        exit(1);}
        
         cout<<i<<") ENTER  "<<subjects[i]<<" CREDIT HOURS : ";
        cin>>cr_hour[i];
        if(cr_hour[i]<0 || cr_hour[i]>4)
       {
		 cout<<"ERROR ! PER SUBJECT CREDIT HOUR CANNOT BE NEGATIVE OR INCREASE BY 4 "<<endl;
        exit(1);}
        

    }
        

    

    

    }
	
	

void RESULT::calc_gradepoints()
{
    total_credit_hours = 0;
    total_grade_point = 0;

    for (int i = 1; i <=n; i++)
    {

        total_credit_hours += cr_hour[i];

        if (marks[i] >= 85)
        {
            grade_point = 4.00 * cr_hour[i];
            total_grade_point += grade_point;
        }
        else if (marks[i] >= 80)
        {
            grade_point = 3.70 * cr_hour[i];
            total_grade_point += grade_point;
        }
        else if (marks[i] >= 75)
        {
            grade_point = 3.30 * cr_hour[i];
            total_grade_point += grade_point;
        }
        else if (marks[i] >= 70)
        {
            grade_point = 3.00 * cr_hour[i];
            total_grade_point += grade_point;
        }
        else if (marks[i] >= 65)
        {
            grade_point = 2.70 * cr_hour[i];
            total_grade_point += grade_point;
        }
        else if (marks[i] >= 60)
        {
            grade_point = 2.30 * cr_hour[i];
            total_grade_point += grade_point;
        }

        else if (marks[i] >= 55)
        {
            grade_point = 1.70 * cr_hour[i];
            total_grade_point += grade_point;
        }

        else if (marks[i] >= 50)
        {
            grade_point = 1.00 * cr_hour[i];
            total_grade_point += grade_point;
        }
        else if (marks[i] < 50)
        {
            grade_point = 0.0 * cr_hour[i];
            total_grade_point += grade_point;
        }
    }
}

float RESULT::GPA()
{
	calc_gradepoints();
    gpa = total_grade_point / total_credit_hours;
   
    
    return gpa;
}

RESULT RESULT::operator +(RESULT obj){

	RESULT temp;
		temp.cgpa=0;
	temp.total_credit_hours=this-> total_credit_hours + obj.total_credit_hours;
	temp.total_grade_point= this-> total_grade_point + obj.total_grade_point;
	 temp.cgpa= temp.total_grade_point/	temp.total_credit_hours;
	
	return temp;
}

void RESULT :: show_CGPA(){

cout<<"<<<<<<<<-------------------CGPA OF 3 SEMESTERS : "<<fixed<<setprecision(2)<<cgpa<<"----------------->>>>>>>>>"<<endl;
}













     void RESULT:: insert(){
int num;
    int no_of_subj,val;
    cout<<"---------------------SUBJECTS INCREASING--------------------------"<<endl;
cout<<"Enter no of subjects u want to increase : ";
cin>>no_of_subj;
num=n;
n+=no_of_subj;

if(n<=10){

for(int i=1;i<=no_of_subj;i++)
{
    cout<<i+num<<") ENTER  "<<subjects[i+num]<<" marks : ";
        cin>>marks[i+num];
         if(marks[i+num]<0 || marks[i+num]>100)
       {
		 cout<<"ERROR ! OBTAINED MARKS CANNOT BE NEGATIVE OR INCREASE BY 100 "<<endl;
        exit(1);}
        
         cout<<i+num<<") ENTER  "<<subjects[i+num]<<" CREDIT HOURS : ";
        cin>>cr_hour[i+num];
        if(cr_hour[i+num]<0 || cr_hour[i+num]>4)
       {
		 cout<<"ERROR ! PER SUBJECT CREDIT HOUR CANNOT BE NEGATIVE OR INCREASE BY 4 "<<endl;
        exit(1);}

}}

    else
    {cout<<"ERROR ! NO OF TOTAL SUBJECTS LIMIT IS 10 "<<endl;
    exit(1);

}

}

void RESULT:: del(){
int d_sub,sub_no;
cout<<"--------------------DELETING SUBJECTS----------------------------"<<endl;
cout<<"Enter total no of subjects you want to delete : ";
cin>>d_sub;
if(d_sub<=n){

while(d_sub){
cout<<"Enter subject num you want to delete : ";
cin>>sub_no;
sub_no++;

if(sub_no<=n+1){

for(int i=sub_no; i<=n;i++)
{
	
	
	
    marks[i-1]=marks[i];
cr_hour[i-1]=cr_hour[i];
subjects[i-1]=subjects[i];
}
n--;
cout<<"YOUR 1 SUBJECT IS REDUCED , SO ENTER SUBJECT NUM ACCORDING TO UPDATION SUCH AS (YOUR "<<sub_no-1<<" SUBJECT HAS BECOME "<<sub_no-2<<") AND UNDER LIMIT ,LIMIT = "<<n<<endl;



}


else
    {cout<<"ERROR! WRONG SUBJECT NUMBER "<<endl;
    exit(1);
  }
d_sub--;
}}
else
    {cout<<"ERROR IN TOTAL SUBJECT NUMBERS "<<endl;
    exit(1);
  }

}

void RESULT:: update()
{
int up_marks,up_sub,t_sub;
int up_credit,c_up_sub,c_sub;
cout<<"--------------------UPDATION----------------------------"<<endl;

 cout<<"Enter total no of subject whose marks you want to update : ";
cin>>t_sub;
if( t_sub<=n){
while(t_sub){
    cout<<"Enter subject no whose marks you want to update : ";
cin>>up_sub;

if(up_sub>0&& up_sub<=n){
    cout<<"ENTER Marks: ";
cin>>up_marks;
  if(up_marks<0 || up_marks>100)
       {
		 cout<<"ERROR ! OBTAINED MARKS CANNOT BE NEGATIVE OR INCREASE BY 100 "<<endl;
        exit(1);}
        else{
		marks[up_sub]=up_marks;
}

}
else
   { cout<<"ERROR! WRONG SUBJECT NUM"<<endl;
   exit(1);
  }
t_sub--;}

}
else
   { cout<<"ERROR IN NO OF SUBJECTS "<<endl;
   exit(1);
  }


cout<<"Enter total no of subject whose credit hours you want to update : ";
cin>>c_sub;
if( c_sub<=n){
while(c_sub){
    cout<<"Enter subject no whose credit hour you want to update : ";
cin>>c_up_sub;

if(c_up_sub>0&& c_up_sub<=n){
    cout<<"ENTER CREDIT HOUR : ";
cin>>up_credit;
  if(up_credit<0 || up_credit>4)
       {
		 cout<<"ERROR ! CREDIT HOUR PER SUBJECT CANNOT BE NEGATIVE OR INCREASE BY 4 "<<endl;
        exit(1);}
        else{
		cr_hour[c_up_sub]=up_credit;
}

}
else
   { cout<<"ERROR! WRONG SUBJECT NUM"<<endl;
   exit(1);
  }
c_sub--;}

}
else
   { cout<<"ERROR IN NO OF SUBJECTS "<<endl;
   exit(1);
  }

}


void RESULT::search(){

int subj_no,t_sub;
cout<<"--------------------SEARCHING----------------------------"<<endl;
cout<<"Enter total no of subjects whose marks you want to check : ";
cin>>t_sub;
if(t_sub<=n){

while(t_sub){

    cout<<"Enter SUBJECT NUM TO CHECK ITS MARKS : ";
cin>>subj_no;
if(subj_no>0 && subj_no<=n)
{
    
cout<<"Subject : "<<subjects[subj_no]<<"MARKS : "<<marks[subj_no]<<endl;}

else
{
cout<<"ERROR ! WRONG SUBJECT NUMBER "<<endl;
exit(1);
}
t_sub--;
}}
else 
{
cout<<"ERROR in TOTAL SUBJECT NUMBERS "<<endl;
exit(1);}

}

void RESULT :: display_marks(){
	
	cout<<"-----------------SUBJECT MARKS--------------------"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<") SUBJECT : "<<this->subjects[i]<<" Marks : "<<this->marks[i]<<"------------CREDIT HOUR : "<<this->cr_hour[i]<<endl;

    }
	 
}

   










int main(){
	int n=3,num,choose,change,sem_num,st;
	
	cout<<"------------------------------------1ST STUDENT DATA-------------------------------"<<endl;
	
RESULT s1_sem[4],CGPA, s2_sem[4];
s1_sem[1].check_s_data();
	for(int i=1;i<=n;i++)
{

	
s1_sem[i].total_sub();
s1_sem[i].subject_set();
cout<<"--------------GPA OF "<<i<<" SEMESTER = "<<fixed<<setprecision(2)<<s1_sem[i].GPA()<<endl;


}
CGPA= s1_sem[1]+s1_sem[2]+s1_sem[3];
CGPA.show_CGPA();


cout<<"------------------------------------2ND STUDENT DATA-------------------------------"<<endl;
s2_sem[1].check_s_data();
	for(int i=1;i<=n;i++)
{

	
s2_sem[i].total_sub();
s2_sem[i].subject_set();
cout<<"-----------------GPA OF "<<i<<" SEMESTER = "<<fixed<<setprecision(2)<<s2_sem[i].GPA()<<endl;


}
CGPA= s2_sem[1]+s2_sem[2]+s2_sem[3];
CGPA.show_CGPA();



cout<<"IF U WANT ANY CHANGINGS IN YOUR SEMESTER'S DATA-----KINDLY PRESS 1 \nIF NOT THEN PRESS 0 : ";
cin>>choose;
if(choose==1){

while(choose!=0){
	cout<<"WHICH STUDENT DATA U WANNA CHANGE : ";
	cin>>st;
	
	if(st==1){
	
cout<<"IN HOW MANY SEMESTERS YOU WANT CHANGINGS : ";
cin>>change;
if(change<=n)
{
	for(int i=1;i<=change;i++){
		cout<<"ENTER SEMESTER NUMBER IN WHICH U WANT CHANGING : ";
		cin>>sem_num;
		if (sem_num<=n){
		
		
	

s1_sem[sem_num].insert();
s1_sem[sem_num].del();
s1_sem[sem_num].update();
s1_sem[sem_num].display_marks();
s1_sem[sem_num].search();
}
else
{
cout<<"ERROR IN SEMESTER NUM "<<endl;
exit(1);}
} }
else
{
cout<<"ERROR IN TOTAL NO OF SEMESTERS"<<endl;
exit(1);}

cout<<"IF U WANT ANY CHANGINGS IN YOUR SEMESTER'S DATA-----KINDLY PRESS 1 \nIF NOT THEN PRESS 0 :  ";
cin>>choose;

cout<<"--------------------------------------------AFTER CHANGINGS, CURRENT CGPA of 1st Student----------------------------------"<<endl;

CGPA= s1_sem[1]+s1_sem[2]+s1_sem[3];
CGPA.show_CGPA();
}

else if(st==2){
	
cout<<"IN HOW MANY SEMESTERS YOU WANT CHANGINGS : ";
cin>>change;
if(change<=n)
{
	for(int i=1;i<=change;i++){
		cout<<"ENTER SEMESTER NUMBER IN WHICH U WANT CHANGING : ";
		cin>>sem_num;
		if (sem_num<=n){
		
		
	

s2_sem[sem_num].insert();
s2_sem[sem_num].del();
s2_sem[sem_num].update();
s2_sem[sem_num].display_marks();
s2_sem[sem_num].search();
}
else
{
cout<<"ERROR IN SEMESTER NUM "<<endl;
exit(1);}
} }
else
{
cout<<"ERROR IN TOTAL NO OF SEMESTERS"<<endl;
exit(1);}

cout<<"IF U WANT ANY CHANGINGS IN YOUR SEMESTER'S DATA-----KINDLY PRESS 1 \nIF NOT THEN PRESS 0 :  ";
cin>>choose;

cout<<"--------------------------------------------AFTER CHANGINGS, CURRENT CGPA of 2nd Student----------------------------------"<<endl;

CGPA= s2_sem[1]+s2_sem[2]+s2_sem[3];
CGPA.show_CGPA();

}
else  {

cout<<"ERROR IN NO OF STUDENTS ! "<<endl;
exit(1);}








}












}
else
{
cout<<"YOU HAVE PRESSED O or ANY OTHER DIGIT , SO GOODBYE "<<endl;
exit(1);}









return 0;}

