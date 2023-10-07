#include<iostream>
#include<fstream>
using namespace std;

float *ptr;
int tot_student,  num_of_active_student, cur_student;


void set_student(int s){
if(s>0){
    tot_student=s+1;
    cur_student=0;
    num_of_active_student=0;
    ptr = new float[tot_student];

ptr[0]=0;
    for(int i=1;i<=tot_student;i++){
        ptr[i]=-1;

    }


}


}
void  add(float cgpa){


if(cur_student==tot_student)
    cout<<"List is Full"<<endl;
else

{
    ptr[++cur_student]=cgpa;
  num_of_active_student++;
}

}
void  start(){
    cur_student = 1;


}
void  next(){
if(cur_student==tot_student)
   {

    cout<<" THIS IS THE LAST STUDENT so Can't Move forward "<<endl;

	}
else if(cur_student>tot_student)
   {

    cout<<" TOTAL NO ACTIVE STUDENTS CANNOT BE GREATER THAN OVERALL TOTAL NO OF STUDENTS "<<endl;
    exit(1);
    }
else
    cur_student++;

}
void  backk(){
if(cur_student==1)
   {

   cout<<"THIS IS THE FIRST STUDENT so Can't move Backward "<<endl;
    }
else
    cur_student--;
}
void  tail(){
    cur_student =num_of_active_student ;
}
void  print(ofstream& file){

for(int i=1;i<tot_student;i++)
{
    file<<"\tCGPA OF STUDENT <"<<i<<"> : "<<ptr[i]<<endl;

}
for(int i=1;i<tot_student;i++)
{
    cout<<"\tCGPA OF STUDENT <"<<i<<"> : "<<ptr[i]<<endl;

}

}




void clearlist(){
    cur_student=0;
    num_of_active_student=0;

ptr[0]=0;
    for(int i=1;i<=tot_student;i++){
        ptr[i]=-1;


    }}
void findcgpa(float cgpa){
    int compare=0;
    for(int i = 1;i<=tot_student;i++){
        if(ptr[i]==cgpa){
            compare=1;
            cout<<"THATS THE CGPA OF  "<<i<<" STUDENT "<<endl;
            break;
        }

    }
    if(compare==0){
        cout<<"SORRY ! NOT A ONE STUDENT GOT THIS CGPA "<<endl;
    }
}

void getcgpa(int s_num){
if(s_num<1 || s_num>num_of_active_student){
        cout<<"THIS STUDENT HAS NOT GIVEN EXAMS ---SO THERE IS NO CGPA RECORD OF HIM ."<<endl;
    }
    else{

    cout<<"CGPA= "<<ptr[s_num]<<endl;
    }

}

void updatecgpa(int s_num,float cgpa){

if((s_num>1 || s_num<=num_of_active_student)&&(cgpa>0 && cgpa<=4))
    ptr[s_num]=cgpa;
else
cout<<"ERROR IN CGPA OR STUDENT NUMBER"<<endl;

}
void insertt(int s_num,float cgpa){
if(s_num<1 || s_num>num_of_active_student+1){
        cout<<"NO STUDENT CAN BE ADDED AS LIST IS FULL "<<endl;
    }
    else{
    	if(cgpa>0 && cgpa<=4){

        for (int i = num_of_active_student+1 ; i >=s_num; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        num_of_active_student++;
        ptr[s_num]=cgpa;
        tot_student++;
}
else
cout<<"ERROR IN CGPA ! "<<endl;

    }}
void remove(int s_num){
    if(s_num<1 || s_num>num_of_active_student+1){
        cout<<"ERROR ! CANNOT REMOVE THIS STUDENT "<<endl;
    }
    else{
        for (int i = s_num; i <=num_of_active_student+1; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        num_of_active_student--;
        tot_student--;


    }
}


