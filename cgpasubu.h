#include<iostream>
#include<string>
using namespace std;
class Data	//Data named class
{ 
	private:	
		int marks[7];
		int i,j;
		int pos;
		int siz=7; 
		string name[7];
		string c_code[7];
		int number_of_subjects;
		float gpa;
	public:
		void setvalues(int number_of_subjects);
		void get();
		void update(int,int);
		void insert(int,int);
		void remove(int);
		float calc_gpa();
		void showgpa();
};
//function defining outside the class to set values
void Data::setvalues (int number_of_subjects)
{
	this-> number_of_subjects = number_of_subjects;
	if(number_of_subjects>7)
	{
		
		cout<<"Number of subjects exceeds the limit..ERROR!!!";
		exit(1);
	}
	else
	for(i=1;i<=number_of_subjects;i++)
	{
	cout<<"Course Name:  ";
	getline(cin>>ws,name[i]);
	cout<<"Course Code:  ";
	getline(cin>>ws,c_code[i]);
	cout<<"Marks of "<<name[i]<<":  ";
	cin>>marks[i];
	}
}
//function defining outside the class to display values 
void Data::get()
{
	cout<<"Marks of each subject. "<<endl;
	for( int i=1;i<=number_of_subjects;i++)
	{
		cout<<"Course "<<c_code[i]<<" : "<<name[i]<<" : "<<marks[i]<<endl;
	}
}
//function defining outside the class to insert value at particular position
void Data::insert(int pos, int marks) 
{
		if (pos >= 1 && pos <= number_of_subjects + 1) 
		{
		// Shift elements to make space for the new value
		for (int i = number_of_subjects; i >= pos; i--) 
		{
			this->marks[i + 1] = this->marks[i];
		}
		// Insert the new values at the specified position
		this->marks[pos] = marks;
		number_of_subjects++; // Increment the total number of subjects
		cout << "Values inserted at position " << pos << endl;
		}
		else 
		{
			cout << "Invalid position!" << endl;
		}
}
//function defining outside the class to remove the value at particular position
void Data::remove(int pos)
{
	if (pos >= 1 && pos <= number_of_subjects)
	{
		for (int i = pos; i < number_of_subjects; i++)
		{
			marks[i] = marks[i + 1];
		}
		number_of_subjects--; // Decrement the total number of subjects
		cout << "Value removed from position " << pos << endl;
	}
	else 
	{
		cout << "Invalid position!" << endl;
	}
}
void Data::update(int pos, int x)
{
	if (pos >= 1 && pos <= number_of_subjects) {
		marks[pos] = x;
		cout << "Value updated at position " << pos << endl;
	}
	else 
	{
		cout << "Invalid position!" << endl;
	}
}
float Data::calc_gpa()
{
    float grade_point;
    float sum = 0.0;
    float ch= 0.0;
    for (int i = 1; i < number_of_subjects; i++)
    {
        if (marks[i] >= 85)
        {
            ch = 4;
        }
        else if (marks[i] >= 80)
        {
            ch = 3.7;
        }
        else if (marks[i] >= 75)
        {
            ch = 3.30;
        }
        else if (marks[i] >= 70)
        {
            ch = 3.00;
        }
        else if (marks[i] >= 65)
        {
            ch = 2.70;
        }
        else if (marks[i] >= 60)
        {
            ch = 2.30;
        }
        else if (marks[i] >= 55)
        {
            ch = 1.70;
        }
        else if (marks[i] >= 50)
        {
            ch = 1.00;
        }
        else if (marks[i] < 50)
        {
            ch = 0.0;
        }
        sum=sum+ch*3.0;
    }
    gpa =sum/18.0;
	return gpa;
}
void Data::showgpa()
{
    cout << gpa << endl;
}