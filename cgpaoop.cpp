#include <iostream>//preprocessor directive
using namespace std;//standard library
class cgpa{//class definition
	private://access specifier
	//data members
		int marks[5],cr_h[5],Total_CH=0;
		float gpa[5],Grade_point[5],Total_GP=0,CGPAA;
		char name[20];
	public://access specifier
	cgpa(){
		//Constructor
	}
	~cgpa(){
		//Destructor
	}
	//member functions
		void c_gpa(){//for input
				int x;
			cout<<"Enter name: ";
			cin.getline(name,20);
			cout<<"Enter No. of Semesters: ";
			cin>>x;
			float GPAA[x];
			for(int i=0;i<x;i++){//Loop for x number of semesters
				Total_GP=0;
				Total_CH=0;
				CGPAA=0;
				for(int j=0;j<5;j++){//loop for marks of 5 subjects
					cout<<"Enter marks for subject:"<<j+1<<" ";
					cin>>marks[j];
					cout<<"Enter credit hours for subject:"<<j+1<<" ";
					cin>>cr_h[j];
					//if else condition for gpa of particular subject
					if(marks[j]>=85&&marks[j]<=100)
					gpa[j]=4.0;
					else if(marks[j]>=80&&marks[j]<85)
					gpa[j]=3.7;
					else if(marks[j]>=75&&marks[j]<70)
					gpa[j]=3.3;
					else if(marks[j]>=70&&marks[j]<75)
					gpa[j]=3.0;
					else if(marks[j]>=65&&marks[j]<70)
					gpa[j]=2.7;
					else if(marks[j]>=61&&marks[j]<65)
					gpa[j]=2.3;
					else if(marks[j]>=58&&marks[j]<61)
					gpa[j]=2.0;
					else if(marks[j]>=55&&marks[j]<58)
					gpa[j]=1.7;
					else if(marks[j]>=50&&marks[j]<55)
					gpa[j]=1.0;
					else gpa[j]=0.0;
					Grade_point[j]=gpa[j]*cr_h[j];//grade points for individual subject
					Total_GP+=Grade_point[j];//Total grade points
					Total_CH+=cr_h[j];//Total credit hours
				
				}
				GPAA[i]=Total_GP/Total_CH;//Gpa per semester
				cout<<"GPA of semester "<<i+1<<" is: "<<GPAA[i]<<endl;
				//if else condition for cgpa
				if(i==0)
				CGPAA=GPAA[0];
				else if(i==1)
				CGPAA=(GPAA[0]+GPAA[1])/2.0;
				else if(i==2)
				CGPAA=(GPAA[0]+GPAA[1]+GPAA[2])/3.0;
				else if(i==3)
				CGPAA=(GPAA[0]+GPAA[1]+GPAA[2]+GPAA[3])/4.0;
				else if(i==4)
				CGPAA=(GPAA[0]+GPAA[1]+GPAA[2]+GPAA[3]+GPAA[4])/5.0;
				else if(i==5)
				CGPAA=(GPAA[0]+GPAA[1]+GPAA[2]+GPAA[3]+GPAA[4]+GPAA[5])/6.0;
				else if(i==6)
				CGPAA=(GPAA[0]+GPAA[1]+GPAA[2]+GPAA[3]+GPAA[4]+GPAA[5]+GPAA[6])/7.0;
				else if(i==7)
				CGPAA=(GPAA[0]+GPAA[1]+GPAA[2]+GPAA[3]+GPAA[4]+GPAA[5]+GPAA[6]+GPAA[7])/8.0;
				cout<<"CGPA of Semester "<<i+1<<" is: "<<CGPAA<<endl;
			}
			
		}
};
int main(){//function where execution starts
//object creations with their relative functions
	cgpa mv;
	mv.c_gpa();
	cgpa shb;
	shb.c_gpa();
	cgpa slmn;
	slmn.c_gpa();
	return 0;//control returns
}//destructor called