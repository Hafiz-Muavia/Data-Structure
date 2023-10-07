#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
int j=0;

    float cgpa=0;
    int total_credit_hours ;
    float total_grade_point ;
    float  grade_point ;
    float gpa;
    int n;
    int marks[11];
    int cr_hour[11];
    string subjects[11]={"\0","MATHS","OOP","DB","PF","ISL","SST","ASSEMBLY","ECONOMY","PP","TARJMA"};





total_sub(){
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

subject_set(){
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

calc_gradepoints()
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



show_CGPA(){
    cout<<"\n\t <<<<<-----CGPA OF 3 SEMESTERS: "<<fixed<<setprecision(2)<<cgpa/3<<"---->>>>>\n"<<endl;
    cgpa=0;
    j=0;
}



display_marks(){
    cout<<"-----------------SUBJECT MARKS--------------------"<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<") SUBJECT: "<<subjects[i]<<" Marks: "<<marks[i]<<"------------CREDIT HOUR: "<<cr_hour[i]<<endl;
    }
}









