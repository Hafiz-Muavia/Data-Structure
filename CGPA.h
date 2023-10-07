#include <iostream>//preprocessor directive
#include <fstream>
#include <iomanip>//for manipulators
using namespace std;//standard library
class result{//class definition
	private://access specifier
	    //private Declarations of data members
	    
		int marks[11];
		string names[11];
		string ccode[11];
		int subject_no;
		float gpa[11];
		float grade_points[11];
		float credit_hours[11];
		int TotalCreditHours;
		int TotalGradePoints;
		float total_gpa;
	public://access specifier
	    //public declaration for member functions
		result();
		void in(int);
		void out(int);
		void gpa1();
		void GradePoints();
		void GPA();
		result operator +(result);
		void operator /(int);
		void operatorr(result,result,result,int,string,int,string);
		void insert();
		void deleted();
		void update();
};//class ends
//Definitions of member functions
result::result(){//constructor
    //initializations to zero
    this->ccode[0]='\0';
	this->marks[0]=0;
	this->names[0]='\0';
	this->subject_no=0;
	this->gpa[0]=0;
	this->grade_points[0]=0;
	this->credit_hours[0]=0;
}
void result::in(int sem_no){//for input
	Subjects:
		
	cout<<"How many subjects are in semester "<<sem_no<<": ";
	cin>>this->subject_no;
	if(this->subject_no<1||this->subject_no>7){//condition for subject numbers(can't exceed 6)
		cout<<"Invalid. Try again."<<endl;
		goto Subjects;//goto statement
	}
	
	cout<<"Enter marks for semester: "<<sem_no<<endl;
	for(int i=1;i<=this->subject_no;i++){
		//Names of subjects
		cout<<"subject_name["<<i<<"]: ";
		cin.ignore();
		getline(cin,this->names[i]);
		Marks:
			//Marks
		cout<<"marks["<<i<<"]: ";
		cin>>this->marks[i];	
		if(this->marks[i]<0||this->marks[i]>100){//condition for marks
			cout<<"Invalid Marks. Enter again: "<<endl;
			goto Marks;//goto statement
		}
		CH:
			//credit hours
		cout<<"credit_hours["<<i<<"]: ";
		cin>>this->credit_hours[i];
		if(this->credit_hours[i]<0){//condition for credit hours
			cout<<"Invalid Input. Enter again: "<<endl;
			goto CH;//goto statement
		}
		cout<<"course code["<<i<<"]: ";
		cin>>this->ccode[i];
	}
}
void result::out(int sem_no){//for output
	cout<<"Marks for semester "<<sem_no<<" are: "<<endl;
	cout<<"Subjects"<<setw(20-8)<<setfill(' ')<<"Marks"<<setw(20)<<setfill(' ')<<"Credit Hours"<<setw(20)<<setfill(' ')<<"Course Code"<<endl;
	for(int i=1;i<=this->subject_no;i++){
		cout<<this->names[i]<<setw(20-(names[i].size()))<<setfill(' ')<<this->marks[i]<<setw(20-2)<<setfill(' ')<<this->credit_hours[i]<<setw(19)<<setfill(' ')<<this->ccode[i]<<endl;
	}
	cout<<"GPA for Semester "<<sem_no<<" is: "<<this->total_gpa<<endl;
}
void result::gpa1(){//for gpa of individual subjects
	for(int i=1;i<=this->subject_no;i++){
		if(this->marks[i]>=85&&this->marks[i]<=100)
		    this->gpa[i]=4.0;
		else if(this->marks[i]>=80&&this->marks[i]<85)
		    this->gpa[i]=3.7;
		else if(this->marks[i]>=75&&this->marks[i]<80)
		    this->gpa[i]=3.3;
		else if(this->marks[i]>=70&&this->marks[i]<75)
		    this->gpa[i]=3.0;
		else if(this->marks[i]>=65&&this->marks[i]<70)
		    this->gpa[i]=2.7;
		else if(this->marks[i]>=61&&this->marks[i]<65)
		    this->gpa[i]=2.3;
		else if(this->marks[i]>=58&&this->marks[i]<61)
		    this->gpa[i]=2.0;
		else if(this->marks[i]>=55&&this->marks[i]<58)
		    this->gpa[i]=1.7;
		else if(this->marks[i]>=50&&this->marks[i]<55)
		    this->gpa[i]=1.0;
		else if(this->marks[i]>=0&&this->marks[i]<50)
		    this->gpa[i]=0.0;	
	}
}
void result::GradePoints(){//for grade points of individual subject as well as per semester
	this->TotalCreditHours=0;
	this->TotalGradePoints=0;
	for(int i=1;i<=this->subject_no;i++){
		this->grade_points[i]=this->gpa[i]*this->credit_hours[i];
		this->TotalGradePoints+=this->grade_points[i];
		this->TotalCreditHours+=this->credit_hours[i];
	}
}
void result::GPA(){//GPA per semester
	this->total_gpa=this->TotalGradePoints/float(this->TotalCreditHours);
}
result result::operator +(result t){//overloading + operator for adding gpa
	result temp;//temporary object
	temp.total_gpa=0;
	temp.total_gpa=this->total_gpa+t.total_gpa;
	return temp;
}
void result:: operator /(int t){//overloading / operator for dividing gpa
	result temp;
	temp.total_gpa=0;
    temp.total_gpa=this->total_gpa/3.0;
    cout<<"CGPA of 3 semesters are: "<<temp.total_gpa<<endl;;
}
void result::insert(){//for insertion
	int ins;
	Indexing1:
	cout<<"Enter the index at which you want to insert: ";
	cin>>ins;
	if(ins<1||ins>this->subject_no+1){//condition for index
		cout<<"Invalid input. Try again."<<endl;
		goto Indexing1;
	}
	this->subject_no++;
	int k=this->subject_no;
	int j=this->subject_no-ins;
	for(int i=1;i<=j;i++){//loop for insertion
		this->marks[k]=this->marks[k-1];
		this->names[k]=this->names[k-1];
		this->ccode[k]=this->ccode[k-1];
		this->credit_hours[k]=this->credit_hours[k-1];
		k--;
	}
	//Insertion process
	cout<<"subject_name["<<ins<<"]: ";
		cin>>this->names[ins];
		Marks1:
		cout<<"marks["<<ins<<"]: ";
		cin>>this->marks[ins];	
		if(this->marks[ins]<0||this->marks[ins]>100){
			cout<<"Invalid Marks. Enter again: "<<endl;
			goto Marks1;
		}
		CH1:
		cout<<"credit_hours["<<ins<<"]: ";
		cin>>this->credit_hours[ins];
		if(this->credit_hours[ins]<0){
			cout<<"Invalid Input. Enter again: "<<endl;
			goto CH1;
		}
		cout<<"Cource_Code["<<ins<<"]: ";
		cin>>this->ccode[ins];
}
void result::deleted(){//for deletion
	int del;
	Deletion1:
	cout<<"Enter index you want to delete: ";
	cin>>del;
	if(del<1||del>this->subject_no){//condition for index
		cout<<"Invalid input. Try again."<<endl;
		goto Deletion1;
	}
	int k=del;
	int j=this->subject_no-del;
	this->subject_no--;
	for(int i=1;i<=j;i++){//loop for deletion
		this->marks[k]=this->marks[k+1];
		this->names[k]=this->names[k+1];
		this->ccode[k]=this->ccode[k+1];
		this->credit_hours[k]=this->credit_hours[k+1];
		k++;
	}
}
void result::update(){//for updation
	int upd;
	Updation1:
		cout<<"Enter index you want to update: ";
	cin>>upd;
	if(upd<1||upd>this->subject_no){//condition for index
		cout<<"Invalid input. Try again."<<endl;
		goto Updation1;
	}
	//updation process
	cout<<"subject_name["<<upd<<"]: ";
		cin>>this->names[upd];
		Marks2:
		cout<<"marks["<<upd<<"]: ";
		cin>>this->marks[upd];	
		if(this->marks[upd]<0||this->marks[upd]>100){
			cout<<"Invalid Marks. Enter again: "<<endl;
			goto Marks2;
		}
		CH2:
		cout<<"credit_hours["<<upd<<"]: ";
		cin>>credit_hours[upd];
		if(credit_hours[upd]<0){
			cout<<"Invalid Input. Enter again: "<<endl;
			goto CH2;
		}
		cout<<"Cource_Code["<<upd<<"]: ";
		cin>>this->ccode[upd];
}

