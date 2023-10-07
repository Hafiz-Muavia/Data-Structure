#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
int j=0;
int a=0;

    float cgpa=0;
    int total_credit_hours ;
    float total_grade_point ;
    float  grade_point ;
    float gpa;
    int n;
    int *marks;
    int *cr_hour;
    string subjects[11]={"\0","MATHS","OOP","DB","PF","ISL","SST","ASSEMBLY","ECONOMY","PP","TARJMA"};

float cgpa_arr[6];



void total_sub(){
	
	j++;
    cout<<"\n\n----------------------ENTER SEMESTER  <" <<j<< "> DATA --------------------"<<endl;
    do{
        cout<<"\nENTER TOTAL NUMBER OF SUBJECTS: ";
        cin>>n;

        if(n>=11)
        {
            cout<<"ERROR! TOTAL NUMBER OF SUBJECTS LIMIT IS 10 "<<endl;
            cout<<"------PLEASE ENTER NUMBER OF SUBJECTS UNDER LIMIT --------"<<endl;
        }
        else
        {
            break;
        }
    }
    while(n>=11);
}

void subject_set(){
	
    marks= new int[n];
    cr_hour= new int[n];
	
	marks[0]=0;
    cr_hour[0]=0;
    
    
    	for(int i=1;i<=n;i++){
		
        cout<<"   ENTER "<<subjects[i]<<" Marks: ";
        cin>>marks[i];
        if(marks[i]<0 || marks[i]>100)
        {
            cout<<"ERROR! OBTAINED MARKS CANNOT BE NEGATIVE OR GREATER THAN 100 "<<endl;
            exit(1);
        }

        cout<<"   ENTER "<<subjects[i]<<" CREDIT HOURS: ";
        cin>>cr_hour[i];
        if(cr_hour[i]<0 || cr_hour[i]>4)
        {
            cout<<"ERROR! PER SUBJECT CREDIT HOUR CANNOT BE NEGATIVE OR GREATER THAN 4 "<<endl;
            exit(1);
        }
    }
}

void calc_gradepoints()
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

float GPA()
{
	gpa=0;
    calc_gradepoints();
    gpa = total_grade_point / total_credit_hours;
   cgpa+=gpa;
    
 

     
    return gpa;
    
   
}



void show_CGPA(){
	
	a++;
    cout<<"\n\t <<<<<-----CGPA OF 3 Semesters : "<<fixed<<setprecision(2)<<cgpa/3<<"---->>>>>\n"<<endl;
   
   cgpa_arr[a]=cgpa/3;
    cgpa=0;
    j=0;
   
    
    delete[] marks;
    delete[] cr_hour;
}



void display_marks(){
    cout<<"-----------------SUBJECT MARKS--------------------"<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<") SUBJECT: "<<subjects[i]<<" Marks: "<<marks[i]<<"------------CREDIT HOUR: "<<cr_hour[i]<<endl;
    }
}









