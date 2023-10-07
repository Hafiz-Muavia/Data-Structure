#include<iostream>
using namespace std;
class CGPA
{
private:
    char str[500];
    int marks[6];
    float gpa=0.0,gradepoints=0.0;

public:
    float tgpa;

    int index,value;
    int val;
    void input_Book_names();
    void Book_values();
    void gpa_1st_sem();
    void gpa_2nd_sem();
    void gpa_3rd_sem();
    void insertion();
    void deletion();
    void updation();
    void searching();
    void set_val(int ,int);
    void set(int);


};
void CGPA::set(int val)
{
    this->val=val;
}
void CGPA::set_val(int index,int value)
{
    this->index=index;
    this->value=value;
}
void CGPA::input_Book_names()
{
   cout<<"Enter the book name:";
   cin.ignore();
   cin.getline(str,500);
   cout<<"Enter the book name:";
   cin.ignore();
   cin.getline(str,500);
   cout<<"Enter the book name:";
   cin.ignore();
   cin.getline(str,500);
   cout<<"Enter the book name:";
   cin.ignore();
   cin.getline(str,500);
   cout<<"Enter the book name:";
   cin.ignore();
   cin.getline(str,500);

}
void CGPA::Book_values()
{
    cout<<"Enter the marks:"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>marks[i];
    }

}
void CGPA::gpa_1st_sem()
{
  for(int i=0;i<5;i++)
 {

 if(marks[i]>=85)
gpa=4.00;
else if(marks[i]>=75)
gpa=3.8;
else if(marks[i]>=65)
gpa=3.6;
else if(marks[i]>=55)
gpa=3.2;
else if(marks[i]>=50)
gpa=2.7;
else if(marks[i]>=45)
gpa=2.5;
else if(marks[i]>=40)
gpa=2.3;
else
gpa=1.00;
gradepoints+=gpa*3.0;
cout<<"The gpa is"<<gpa<<endl;
}
 tgpa=gradepoints/15.0;
 cout<<"The tgpa of 1st sem is:"<<tgpa<<endl;
}

void CGPA::gpa_2nd_sem()
{
     float gpa=0.0,gradepoints=0.0;
  for(int i=0;i<5;i++)
 {

 if(marks[i]>=85)
gpa=4.00;
else if(marks[i]>=75)
gpa=3.8;
else if(marks[i]>=65)
gpa=3.6;
else if(marks[i]>=55)
gpa=3.2;
else if(marks[i]>=50)
gpa=2.7;
else if(marks[i]>=45)
gpa=2.5;
else if(marks[i]>=40)
gpa=2.3;
else
gpa=1.00;
gradepoints+=gpa*3.0;
cout<<"The gpa is"<<gpa<<endl;
}
 tgpa=gradepoints/15.0;
 cout<<"The tgpa of 2nd sem is:"<<this->tgpa<<endl;
}

void CGPA::gpa_3rd_sem()
{
  float gpa=0.0,gradepoints=0.0;
for(int i=0;i<5;i++)
 {

 if(marks[i]>=85)
gpa=4.00;
else if(marks[i]>=75)
gpa=3.8;
else if(marks[i]>=65)
gpa=3.6;
else if(marks[i]>=55)
gpa=3.2;
else if(marks[i]>=50)
gpa=2.7;
else if(marks[i]>=45)
gpa=2.5;
else if(marks[i]>=40)
gpa=2.3;
else
gpa=1.00;
gradepoints+=gpa*3.0;
cout<<"The gpa is"<<gpa<<endl;
}
 tgpa=gradepoints/15.0;
 cout<<"The tgpa of 3rd sem is:"<<tgpa<<endl;
}
CGPA  operator +(CGPA s,CGPA t)
{

    CGPA temp;
    temp.tgpa=s.tgpa+t.tgpa;
     return temp;
}
void CGPA::insertion()
{
    cout<<"Insertion marks:"<<endl;
    for(int i=6;i>index;i--)
    {
        marks[i]=marks[i-1];
    }
    marks[index]=value;
    cout<<"Display the marks:"<<endl;
    for(int i=0;i<6;i++)
    {
        cout<<marks[i]<<endl;
    }
}
void CGPA::deletion()
{
    int marks[5];
    cout<<"Enter the deletion marks"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>marks[i];
    }

    cout<<"Deletion marks:"<<endl;
    for(int i=index;i<5;i++)
    {
        marks[i-1]=marks[i];
    }
    cout<<"Display the marks:"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<marks[i]<<endl;
    }
}
void CGPA::updation()
{
    cout<<"Updation:"<<endl;
    for(int i=0;i<5;i++)
    {
        if(marks[i]==index)
        {
            marks[index]=value;
        }

    }
    cout<<"Display the updated array:"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<marks[i]<<endl;
    }
}
void CGPA::searching()
{
    cout<<"Searching:"<<endl;
  for(int i=0;i<5;i++)
  {
      if(marks[i]==val)
      {
          cout<<"Value found at array:"<<endl;
      }

  }


}



main()
{
    CGPA a,x,y,z,obj;
   cout<<"Enter the value of index:";
   cin>>obj.index;

   cout<<"Enter the value:";
   cin>>obj.value;

   cout<<"Enter the matching value:"<<endl;
   cin>>obj.val;

    x.input_Book_names();
    x.set_val(obj.index ,obj.value);
    x.set(obj.val);
    x.Book_values();
    x.gpa_1st_sem();
    x.insertion();
    x.deletion();
    x.updation();
    x.searching();



    y.input_Book_names();
    y.set_val(obj.index ,obj.value);
    x.set(obj.val);
    y.Book_values();
    y.gpa_2nd_sem();
    y.insertion();
    y.deletion();
    y.updation();
    y.searching();


    z.input_Book_names();
    z.set_val(obj.index ,obj.value);
    x.set(obj.val);
    z.Book_values();
    z.gpa_3rd_sem();
    z.insertion();
    z.deletion();
    z.updation();
    z.searching();


    a=x+y+z;
   cout<<"The sum of three semester cgpa is:"<<a.tgpa<<endl;


}