void result:: operatorr(result Mavi1,result Mavi2, result Mavi3,int t,string nm,int age,string id){//overloading / operator for dividing gpa
    ofstream file("Student.txt");
    file<<"Name: "<<nm<<endl;
    file<<"Roll no: "<<id<<endl;
    file<<"Age: "<<age<<endl;
    file<<"Marks for semester "<<1<<" are: "<<endl;
	file<<"Subjects"<<setw(20-8)<<setfill(' ')<<"Marks"<<setw(20)<<setfill(' ')<<"Credit Hours"<<setw(20)<<setfill(' ')<<"Course Code"<<endl;
	for(int i=1;i<=Mavi1.subject_no;i++){
		file<<Mavi1.names[i]<<setw(20-(Mavi1.names[i].size()))<<setfill(' ')<<Mavi1.marks[i]<<setw(20-2)<<setfill(' ')<<Mavi1.credit_hours[i]<<setw(19)<<setfill(' ')<<Mavi1.ccode[i]<<endl;
	}
	file<<"GPA for Semester "<<1<<" is: "<<Mavi1.total_gpa<<endl;
	file<<"Marks for semester "<<2<<" are: "<<endl;
	file<<"Subjects"<<setw(20-8)<<setfill(' ')<<"Marks"<<setw(20)<<setfill(' ')<<"Credit Hours"<<setw(20)<<setfill(' ')<<"Course Code"<<endl;
	for(int i=1;i<=Mavi2.subject_no;i++){
		file<<Mavi2.names[i]<<setw(20-(Mavi2.names[i].size()))<<setfill(' ')<<Mavi2.marks[i]<<setw(20-2)<<setfill(' ')<<Mavi2.credit_hours[i]<<setw(19)<<setfill(' ')<<Mavi2.ccode[i]<<endl;
	}
	file<<"GPA for Semester "<<2<<" is: "<<Mavi2.total_gpa<<endl;
	file<<"Marks for semester "<<3<<" are: "<<endl;
	file<<"Subjects"<<setw(20-8)<<setfill(' ')<<"Marks"<<setw(20)<<setfill(' ')<<"Credit Hours"<<setw(20)<<setfill(' ')<<"Course Code"<<endl;
	for(int i=1;i<=Mavi3.subject_no;i++){
		file<<Mavi3.names[i]<<setw(20-(Mavi3.names[i].size()))<<setfill(' ')<<Mavi3.marks[i]<<setw(20-2)<<setfill(' ')<<Mavi3.credit_hours[i]<<setw(19)<<setfill(' ')<<Mavi3.ccode[i]<<endl;
	}
	file<<"GPA for Semester "<<3<<" is: "<<Mavi3.total_gpa<<endl;
	result temp;
	temp.total_gpa=0;
    temp.total_gpa=(Mavi1.total_gpa+Mavi2.total_gpa+Mavi3.total_gpa)/3.0;
    file<<"CGPA of 3 semesters are: "<<temp.total_gpa<<endl;
}